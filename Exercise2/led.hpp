/**
 * @file led.hpp
 * @author Alessio Guarini
 * @version 1.0
 * @date 2025-06-09
 * @brief Abstraction for controlling a digital LED using Arduino.
 *
 * @details
 *   Provides an object-oriented wrapper for digital output control on Arduino
 *   boards. Functionality includes basic on/off control, state toggling, and
 *   autonomous blinking driven by a user-configurable period expressed in
 *   milliseconds. Internally, time is tracked in microseconds to allow for
 *   fine-grained timing precision (e.g., exact 1ms blinking).
 *   The implementation is intentionally minimal to ease
 *   comprehension for high-school students while remaining fully compliant
 *   with MISRA C:2012 guidelines for safety-critical embedded software.
 *
 *   Author contact: aguarini@unisa.it
 *   Affiliation   : PhD Student – Connected Autonomous Vehicles, MIVIA Lab.
 */

#ifndef LED_HPP
#define LED_HPP

#include <Arduino.h>

/**
 * @class Led
 * @brief High-level driver for a single digital LED.
 */
class Led
{
public:
    /**
     * @brief Constructs a Led instance bound to a given pin.
     * @param pin 8-bit Arduino pin number connected (directly or via resistor)
     *            to the LED anode.
     */
    explicit Led(uint8_t pin);

    /**
     * @brief Forces the LED into the ON state (logic HIGH).
     */
    void on(void);

    /**
     * @brief Forces the LED into the OFF state (logic LOW).
     */
    void off(void);

    /**
     * @brief Inverts the current output state of the LED.
     */
    void toggle(void);

    /**
     * @brief Performs time-driven blinking according to @ref blinking_period_us_.
     *
     * @details Call this method periodically (e.g. once per loop cycle).
     *          When the elapsed time since the last toggle exceeds the
     *          programmed period, the LED state is inverted automatically.
     */
    void blink(void);

    /**
     * @brief Updates the autonomous blinking period.
     * @param period_ms Desired total blink period, expressed in milliseconds.
     *
     * @note Internally stored as half-period in microseconds.
     */
    void set_blinking_period(uint32_t period_ms);

private:
    uint8_t  pin_;               /**< Arduino digital pin number              */
    bool     state_;             /**< Current LED state: false = OFF, true = ON */
    uint32_t blinking_period_us_;/**< Half-blink period in microseconds      */
    uint32_t last_toggle_time_;  /**< Timestamp of the last toggle (µs)       */
};

#endif /* LED_HPP */