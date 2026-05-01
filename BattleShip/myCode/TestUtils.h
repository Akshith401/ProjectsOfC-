/**
 * @file partstest.h
 * @author Akshith
 * @date 08-Jan-2026
 *
 * Provides function declarations for testing individual parts of the
 * Battleship project, including grid operations, ship placement,
 * and shot handling. Also includes a simple inline assertion utility.
 */

#ifndef TESTUTILS_H_
#define TESTUTILS_H_

#include <iostream>
#include <string>
#include "Board.h"
#include "GridPosition.h"
#include "Ship.h"
#include "OwnGrid.h"
#include "Shot.h"

/**
 * @brief Executes tests related to the first part of the project.
 *
 * Typically used to validate basic operations like grid creation,
 * getters, and fundamental object initialization.
 */
void part1tests();

/**
 * @brief Executes tests related to the second part of the project.
 *
 * Often focuses on ship placement, occupied areas, and validation
 * of grid constraints.
 */
void part2tests();

/**
 * @brief Executes tests related to the third part of the project.
 *
 * Usually tests shot handling, hit/sunken detection, and overall
 * grid updates after gameplay actions.
 */
void part3tests();

/**
 * @brief Checks a boolean condition and prints a message if false.
 *
 * Inline helper function to simplify test validations. Prints
 * the provided message whenever the assertion fails.
 *
 * @param condition Boolean condition to verify.
 * @param message Message to display if the condition is false.
 */
inline void assertTrue(bool condition, const std::string &message)
{
    if (!condition)
    {
        std::cout << message << std::endl;
    }
}

#endif /* TESTUTILS_H_ */
