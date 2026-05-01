/*
 * Scheduler.cpp
 *
 *  Created on: 15-Nov-2025
 *      Author: akshi
 */

#include "Scheduler.h"

/**
 * @brief Constructs a Scheduler object and initializes internal state.
 *
 * The constructor sets:
 * - nightModeActive to false
 */
Scheduler::Scheduler() {

    nightModeActive = false;
}

/**
 * @brief Destructor for the Scheduler class.
 *
 * Currently, no special cleanup is required.
 */
Scheduler::~Scheduler() {
}

/**
 * @brief Updates the scheduler logic.
 *
 * This function is intended to manage timed events, such as activating
 * night mode or other scheduled temperature adjustments.
 */
void Scheduler::update() {
}

/**
 * @brief Retrieves a temperature modifier based on the current schedule.
 *
 * @return A float representing the modifier to apply to the base temperature.
 *         Currently returns 0 as a placeholder.
 */
float Scheduler::getTemperatureModifier() const {

    return 0;
}
