/*
 * File: environ-logger.cpp
 */

#include "environ-logger.h"
#include "hd44780.h"
#include "humidity-sensor.h"
#include "temperature-sensor.h"
#include "xbee.h"

namespace
{
constexpr uint8_t SYSTICK_PERIOD(10);
}

ENVIRONMENT_LOGGER::ENVIRONMENT_LOGGER() :
   my_tick(0),
   my_humidity_sensor(HUMIDITY_SENSOR()),
   my_temp_sensor(TEMPERATURE_SENSOR()),
   my_serial_connection(XBEE()),
   my_lcd(HD44780())
{
    // Default constructor
}

ENVIRONMENT_LOGGER::~ENVIRONMENT_LOGGER()
{
    // Default destructor
}

ENVIRONMENT_LOGGER::EXIT_CODE ENVIRONMENT_LOGGER::runApplication()
{
    my_tick++;

    if (SYSTICK_PERIOD == my_tick)
    {
        bool error(true);
        uint8_t bytes_written_to_serial(0);
        bool lcd_update_success(false);

        uint8_t humidity = my_humidity_sensor->getHumidity();
        uint8_t temperature_celsius = my_temp_sensor->getTemperature(TEMPERATURE_SENSOR::DEGREES::CELSIUS);

        uint8_t temperature_msg("Temperature (C): " + itoa(temperature_celsius));
        uint8_t humidity_msg("Humidity: " + itoa(humidity) + "%");
        lcd_update_success = my_lcd->updateScreen(&temperature_msg);

        bytes_written_to_serial += my_serial_connection->write(SERIAL_MESSAGE::TEMPERATURE);
        bytes_written_to_serial += my_serial_connection->write(temperature_celsius);
        bytes_written_to_serial += my_serial_connection->write(SERIAL_MESSAGE::HUMIDITY);
        bytes_written_to_serial += my_serial_connection->write(humidity);

        if (4 == bytes_written_to_serial && lcd_update_success)
        {
            return EXIT_CODE::EXIT_WITH_SUCCESSFUL_RUN;
        }
        else
        {
            return EXIT_CODE::EXIT_FAILURE;
        }
    }
    else
    {
        return EXIT_CODE::EXIT_WITHOUT_RUN;
    }
}