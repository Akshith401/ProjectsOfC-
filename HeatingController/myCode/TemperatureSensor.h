/*
 * TemperatureSensor.h
 *
 *  Created on: 15-Nov-2025
 *      Author: akshi
 */

#ifndef TEMPERATURESENSOR_H_
#define TEMPERATURESENSOR_H_

/**
 * @class TemperatureSensor
 * @brief Simulates or interfaces with a physical temperature sensor.
 *
 * Responsibilities:
 *  - Read the current room temperature
 *  - Provide access to the measured temperature
 *  - Could be extended to handle sensor errors or calibration
 */
class TemperatureSensor {
private:
    float temperature;  ///< Stores the most recent measured temperature

public:
    /**
     * @brief Constructor initializes temperature to a default value.
     */
    TemperatureSensor();

    /**
     * @brief Simulates reading the current temperature from the sensor.
     *
     * In a real system, this would interface with hardware.
     * Here it can be used to simulate changes in temperature over time.
     */
    void readSensor();

    /**
     * @brief Returns the last measured temperature.
     *
     * @return float The most recent sensor reading.
     */
    float getTemperature() const;
};

#endif /* TEMPERATURESENSOR_H_ */
