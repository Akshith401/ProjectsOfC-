#ifndef HEATINGCONTROLLER_H
#define HEATINGCONTROLLER_H

/**
 * @class HeatingController
 * @brief Controls heating ON/OFF based on thermostat input.
 *
 * Implements the flowchart:
 *  1. Read thermostat input
 *  2. Decide ON/OFF
 *  3. Update heater hardware
 *  4. Display heater state
 *
 * HeatingController does not decide when heating is required.
 * That is handled by ThermostatLogic or SafetyMonitor.
 */
class HeatingController {
private:
    bool heatingOn; ///< true = ON, false = OFF

public:
    /** @brief Constructor: heater starts OFF. */
    HeatingController();

    /**
     * @brief Executes one control cycle.
     *
     * @param heatingRequested true if heating is required.
     * Flow:
     *  - heatingRequested = true → turn ON
     *  - heatingRequested = false → turn OFF
     *  - Update display
     */
    void update(bool heatingRequested);

    /** @brief Turns the heater ON. */
    void turnOn();

    /** @brief Turns the heater OFF. */
    void turnOff();

    /** @brief Returns true if heater is currently ON. */
    bool isHeatingOn() const;

    /** @brief Displays the current heater state. */
    void displayState() const;
};

#endif // HEATINGCONTROLLER_H
