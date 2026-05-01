/*
 * UserInterface.h
 *
 *  Created on: 15-Nov-2025
 *      Author: akshi
 */

#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

/**
 * @class UserInterface
 * @brief Handles user-level control of the heating system.
 *
 * This class represents the behaviour shown in the flowchart:
 *  - Start
 *  - Turn on heater
 *  - Read current temperature
 *  - Compare current vs desired temperature
 *  - If equal → display temperature
 *  - If not equal → set desired temperature
 */
class UserInterface {
public:
    /**
     * @brief Constructs a new UserInterface object.
     *
     * Initializes temperature variables and prepares the interface.
     */
    UserInterface();

    /**
     * @brief Runs the complete user control routine.
     *
     * Implements the flowchart logic:
     *  - Turns heater on
     *  - Obtains current temperature
     *  - Decides whether to display or update desired temperature
     */
    void run();

private:
    /**
     * @brief Turns on the heater device.
     *
     * This is the first operational step after start.
     */
    void turnOnHeater();

    /**
     * @brief Reads the current temperature from the system.
     *
     * @return float The measured current temperature.
     */
    float readCurrentTemperature();

    /**
     * @brief Prompts the user to set the desired temperature.
     *
     * Called when the current temperature does not match the desired value.
     */
    void setDesiredTemperature();

    /**
     * @brief Displays the current temperature to the user.
     *
     * @param temp The temperature value to display.
     */
    void displayTemperature(float temp);

    /**
     * @brief Checks if the current temperature
     * equals the desired temperature.
     *
     * @param current The current measured temperature.
     * @return true if current equals desired, false otherwise.
     */
    bool isCurrentEqualDesired(float current) const;

    /// @brief Current measured temperature.
    float currentTemperature;

    /// @brief Desired target temperature set by the user.
    float desiredTemperature;
};
#endif /* USERINTERFACE_H_ */
