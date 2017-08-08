/*
 * File: main.cpp
 *
 * Hosts the initialization of the hardware on the microcontroller and set up
 * for the system tick.
 */

#include "adc.h"
#include "button-engine.h"
#include "environ-logger.h"
#include "gpio.h"
#include "timer.h"
#include "uart.h"

void main(void)
{
    // initialize
    // gpio
    startGPIOHandler();
    // uart
    startUART();
    // adc
    initializeADC();
    // timer
    startTimer();

    ENVIRONMENT_LOGGER * myLogger = &ENVIRONMENT_LOGGER();

    while (1)
    {
        // loop forever
        myLogger->runApplication();
        waitForSystick();
    }
}