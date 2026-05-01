/*
 * UserInterface.cpp
 *
 *  Created on: 15-Nov-2025
 *      Author: akshi
 */

#include "UserInterface.h"

/**
 * @brief Executes the main interface logic for interacting with the user.
 *
 * This function would typically handle periodic updates, user input,
 * and control signals for the heating system.
 * Currently, no logic is implemented.
 */
void UserInterface::run() {
}

/**
 * @brief Activates the heating system.
 *
 * This function is intended to turn on the heater hardware or
 * send a command to the heater controller.
 */
void UserInterface::turnOnHeater() {
}

/**
 * @brief Reads the current temperature from the sensor or interface.
 *
 * @return The current temperature as a float.
 *         Currently returns 0 as a placeholder.
 */
float UserInterface::readCurrentTemperature() {

    return 0;
}

/**
 * @brief Allows the user to set the desired temperature.
 *
 * This function is expected to receive input from the user (buttons,
 * touchscreen, or other interface) and update the desired temperature value.
 */
void UserInterface::setDesiredTemperature() {
}

/**
 * @brief Displays the given temperature value to the user interface.
 *
 * @param temp The temperature to display.
 *             Could be shown on a screen, LED display, or console output.
 */
void UserInterface::displayTemperature(float temp) {
}

/**
 * @brief Checks if the current temperature matches the desired temperature.
 *
 * @param current The current temperature value to compare.
 * @return True if current equals desired temperature; otherwise false.
 *         Currently always returns true as a placeholder.
 */
bool UserInterface::isCurrentEqualDesired(float current) const {

    return true;
}
