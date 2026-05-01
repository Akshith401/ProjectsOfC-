/*
 * HeatingController.cpp
 *
 *  Created on: 15-Nov-2025
 *      Author: akshi
 */

#include "HeatingController.h"

/**
 * @brief Constructs a HeatingController object.
 *
 * Initializes the heater state to OFF.
 */
HeatingController::HeatingController() {
    heatingOn = false;
}

/**
 * @brief Executes one control cycle of the heating system.
 *
 * Evaluates the input from the thermostat and updates the heater
 * state accordingly. Also updates the display.
 *
 * @param heatingRequested True if thermostat logic requests heating.
 */
void HeatingController::update(bool heatingRequested) {
}

/**
 * @brief Turns the heater ON.
 *
 * Sets internal heater state and may send command to hardware.
 */
void HeatingController::turnOn() {
}

/**
 * @brief Turns the heater OFF.
 *
 * Sets internal heater state and may send command to hardware.
 */
void HeatingController::turnOff() {
}

/**
 * @brief Checks whether the heater is currently ON.
 *
 * @return True if the heater is ON, false otherwise.
 */
bool HeatingController::isHeatingOn() const {

    return heatingOn;

}

/**
 * @brief Displays the current heater state to the user interface.
 *
 * In a real system, this could update LEDs, screen, or app display.
 */
void HeatingController::displayState() const {
}
