/*
 * File: gpio.cpp
 */

#include <avr/io.h>
#include "gpio.h"

namespace {
static constexpr auto writeOperation[GPIO_HANDLER::GPIO_PIN::NUMBER_OF_PINS] = {
   [](bool val) {
      val ? PORTB |= (1 << PB0) : PORTB &= ~(1 << PB0);
      return true;
   },
   []() {
      PORTB |= (1 << PB1);
      return true;
   },
   []() {
      PORTB |= (1 << PB2);
      return true;
   },
   []() {
      PORTB |= (1 << PB3);
      return true;
   },
   []() { return false; },
   []() { return false; },
   []() { return false; },
   []() { return false; },
   []() { return false; },
   []() { return false; },
   []() { return false; },
   []() { return false; },
   []() { return false; },
   []() { return false; },
   []() { return false; },
   []() { return false; },
   []() { return false; },
   []() { return false; },
   []() { return false; },
   []() { return false; },
   []() { return false; },
   []() { return false; },
   []() { return false; }
};

static constexpr auto readOperation[GPIO_HANDLER::GPIO_PIN::NUMBER_OF_PINS] = {
   []() {
      return (PORTB & (1 << PB0));
   },
   []() {
      return (PORTB & (1 << PB1));
   },
};

static constexpr auto setDirectionOperation[GPIO_HANDLER::GPIO_PIN::NUMBER_OF_PINS] = {
   [](bool direction) {
      (direction ? DDRB |= (1 << PB0) : DDRB &= ~(1 << PB0));
   },
   [](bool direction) {
      (direction ? DDRB |= (1 << PB1) : DDRB &= ~(1 << PB1));
   },
   [](bool direction) {
      (direction ? DDRB |= (1 << PB2) : DDRB &= ~(1 << PB2));
   },
   [](bool direction) {
      (direction ? DDRB |= (1 << PB3) : DDRB &= ~(1 << PB3));
   },
   [](bool direction) {
      (direction ? DDRB |= (1 << PB4) : DDRB &= ~(1 << PB4));
   },
   [](bool direction) {
      (direction ? DDRB |= (1 << PB5) : DDRB &= ~(1 << PB5));
   },
   [](bool direction) {
      (direction ? DDRB |= (1 << PB6) : DDRB &= ~(1 << PB6));
   },
   [](bool direction) {
      (direction ? DDRB |= (1 << PB7) : DDRB &= ~(1 << PB7));
   },
   [](bool direction) {
      (direction ? DDRC |= (1 << PC0) : DDRC &= ~(1 << PC0));
   },
   [](bool direction) {
      (direction ? DDRC |= (1 << PC1) : DDRC &= ~(1 << PC1));
   },
   [](bool direction) {
      (direction ? DDRC |= (1 << PC2) : DDRC &= ~(1 << PC2));
   },
   [](bool direction) {
      (direction ? DDRC |= (1 << PC3) : DDRC &= ~(1 << PC3));
   },
   [](bool direction) {
      (direction ? DDRC |= (1 << PC4) : DDRC &= ~(1 << PC4));
   },
   [](bool direction) {
      (direction ? DDRC |= (1 << PC5) : DDRC &= ~(1 << PC5));
   },
   [](bool direction) {
      (direction ? DDRC |= (1 << PC6) : DDRC &= ~(1 << PC6));
   },
   [](bool direction) {
      (direction ? DDRD |= (1 << PD0) : DDRD &= ~(1 << PD0));
   },
   [](bool direction) {
      (direction ? DDRD |= (1 << PD1) : DDRD &= ~(1 << PD1));
   },
   [](bool direction) {
      (direction ? DDRD |= (1 << PD2) : DDRD &= ~(1 << PD2));
   },
   [](bool direction) {
      (direction ? DDRD |= (1 << PD3) : DDRD &= ~(1 << PD3));
   },
   [](bool direction) {
      (direction ? DDRD |= (1 << PD4) : DDRD &= ~(1 << PD4));
   },
   [](bool direction) {
      (direction ? DDRD |= (1 << PD5) : DDRD &= ~(1 << PD5));
   },
   [](bool direction) {
      (direction ? DDRD |= (1 << PD6) : DDRD &= ~(1 << PD6));
   },
   [](bool direction) {
      (direction ? DDRD |= (1 << PD7) : DDRD &= ~(1 << PD7));
   },
};
}

GPIO_HANDLER::GPIO_HANDLER(GPIO_PIN * pins, uint8_t numberOfPins) : my_pins(pins), my_total_pins(numberOfPins)
{
   // initialization code
}

bool GPIO_HANDLER::writePin(GPIO_PIN pin, PIN_STATE value)
{
   auto writeSuccess(false);

   writeSuccess = writeOperation[static_cast<uint8_t>(pin)](static_cast<bool>(value));

   return writeSuccess;
}


GPIO_HANDLER::PIN_STATE GPIO_HANDLER::readPin(GPIO_PIN pin)
{
   return static_cast<PIN_STATE>(readOperation[static_cast<uint8_t>(pin)]());
}


bool GPIO_HANDLER::setPinDirection(GPIO_PIN pin, DIRECTION direction)
{
   setDirectionOperation[static_cast<uint8_t>(pin)](static_cast<bool>(direction));
   return true;
}