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

int main()
{
    // Use turn on the save buffer feature for more complete capture coverage.
    IRrecv irrecv(kRecvPin, kCaptureBufferSize, kTimeout, true);
    decode_results results; // Somewhere to store the results
    irrecv.setUnknownThreshold(kMinUnknownSize);
    irrecv.setTolerance(kTolerancePercentage); // Override the default tolerance.
    while (1)
    {
        irrecv.decode(&results);
        sleep(1); // Sleep for 1 second
    }
    return 0;
}
