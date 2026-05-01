/*
 * ModuloNDigit.h
 *
 *  Created on: 15-Nov-2025
 *      Author: akshi
 */

#ifndef MODULONDIGIT_H_
#define MODULONDIGIT_H_

/**
 * @class ModuloNDigit
 * @brief A simple counter that counts from 0 up to (maxValue-1)
 * and then wraps around.
 *
 * This class supports incrementing, resetting, printing, and getting
 * the current and maximum values. It also supports prefix and postfix
 * increment operators.
 */
class ModuloNDigit {
private:
    int m_maxValue;    ///< Maximum value of the counter
    int m_currentValue;///< Current value of the counter

public:
    /**
     * @brief Constructor for ModuloNDigit.
     *
     * @param n Maximum value of the counter (default is 10)
     */
    ModuloNDigit(int n = 10);

    /**
     * @brief Destructor for ModuloNDigit.
     */
    virtual ~ModuloNDigit();

    /**
     * @brief Increments the counter by 1.
     *
     * @return true if the counter wraps around to 0, false otherwise
     */
    bool increment();

    /**
     * @brief Resets the counter value to 0.
     */
    void reset();

    /**
     * @brief Prints the name of the counter (like "Modulo10digit").
     */
    void printName();

    /**
     * @brief Prints the current value of the counter.
     *
     * For base 16, values 10-15 are printed as A-F.
     */
    void printValue();

    /**
     * @brief Gets the current value of the counter.
     *
     * @return int Current value
     */
    int getValue();

    /**
     * @brief Gets the maximum value of the counter.
     *
     * @return int Maximum value
     */
    int getMaxvalue();

    /**
     * @brief Prefix increment operator (++counter)
     *
     * @return ModuloNDigit& Reference to the updated counter
     */
    ModuloNDigit &operator++();

    /**
     * @brief Postfix increment operator (counter++)
     *
     * @return ModuloNDigit Counter value before increment
     */
    ModuloNDigit operator++(int);
};

#endif /* MODULONDIGIT_H_ */
