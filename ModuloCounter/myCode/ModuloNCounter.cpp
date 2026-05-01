/*
 * ModuloNCounter.cpp
 *
 *  Created on: 15-Nov-2025
 *      Author: akshi
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "ModuloNCounter.h"

/**
 * @brief Constructor for ModuloNCounter.
 *
 * Creates a counter with multiple digits (each a ModuloNDigit)
 * in the given base.
 * If invalid values are entered, it prints an error message.
 *
 * @param m Number of digits
 * @param n Base (allowed: 2, 8, 10, 16)
 */
ModuloNCounter::ModuloNCounter(int m, int n)
{
    if(m <= 0 || (n != 2 && n != 8 && n != 10 && n != 16))
    {
        cout << "Invalid Base or m value < 0 entered" << endl;
    }
    else
    {
        numDigits = m;
        base = n;
        digits = new ModuloNDigit[m];
        for(int i = 0; i < m; i++)
        {
            digits[i] = ModuloNDigit(n);
        }
    }
}

/**
 * @brief Destructor for ModuloNCounter.
 *
 * Frees the dynamically allocated array of digits.
 */
ModuloNCounter::~ModuloNCounter()
{
    delete[] digits;
    digits = nullptr;
}

/**
 * @brief Increments the whole counter.
 *
 * Starts from the least significant digit (rightmost) and handles overflow.
 *
 * @return true if all digits overflow (counter wraps around),
 *  false otherwise
 */
bool ModuloNCounter::increment()
{
    for(int i = numDigits - 1; i >= 0; --i)
    {
        bool overflow_check = digits[i].increment();
        if(!overflow_check)
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Prints the counter's type and base.
 */
void ModuloNCounter::printName()
{
    cout << base << " digit ";
    switch(base)
    {
        case 2:  cout << "Binary counter" << endl; break;
        case 8:  cout << "Octal counter" << endl; break;
        case 10: cout << "Decimal counter" << endl; break;
        case 16: cout << "HexaDecimal counter" << endl; break;
        default: cout << "Invalid base entered" << endl;
    }
}

/**
 * @brief Prints the current value of the counter.
 *
 * Calls printValue() for each digit.
 */
void ModuloNCounter::printValue()
{
    for(int i = 0; i < numDigits; i++)
    {
        digits[i].printValue();
    }
    cout << " ";
}

/**
 * @brief Prefix increment operator (++counter)
 *
 * Increments digits starting from least significant digit.
 *
 * @return ModuloNCounter& Reference to the updated counter
 */
ModuloNCounter& ModuloNCounter::operator++()
{
    for(int i = numDigits - 1; i >= 0; --i)
    {
        if(!digits[i].increment())
            break;
    }
    return *this;
}

/**
 * @brief Postfix increment operator (counter++)
 *
 * Increments all digits and returns the value before increment.
 *
 * @return ModuloNCounter Counter value before increment
 */
ModuloNCounter ModuloNCounter::operator++(int)
{
    ModuloNCounter temp = *this;
    for(int i = numDigits - 1; i >= 0; --i)
    {
        digits[i].increment();
    }
    return temp;
}
