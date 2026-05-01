/**
 * @file GridPosition.h
 * @author Akshith
 * @date 13-Dec-2025
 *
 * Declares the GridPosition class, which represents a single
 * position on a grid using a row identifier and column index.
 */
#include<iostream>
#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_
#include <string.h>

/**
 * @class GridPosition
 *
 * Encapsulates the coordinates of a grid position and provides
 * validation, comparison, and conversion functionality.
 */
class GridPosition {

private:
	/**
	 * @brief Row identifier of the grid position.
	 *
	 * Stored as a character representing the horizontal coordinate
	 * within the grid.
	 */
	char row;
	/**
	 * @brief Column index of the grid position.
	 *
	 * Represents the vertical coordinate and is expected to be a
	 * positive integer value.
	 */
	int column;
public:
	/**
	 * @brief Constructs a GridPosition from row and column values.
	 *
	 * Initializes the grid position by assigning the given row
	 * character and column number.
	 */

	GridPosition(char row, int column);
	/**
	 * @brief Constructs a GridPosition from a string representation.
	 *
	 * Parses a position string such as "A5" and converts it into
	 * an internal row and column representation.
	 */

	GridPosition(std::string position);
	/**
	 * @brief Destroys the GridPosition object.
	 *
	 * The destructor is virtual to allow safe extension and proper
	 * cleanup in derived classes.
	 */

	virtual ~GridPosition();
	/**
	 * @brief Checks whether the grid position is valid.
	 *
	 * A position is considered valid if the row is alphabetic and
	 * the column number is greater than zero.
	 */

	bool isValid() const;
	/**
	 * @brief Returns the row identifier.
	 *
	 * The row is represented as a single character indicating the
	 * horizontal grid coordinate.
	 */

	char getRow() const;
	/**
	 * @brief Returns the column index.
	 *
	 * The column represents the vertical grid coordinate and is
	 * guaranteed to be non-negative.
	 */

	int getCoulumn() const;

	/**
	 * @brief Converts the grid position to a string.
	 *
	 * The resulting string consists of the row character followed
	 * by the decimal column index.
	 */

	operator std::string() const;
	/**
	 * @brief Compares two grid positions for equality.
	 *
	 * Two positions are equal if both their row and column values
	 * match exactly.
	 */

	bool operator==(const GridPosition &other) const;
	/**
	 * @brief Compares two grid positions for ordering.
	 *
	 * Positions are ordered first by row and then by column, which
	 * enables deterministic sorting.
	 */

	bool operator<(const GridPosition &other) const;


};

#endif /* GRIDPOSITION_H_ */
