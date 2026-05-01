/**
 * @file GridPosition.cpp
 * @author Akshith
 * @date 13-Dec-2025
 *
 * Implements the GridPosition class, which represents a single
 * position on a grid using a row identifier and a column index.
 */
#include<iostream>
#include "GridPosition.h"
#include <string.h>

/**
 * @brief Constructs a GridPosition from row and column values.
 *
 * Initializes the grid position by directly assigning the given
 * row character and column number.
 */

GridPosition::GridPosition(char row, int column) {

	this->row = row;
	this->column = column;
}

/**
 * @brief Constructs a GridPosition from a string representation.
 *
 * Extracts the row and column information from a string such as
 * "A5" and converts it into an internal grid position.
 */

GridPosition::GridPosition(std::string position) {

	row = position[0];
	column = std::stoi(position.substr(1));

}

/**
 * @brief Destroys the GridPosition object.
 *
 * The destructor is explicitly defined for completeness and future
 * extensions, although no resources are released.
 */

GridPosition::~GridPosition() {
	// TODO Auto-generated destructor stub

}
/**
 * @brief Checks whether the grid position is valid.
 *
 * A position is considered valid if the row is an alphabetic
 * character and the column number is greater than zero.
 */
bool GridPosition::isValid() const {

	if(((row >= 'A' && row <= 'Z') ||
			(row >= 'a' && row <= 'z')) && column > 0)
	{
		return true;
	}

	return false;
}

/**
 * @brief Returns the row identifier.
 *
 * The row is represented as a single character indicating the
 * horizontal position within the grid.
 */

char GridPosition::getRow() const{

	return row;
}
/**
 * @brief Returns the column index.
 *
 * The column value represents the vertical position within the
 * grid and is guaranteed to be non-negative.
 */
int GridPosition::getCoulumn() const{

	return column;
}
/**
 * @brief Compares two grid positions for equality.
 *
 * Two positions are equal if both their row characters and column
 * indices match exactly.
 */
bool GridPosition::operator ==(const GridPosition &other) const{

	if(row == other.row && column == other.column)
	{
		return true;
	}
	return false;
}

/**
 * @brief Converts the grid position to a string.
 *
 * The resulting string consists of the row character followed
 * by the decimal representation of the column index.
 */

GridPosition::operator std::string() const {

	return std::string(1, row) + std::to_string(column);
}
/**
 * @brief Compares two grid positions for ordering.
 *
 * Positions are ordered first by row and then by column, which
 * enables deterministic sorting of grid positions.
 */
bool GridPosition::operator <(const GridPosition &other) const{

	if(row < other.row)
	{
		return true;
	}
	if(row > other.row)
	{
		return false;
	}
	return column < other.column;
}

