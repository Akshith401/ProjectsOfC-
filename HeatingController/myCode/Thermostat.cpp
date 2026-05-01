/*
 * Thermostat.cpp
 *
 *  Created on: 15-Nov-2025
 *      Author: akshi
 */

#include "Thermostat.h"

/**
 * @brief Constructs a Thermostat object with initial and target temperatures.
 *
 * Initializes internal state variables:
 * - currentTemp to initialTemp
 * - desiredTemp to targetTemp
 * - heaterOn to false
 * - mode to OFF
 *
 * @param initialTemp The starting temperature of the system.
 * @param targetTemp The user-desired target temperature.
 */
Thermostat::Thermostat(float initialTemp, float targetTemp)
    : currentTemp(initialTemp),
      desiredTemp(targetTemp),
      heaterOn(false),
      mode(OFF)
{
}

/**
 * @brief Sets the operational mode of the thermostat.
 *
 * @param m The mode to set (OFF, HEATING, COOLING, etc.).
 */
void Thermostat::setMode(Mode m) {
}

/**
 * @brief Updates the desired temperature.
 *
 * @param temp The new desired temperature to maintain.
 */
void Thermostat::setDesiredTemp(float temp) {
}

/**
 * @brief Retrieves the current temperature.
 *
 * @return The current temperature as a float.
 */
float Thermostat::getCurrentTemp() const {

    return currentTemp;

}

/**
 * @brief Retrieves the desired temperature.
 *
 * @return The desired temperature as a float.
 */
float Thermostat::getDesiredTemp() const {

    return desiredTemp;

}

/**
 * @brief Checks if the heater is currently active.
 *
 * @return True if the heater is on; otherwise false.
 */
bool Thermostat::isHeaterOn() const {

    return heaterOn;

}

/**
 * @brief Retrieves the current operational mode of the thermostat.
 *
 * @return The current mode (OFF, HEATING, COOLING, etc.).
 */
Thermostat::Mode Thermostat::getMode() const {

    return mode;

}

/**
 * @brief Updates the thermostat logic.
 *
 * This function is intended to:
 * - Read current temperature
 * - Compare with desired temperature
 * - Turn heater on or off accordingly
 * Currently, the logic is not implemented.
 */
void Thermostat::update() {
}

/**
 * @brief Activates the heater.
 *
 * This function should set internal flags and potentially send commands
 * to the heating system.
 */
void Thermostat::activateHeater() {
}

/**
 * @brief Deactivates the heater.
 *
 * This function should set internal flags and potentially send commands
 * to stop the heating system.
 */
void Thermostat::deactivateHeater() {
}

/**
 * @brief Displays the current temperature to the user interface.
 */
void Thermostat::displayCurrentTemp() const {
}

/**
 * @brief Displays the desired temperature to the user interface.
 */
void Thermostat::displayDesiredTemp() const {
}
