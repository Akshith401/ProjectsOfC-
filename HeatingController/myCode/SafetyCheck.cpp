/*
 * SafetyCheck.cpp
 *
 *  Created on: 14-Nov-2025
 *      Author: akshi
 */

#include "SafetyCheck.h"

/**
 * @brief Constructs a SafetyCheck object and initializes all
 *        internal status flags and temperature values.
 *
 * The constructor sets:
 * - sensorError to false
 * - usingDefaultTemp to false
 * - finalTemperature to 0.0f
 */
SafetyCheck::SafetyCheck() {
    sensorError = false;
    usingDefaultTemp = false;
    finalTemperature  = 0.0f;
}

/**
 * @brief Executes the safety validation logic using the measured and
 *        user-requested temperatures.
 *
 * This function is intended to evaluate conditions such as sensor failure,
 * invalid temperature readings, and fallback logic.
 * Currently, the logic is not implemented.
 *
 * @param measuredTemp     The temperature value read from the sensor.
 * @param userDesiredTemp  The temperature value requested by the user.
 */
void SafetyCheck::runSafetyCheck(float measuredTemp, float userDesiredTemp) {
}

/**
 * @brief Retrieves the computed final temperature after applying all
 *        safety validations.
 *
 * @return The resulting temperature value as a floating-point number.
 */
float SafetyCheck::getFinalTemperature() const {

    return finalTemperature;
}

/**
 * @brief Indicates whether a sensor fault was detected during
 * the safety check.
 *
 * @return True if a sensor error occurred; otherwise false.
 */
bool SafetyCheck::isSensorError() const {

    return sensorError;
}

/**
 * @brief Reports whether the system had to fall back on a predefined
 *        default temperature due to invalid or unsafe conditions.
 *
 * @return True if the default temperature was used; otherwise false.
 */
bool SafetyCheck::isUsingDefaultTemperature() const {

    return usingDefaultTemp;
}
