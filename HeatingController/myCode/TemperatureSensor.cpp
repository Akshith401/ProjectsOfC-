/*
 * TemperatureSensor.cpp
 *
 *  Created on: 15-Nov-2025
 *      Author: akshi
 */

#include "TemperatureSensor.h"

/**
 * @brief Constructs a TemperatureSensor object.
 *
 * Initializes the temperature reading to 0.
 */
TemperatureSensor::TemperatureSensor() {

    temperature = 0;
}

/**
 * @brief Reads the temperature from the sensor hardware.
 *
 * This function should interact with the physical sensor to
 * update the internal @c temperature value.
 */
void TemperatureSensor::readSensor() {
}

/**
 * @brief Retrieves the current temperature reading.
 *
 * @return The current temperature as a float.
 */
float TemperatureSensor::getTemperature() const {

    return temperature;

}
