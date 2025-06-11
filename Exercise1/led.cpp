/**
 * @file led.cpp
 * @author Alessio Guarini
 * @version 1.1
 * @date 2025-06-09
 * @brief Implementation of the Led class for controlling a digital LED on Arduino.
 *
 * @details
 *   Implements the methods defined in led.hpp for managing a digital LED
 *   connected to an Arduino output pin. The class supports direct manipulation
 *   of the LED state through on(), off(), and toggle() operations.
 *   Designed for educational use and MISRA C:2012 compliant environments.
 *
 *   Author contact: aguarini@unisa.it
 *   Affiliation   : PhD Student – Connected Autonomous Vehicles, MIVIA Lab.
 */

#include "led.hpp"

/**
 * @brief Constructs a Led instance on the specified pin.
 * @param pin Digital I/O pin connected to the LED.
 */
Led::Led(uint8_t pin)
    : pin_(pin),
      state_(false)
{
    pinMode(pin_, OUTPUT);
    digitalWrite(pin_, LOW);
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
 * @brief Toggles the LED state.
 */
void Led::toggle(void)
{
    state_ = !state_;
    digitalWrite(pin_, state_);
}