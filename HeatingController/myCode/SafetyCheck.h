/*
 * SafetyCheck.h
 *
 *  Created on: 14-Nov-2025
 *      Author: akshi
 */

#ifndef SAFETYCHECK_H_
#define SAFETYCHECK_H_

/**
 * @class SafetyCheck
 * @brief Performs
 * safety validation of temperature readings and user settings.
 *
 * This component implements the safety logic described in the flowchart:
 *  - Reads user-desired temperature
 *  - Validates sensor temperature (checks whether the value is possible)
 *  - Verifies if the temperature is within expected operational ranges
 *  - Falls back to a default temperature if readings are suspicious
 *  - Detects sensor faults and reports issues
 *  - Provides a final, safe temperature to be used by the controller
 */
class SafetyCheck {
private:
	///< True if the sensor reading is invalid
    bool sensorError;
    ///< True if the system fell back to a default safe temperature
    bool usingDefaultTemp;
    ///< Temperature that is safe to use after checks
    float finalTemperature;

    // Safety limits (these match your flowchart logic)
    const float USER_MIN_TEMP = 15.0f; /// Comfortable room lower limit
    const float USER_MAX_TEMP = 30.0f; /// Comfortable room upper limit

    ///< Fallback temperature when sensor data is suspicious
    const float DEFAULT_TEMP   = 20.0f;

public:

    /** @brief Constructor initializes flags to safe defaults. */
    SafetyCheck();

    /**
     * @brief Performs all safety checks on the measured
     * and user-desired temperatures.
     *
     * Flow (matches your diagram):
     *  1. Get user's desired temperature (input parameter)
     *  2. Check if sensor reading is valid → if not: sensorError = true
     *  3. If value is valid but
     *  outside expected range → use default fallback temperature
     *  4. Otherwise → use userDesiredTemp as final safe temperature
     *
     * @param measuredTemp  The temperature read from the sensor.
     * @param userDesiredTemp The temperature the user wants.
     */
    void runSafetyCheck(float measuredTemp, float userDesiredTemp);

    /**
     * @brief Returns the final validated temperature
     * that the system should use.
     *
     * This may be:
     *  - The user’s desired temperature (normal case)
     *  - A fallback default temperature (if sensor gives suspicious values)
     */
    float getFinalTemperature() const;

    /** @brief True if the sensor reading was invalid (hardware issue). */
    bool isSensorError() const;

    /** @brief True if safety fallback
     * temperature was used instead of user input. */
    bool isUsingDefaultTemperature() const;
};

#endif /* SAFETYCHECK_H_ */
