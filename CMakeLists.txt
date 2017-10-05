cmake_minimum_required(VERSION 3.0.0)

project(environ-logger CXX)

set(CMAKE_CXX_COMPILER /usr/local/avr/bin/avr-g++)
message($ENV{AVR_PATH}/bin/avr-g++)
#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=gnu++17 -Wall -Wextra -fno-exceptions")

add_definitions(-D__AVR_ATmega328P__)

include_directories(
        $ENV{AVR_PATH}/avr/include
        #${PROJECT_SOURCE_DIR}/applications
        #${PROJECT_SOURCE_DIR}/outputs
        ${PROJECT_SOURCE_DIR}/peripherals
        ${PROJECT_SOURCE_DIR}/sensors)
set(HEADER_FILES
        ${PROJECT_SOURCE_DIR}/main.cpp
        #${PROJECT_SOURCE_DIR}/applications/environ-logger.h
        ${PROJECT_SOURCE_DIR}/peripherals/gpio.h)
set(SOURCE_FILES
        #${PROJECT_SOURCE_DIR}/applications/environ-logger.cpp
        ${PROJECT_SOURCE_DIR}/peripherals/gpio.cpp)

#add_subdirectory(applications)
#add_subdirectory(outputs)
#add_subdirectory(peripherals)
#add_subdirectory(sensors)

add_executable(environ-logger.hex ${SOURCE_FILES} ${HEADER_FILES})
