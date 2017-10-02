/*
 * File: gpio.h
 *
 * This file defines an interface to the gpio periperhal of the Atmega AVR.
 */

class GPIO_HANDLER
{
private:

   GPIO_PIN * my_pins;
   uint8_t my_total_pins;

public:

   /*
   * This enum contains the GPIO pins available on the Atmega328 microcontroller.
   */
   enum class GPIO_PIN
   {
      PIN_B0 = 0u,
      PIN_B1,
      PIN_B2,
      PIN_B3,
      PIN_B4,
      PIN_B5,
      PIN_B6,
      PIN_B7,
      PIN_C0,
      PIN_C1,
      PIN_C2,
      PIN_C3,
      PIN_C4,
      PIN_C5,
      PIN_C6,
      PIN_D0,
      PIN_D1,
      PIN_D2,
      PIN_D3,
      PIN_D4,
      PIN_D5,
      PIN_D6,
      PIN_D7,
      NUMBER_OF_PINS = 23u,
   };

   enum class DIRECTION
   {
      INPUT = 0u,
      OUTPUT = 1u,
   };

   GPIO_HANDLER(GPIO_PIN * pins, uint8_t numberOfPins);

   ~GPIO_HANDLER() = default;

   bool writePin(GPIO_PIN pin, bool value);

   bool readPin(GPIO_PIN pin);

   bool setPinDirection(GPIO_PIN pin, DIRECTION direction);
};