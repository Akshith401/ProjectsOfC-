/**
 * @file main.cpp
 * @brief Entry point for the HeatingController application.
 *
 * This program initializes and starts the heating controller system.
 * It includes core components such as:
 *  - UserInterface
 *  - SafetyCheck
 *  - Scheduler
 *  - Thermostat
 *  - HeatingController
 *  - TemperatureSensor
 *
 * The main function currently prints a startup message and can be
 * extended to initialize the full control loop.
 */

#include <iostream>
#include <cstdlib>
#include "UserInterface.h"
#include "SafetyCheck.h"
#include "Scheduler.h"
#include "Thermostat.h"
#include "HeatingController.h"
#include "TemperatureSensor.h"

using namespace std;

/**
 * @brief Program entry point.
 *
 * Initializes components and displays a startup message.
 *
 * @return Returns 0 on successful execution.
 */
int main ()
{
    // Startup message
    cout << "HeatingController started." << endl << endl;

    // TODO: Add initialization and control loop here

    return 0;
}
