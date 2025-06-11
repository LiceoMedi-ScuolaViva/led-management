/**
 * @file led.hpp
 * @author Alessio Guarini
 * @version 1.1
 * @date 2025-06-09
 * @brief Abstraction for controlling a digital LED using Arduino.
 *
 * @details
 *   Provides an object-oriented interface for digital LED control using Arduino.
 *   The interface includes methods for switching the LED on, off, and toggling
 *   its state. Designed to be minimal, intuitive, and MISRA C:2012 compliant,
 *   this class forms the basis for higher-level actuation logic in embedded systems.
 *
 *   Author contact: aguarini@unisa.it
 *   Affiliation   : PhD Student – Connected Autonomous Vehicles, MIVIA Lab.
 */

#ifndef LED_HPP
#define LED_HPP

#include <Arduino.h>

/**
 * @class Led
 * @brief High-level driver for digital LED output control.
 */
class Led
{
public:
    /**
     * @brief Constructs a Led instance bound to a specific Arduino pin.
     * @param pin Arduino digital I/O pin connected to the LED.
     */
    explicit Led(uint8_t pin);

    /**
     * @brief Drives the LED to the ON state (logic HIGH).
     */
    void on(void);

    /**
     * @brief Drives the LED to the OFF state (logic LOW).
     */
    void off(void);

    /**
     * @brief Inverts the current output state of the LED.
     */
    void toggle(void);

private:
    uint8_t pin_;   /**< Arduino digital pin number */
    bool    state_; /**< Logical state of the LED: false = OFF, true = ON */
};

#endif /* LED_HPP */