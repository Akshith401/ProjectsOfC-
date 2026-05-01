/*
 * Thermostat.h
 *
 *  Created on: 15-Nov-2025
 *      Author: akshi
 */
#ifndef THERMOSTAT_H
#define THERMOSTAT_H

/**
 * @brief Thermostat controller class implementing heating logic.
 *
 * This class models a thermostat system based on the provided flowchart.
 * It displays the current and desired temperatures, manages heating mode,
 * and controls activation/deactivation of the heater depending on whether
 * the current temperature is below or above the desired temperature.
 */
class Thermostat {
private:
    float currentTemp;   ///< The current temperature measured by the system.
    float desiredTemp;   ///< The user-defined target temperature.
    bool heaterOn;       ///< Tracks whether the heater is currently active.

    /**
     * @brief Operating modes for the thermostat.
     */
    enum Mode {
        OFF,     ///< Heating system is disabled.
        HEATING  ///< Thermostat will monitor and control the heater.
    } mode;      ///< Current operating mode.

public:
    /**
     * @brief Constructs a new Thermostat object.
     *
     * @param initialTemp Initial measured temperature.
     * @param targetTemp Initial desired temperature set by the user.
     */
    Thermostat(float initialTemp = 20.0f, float targetTemp = 22.0f);

    /**
     * @brief Sets the thermostat operating mode.
     *
     * @param m The mode to switch to (OFF or HEATING).
     */
    void setMode(Mode m);

    /**
     * @brief Sets the desired temperature.
     *
     * @param temp The new target temperature.
     */
    void setDesiredTemp(float temp);

    /**
     * @brief Retrieves the current temperature.
     *
     * @return The measured current temperature.
     */
    float getCurrentTemp() const;

    /**
     * @brief Retrieves the user-defined desired temperature.
     *
     * @return The desired target temperature.
     */
    float getDesiredTemp() const;

    /**
     * @brief Checks whether the heater is currently active.
     *
     * @return true if the heater is on, false otherwise.
     */
    bool isHeaterOn() const;

    /**
     * @brief Retrieves the current operating mode.
     *
     * @return The current thermostat mode.
     */
    Mode getMode() const;

    /**
     * @brief Main logic update for the thermostat.
     *
     * This function should be called periodically. It performs the logic
     * specified in the flowchart:
     *  - Displays the mode and current temperature.
     *  - If in OFF mode: does nothing.
     *  - If in HEATING mode:
     *      - If heater is off and
     *      currentTemp < desiredTemp → activates heater.
     *      - If heater is on and
     *      currentTemp >= desiredTemp → deactivates heater.
     *  - Displays the desired temperature afterward.
     */
    void update();

private:
    /**
     * @brief Activates the heating system.
     */
    void activateHeater();

    /**
     * @brief Deactivates the heating system.
     */
    void deactivateHeater();

    /**
     * @brief Displays the current temperature.
     *
     * Typically used for debugging or UI output.
     */
    void displayCurrentTemp() const;

    /**
     * @brief Displays the desired temperature.
     *
     * Typically used for debugging or UI output.
     */
    void displayDesiredTemp() const;
};

#endif // THERMOSTAT_H
