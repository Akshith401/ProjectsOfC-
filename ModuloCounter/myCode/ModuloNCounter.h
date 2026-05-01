/*
 * ModuloNCounter.h
 *
 *  Created on: 15-Nov-2025
 *      Author: akshi
 */

#include "ModuloNDigit.h"

#ifndef MODULONCOUNTER_H_
#define MODULONCOUNTER_H_

/**
 * @class ModuloNCounter
 * @brief A counter with multiple digits, each a ModuloNDigit,
 * for a specific base.
 *
 * This class lets you create counters with multiple digits
 * in base 2, 8, 10, or 16.
 * It supports incrementing, printing values, and
 * using prefix/postfix ++ operators.
 */
class ModuloNCounter {
private:
    ModuloNDigit* digits; ///< Array of digits in the counter
    int numDigits;        ///< Number of digits in the counter
    int base;             ///< Base of the counter (2, 8, 10, 16)

public:
    /**
     * @brief Constructor for ModuloNCounter.
     *
     * @param m Number of digits
     * @param n Base of the counter (allowed: 2, 8, 10, 16)
     */
    ModuloNCounter(int m, int n);

    /**
     * @brief Destructor for ModuloNCounter.
     */
    virtual ~ModuloNCounter();

    /**
     * @brief Increments the counter by 1.
     *
     * @return true if the counter wraps around, false otherwise
     */
    bool increment();

    /**
     * @brief Prints the type of counter (e.g., "Decimal counter").
     */
    void printName();

    /**
     * @brief Prints the current value of the counter.
     */
    void printValue();

    /**
     * @brief Prefix increment operator (++counter)
     *
     * @return ModuloNCounter& Reference to the updated counter
     */
    ModuloNCounter &operator++();

    /**
     * @brief Postfix increment operator (counter++)
     *
     * @return ModuloNCounter Counter value before increment
     */
    ModuloNCounter operator++(int);
};

#endif /* MODULONCOUNTER_H_ */
