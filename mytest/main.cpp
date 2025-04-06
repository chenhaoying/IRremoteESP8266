#include <iostream>
#include <assert.h>
#include <unistd.h>
#include "IRrecv.h"
#include "IRremoteESP8266.h"
#include "IRac.h"
#include "IRtext.h"
#include "IRutils.h"

const uint16_t kRecvPin = 14;
const uint16_t kCaptureBufferSize = 1024;
const uint8_t kTimeout = 50;
const uint16_t kMinUnknownSize = 12;
const uint8_t kTolerancePercentage = kTolerance; // kTolerance is normally 25%
#include <vector>

std::vector<uint16_t> rawData = {
    4458, 4325, 588, 1551, 588, 507, 587, 1552, 587, 1551, 587, 509, 586, 508, 586, 1551, 588, 510, 586, 507, 588, 1549, 588, 507, 587, 509, 587, 1549, 589, 1550, 588, 508, 587, 1551, 586, 509, 586, 509, 587, 507, 587, 1551, 588, 1549, 588, 1551, 588, 1550, 588, 1551, 587, 1550, 588, 1550, 589, 1549, 588, 508, 587, 508, 587, 508, 587, 509, 587, 507, 587, 508, 588, 1548, 590, 1549, 588, 1551, 588, 507, 587, 1550, 588, 508, 589, 508, 587, 1548, 590, 507, 588, 508, 587, 507, 587, 1549, 589, 508, 588, 1549, 588, 1550, 589, 5166, 4486, 4310, 588, 1550, 589, 508, 588, 1550, 588, 1550, 589, 508, 588, 507, 588, 1549, 589, 507, 588, 506, 587, 1551, 588, 507, 587, 508, 589, 1548, 589, 1549, 590, 508, 588, 1549, 588, 507, 588, 506, 589, 506, 588, 1550, 589, 1549, 589, 1550, 589, 1548, 588, 1550, 589, 1550, 589, 1548, 590, 1549, 589, 507, 589, 506, 589, 506, 589, 506, 590, 506, 589, 507, 588, 1548, 590, 1550, 590, 1549, 589, 506, 588, 1549, 589, 506, 589, 507, 588, 1550, 589, 506, 589, 507, 588, 507, 587, 1549, 589, 507, 588, 1548, 590, 1550, 590
};

int main()
{
    // Use turn on the save buffer feature for more complete capture coverage.
    IRrecv irrecv(kRecvPin, kCaptureBufferSize, kTimeout, true);
    decode_results results; // Somewhere to store the results
    irrecv.setUnknownThreshold(kMinUnknownSize);
    irrecv.setTolerance(kTolerancePercentage); // Override the default tolerance.
    volatile irparams_t *params_ptr = irrecv._getParamsPtr();
    memcpy(params_ptr->rawbuf, rawData.data(), sizeof(rawData));
    params_ptr->rawlen = rawData.size();
    irrecv.decode(&results);
    std::cout << "Decoded: " + resultToHumanReadableBasic(&results) << std::endl;
    // Display any extra A/C info if we have it.
    String description = IRAcUtils::resultAcToString(&results);
    if (description.length())
        std::cout << D_STR_MESGDESC ": " + description << std::endl;
    return 0;
}
