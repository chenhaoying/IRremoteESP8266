cmake_minimum_required(VERSION 3.0)

# Define the project name
project(irremoteesp8266)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all .cpp files in the current directory
set(SOURCES
    IRac.cpp
    IRrecv.cpp
    IRsend.cpp
    IRtext.cpp
    IRtimer.cpp
    IRutils.cpp
    ir_Airton.cpp
    ir_Airwell.cpp
    ir_Aiwa.cpp
    ir_Amcor.cpp
    ir_Argo.cpp
    ir_Arris.cpp
    ir_BluestarHeavy.cpp
    ir_Bosch.cpp
    ir_Bose.cpp
    ir_Carrier.cpp
    ir_ClimaButler.cpp
    ir_Coolix.cpp
    ir_Corona.cpp
    ir_Daikin.cpp
    ir_Delonghi.cpp
    ir_Denon.cpp
    ir_Dish.cpp
    ir_Doshisha.cpp
    ir_Ecoclim.cpp
    ir_Electra.cpp
    ir_EliteScreens.cpp
    ir_Epson.cpp
    ir_Fujitsu.cpp
    ir_GICable.cpp
    ir_GlobalCache.cpp
    ir_Goodweather.cpp
    ir_Gorenje.cpp
    ir_Gree.cpp
    ir_Haier.cpp
    ir_Hitachi.cpp
    ir_Inax.cpp
    ir_JVC.cpp
    ir_Kelon.cpp
    ir_Kelvinator.cpp
    ir_Lasertag.cpp
    ir_Lego.cpp
    ir_LG.cpp
    ir_Lutron.cpp
    ir_Magiquest.cpp
    ir_Metz.cpp
    ir_Midea.cpp
    ir_MilesTag2.cpp
    ir_Mirage.cpp
    ir_Mitsubishi.cpp
    ir_MitsubishiHeavy.cpp
    ir_Multibrackets.cpp
    ir_MWM.cpp
    ir_NEC.cpp
    ir_Neoclima.cpp
    ir_Nikai.cpp
    ir_Panasonic.cpp
    ir_Pioneer.cpp
    ir_Pronto.cpp
    ir_RC5_RC6.cpp
    ir_RCMM.cpp
    ir_Rhoss.cpp
    ir_Samsung.cpp
    ir_Sanyo.cpp
    ir_Sharp.cpp
    ir_Sherwood.cpp
    ir_Sony.cpp
    ir_Symphony.cpp
    ir_Tcl.cpp
    ir_Technibel.cpp
    ir_Teco.cpp
    ir_Teknopoint.cpp
    ir_Toshiba.cpp
    ir_Toto.cpp
    ir_Transcold.cpp
    ir_Trotec.cpp
    ir_Truma.cpp
    ir_Vestel.cpp
    ir_Voltas.cpp
    ir_Whirlpool.cpp
    ir_Whynter.cpp
    ir_Wowwee.cpp
    ir_Xmp.cpp
    ir_York.cpp
    ir_Zepeal.cpp
)

# Add the static library target
add_library(${PROJECT_NAME} STATIC ${SOURCES})
