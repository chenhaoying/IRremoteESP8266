cmake_minimum_required(VERSION 3.0)

# Set the project name
project(mytest)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the global include directory to the current script path
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

# Add a global macro definition for UNIT_TEST
add_definitions(-DUNIT_TEST)

# Add the static library
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../src ${CMAKE_BINARY_DIR}/src)

# Add the executable
add_executable(mytest
    main.cpp
)

# Link the static library to the executable
target_link_libraries(mytest PRIVATE irremoteesp8266)

