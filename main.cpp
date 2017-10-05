/*
 * File: main.cpp
 *
 * Hosts the initialization of the hardware on the microcontroller and set up
 * for the system tick.
 */

#include <stdint.h>
#include "gpio.h"

const uint8_t numberOfPins = 2;
GPIO_HANDLER::GPIO_PIN myPins[numberOfPins] = {GPIO_HANDLER::GPIO_PIN::PIN_B0, GPIO_HANDLER::GPIO_PIN::PIN_B1};
GPIO_HANDLER my_gpio_handler(myPins, numberOfPins);

void main()
{
   my_gpio_handler.setPinDirection(GPIO_HANDLER::GPIO_PIN::PIN_B0, GPIO_HANDLER::DIRECTION::INPUT);
   my_gpio_handler.setPinDirection(GPIO_HANDLER::GPIO_PIN::PIN_B1, GPIO_HANDLER::DIRECTION::OUTPUT);

   while (true)
   {
      // check the button state
      GPIO_HANDLER::PIN_STATE state(my_gpio_handler.readPin(GPIO_HANDLER::GPIO_PIN::PIN_B0));
      // reflect the button state in the LED state
      my_gpio_handler.writePin(GPIO_HANDLER::GPIO_PIN::PIN_B1, state);
   }
}