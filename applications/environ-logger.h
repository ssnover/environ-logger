/*
 * File: environ-logger.h
 *
 * Definition for the environment logger class. This class performs sampling of
 * a humidity and temperature sensor via the ADC and outputting those values
 * to the LCD screen and a UART connection to an XBee radio.
 */

class ENVIRONMENT_LOGGER
{
private:

    uint8_t my_tick;
    SERIAL_INTF * my_serial_connection;
    TEMPERATURE_SENSOR_INTF * my_temp_sensor;
    HUMIDITY_SENSOR_INTF * my_humidity_sensor;
    LCD_SCREEN * my_lcd;

public:

    enum class EXIT_CODE {
        EXIT_WITHOUT_RUN,
        EXIT_WITH_SUCCESSFUL_RUN,
        EXIT_FAILURE
    };
    /*
     * Constructor.
     *
     * Creates an instance of the ENVIRONMENT_LOGGER class and initializes it.
     */
    ENVIRONMENT_LOGGER() = default;

    /*
     * Destructor.
     *
     * Deallocates an instance of the ENVIRONMENT_LOGGER class.
     */
    ~ENVIRONMENT_LOGGER() = default;

    /*
     * Runs the application to check if it is time for the application to
     * update values on it's outputs.
     */
    void runApplication();
};