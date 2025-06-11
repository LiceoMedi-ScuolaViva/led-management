/**
 * @file led.cpp
 * @author Alessio Guarini
 * @version 1.0
 * @date 2025-06-09
 * @brief Implementation of the Led class for controlling a digital LED on Arduino.
 *
 * @details
 *   This file contains the implementation of a high-level abstraction for
 *   controlling a digital output LED using Arduino. The class supports basic
 *   on/off/toggle operations as well as autonomous blinking at a configurable
 *   frequency. While the user-facing API specifies the blink period in
 *   milliseconds, all internal timekeeping is performed in microseconds to
 *   support precise handling of short periods (e.g., 1 ms).
 *
 *   Author contact: aguarini@unisa.it
 *   Affiliation   : PhD Student – Connected Autonomous Vehicles, MIVIA Lab.
 *
 *   Conforms to MISRA C:2012 guidelines for embedded C/C++ development.
 */

#include "led.hpp"

/**
 * @brief Constructs a Led instance on the specified pin.
 * @param pin Digital I/O pin connected to the LED.
 */
Led::Led(uint8_t pin)
    : pin_(pin),
      state_(false),
      blinking_period_us_(0U),
      last_toggle_time_(0U)
{
    pinMode(pin_, OUTPUT);
    digitalWrite(pin_, LOW);
    last_toggle_time_ = micros();
}

/**
 * @brief Turns the LED on.
 */
void Led::on(void)
{
    digitalWrite(pin_, HIGH);
    state_ = true;
}

/**
 * @brief Turns the LED off.
 */
void Led::off(void)
{
    digitalWrite(pin_, LOW);
    state_ = false;
}

/**
 * @brief Inverts the current output state of the LED.
 */
void Led::toggle(void)
{
    if (false == state_)
    {
        digitalWrite(pin_, HIGH);
        state_ = true;
    }
    else
    {
        digitalWrite(pin_, LOW);
        state_ = false;
    }
    last_toggle_time_ = micros();
}

/**
 * @brief Performs time-driven blinking according to blinking_period_us_.
 *        Call this method periodically inside loop().
 */
void Led::blink(void)
{
    if (blinking_period_us_ > 0U)
    {
        const uint32_t current_time = micros();
        if ((current_time - last_toggle_time_) >= blinking_period_us_)
        {
            toggle();
        }
    }
}

/**
 * @brief Sets the blinking period for the LED.
 * @param period_ms Total blink period in milliseconds.
 * @note Internally converted to half-period in microseconds.
 */
void Led::set_blinking_period(uint32_t period_ms)
{
    blinking_period_us_ = period_ms * 500U;
}