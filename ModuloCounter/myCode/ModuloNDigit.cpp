/*
 * ModuloNDigit.cpp
 *
 *  Created on: 15-Nov-2025
 *      Author: akshi
 */

#include <iostream>
#include <cstdlib>
#include "ModuloNDigit.h"
using namespace std;

/**
 * @brief Constructor to create a ModuloNDigit counter.
 *
 * @param n Maximum value of the counter (counter goes from 0 to n-1)
 */
ModuloNDigit::ModuloNDigit(int n)
{
	m_maxValue = n;
	m_currentValue = 0;
}

/**
 * @brief Destructor for ModuloNDigit class.
 */
ModuloNDigit::~ModuloNDigit()
{
	// Nothing to clean up for now
}

/**
 * @brief Increments the counter by 1.
 *
 * @return true if counter wraps around to 0, false otherwise
 */
bool ModuloNDigit::increment()
{
	m_currentValue++;
	if(m_currentValue >= m_maxValue) // check for wrap-around
	{
		m_currentValue = 0;
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * @brief Resets the counter value to 0.
 */
void ModuloNDigit::reset()
{
	m_currentValue = 0;
}

/**
 * @brief Prints the name of the counter (like "Modulo10digit").
 */
void ModuloNDigit::printName()
{
	cout << "Modulo" << m_maxValue << "digit" << endl;
}

/**
 * @brief Prints the current value of the counter.
 *
 * For base 16, values 10-15 are printed as A-F.
 */
void ModuloNDigit::printValue()
{
	if (m_maxValue == 16 && m_currentValue >= 10)
		cout << static_cast<char>('A' + (m_currentValue - 10));
	else
		cout << m_currentValue;
}

/**
 * @brief Prefix increment operator (++counter)
 */
ModuloNDigit& ModuloNDigit::operator++()
		{
	increment();
	return *this;
		}

/**
 * @brief Returns the current value of the counter.
 *
 * @return int Current value
 */
int ModuloNDigit::getValue()
{
	return m_currentValue;
}

/**
 * @brief Returns the maximum value of the counter.
 *
 * @return int Maximum value
 */
int ModuloNDigit::getMaxvalue()
{
	return m_maxValue;
}

/**
 * @brief Postfix increment operator (counter++)
 *
 * @return ModuloNDigit Counter value before increment
 */
ModuloNDigit ModuloNDigit::operator++(int)
		{
	ModuloNDigit temp = *this;
	increment();
	return temp;
		}
