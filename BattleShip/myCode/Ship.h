/**
 * @file Ship.h
 * @author Akshith
 * @date 14-Dec-2025
 *
 * Declares the Ship class, representing a ship on the Battleship grid.
 * Handles validation, computation of occupied and blocked positions,
 * length calculation, and provides visualization support.
 */

#ifndef SHIP_H_
#define SHIP_H_

#include <iostream>
#include <set>
#include "GridPosition.h"

/**
 * @class Ship
 *
 * Represents a single ship on the grid with a bow and stern position.
 * Provides methods to check validity, determine occupied and blocked
 * areas, compute length, and print ship details.
 */
class Ship
{
private:
	/**
	 * @brief The bow (start) position of the ship.
	 *
	 * Defines one endpoint of the ship on the grid and is used to
	 * determine orientation and length.
	 */
	GridPosition bow;

	/**
	 * @brief The stern (end) position of the ship.
	 *
	 * Defines the other endpoint of the ship on the grid and
	 * helps determine occupied area and orientation.
	 */
	GridPosition stern;

public:
	/**
	 * @brief Constructs a Ship with specified bow and stern.
	 *
	 * Initializes a ship on the grid using two positions. Orientation
	 * and length are inferred from these positions.
	 *
	 * @param bow GridPosition for the bow of the ship.
	 * @param stern GridPosition for the stern of the ship.
	 */
	Ship(const GridPosition &bow, const GridPosition &stern);

	/**
	 * @brief Destroys the Ship object.
	 *
	 * Virtual destructor ensures proper cleanup and safe inheritance
	 * if the class is extended.
	 */
	virtual ~Ship();

	/**
	 * @brief Checks if the ship's placement is valid.
	 *
	 * Validity requires the ship to be strictly horizontal or vertical,
	 * length between 2 and 5, and all coordinates within the grid.
	 *
	 * @return True if the ship placement is valid, false otherwise.
	 */
	bool isValid() const;

	/**
	 * @brief Returns the bow position of the ship.
	 *
	 * Provides access to the starting coordinate of the ship.
	 *
	 * @return GridPosition of the bow.
	 */
	GridPosition getBow() const;

	/**
	 * @brief Returns the stern position of the ship.
	 *
	 * Provides access to the ending coordinate of the ship.
	 *
	 * @return GridPosition of the stern.
	 */
	GridPosition getStern() const;

	/**
	 * @brief Computes the length of the ship.
	 *
	 * Calculates the number of cells the ship occupies including both
	 * endpoints, based on horizontal or vertical orientation.
	 *
	 * @return Length of the ship as an integer.
	 */
	int length() const;

	/**
	 * @brief Returns all grid positions occupied by the ship.
	 *
	 * Computes a set of GridPosition objects representing each cell
	 * covered by the ship on the grid.
	 *
	 * @return Set of GridPosition objects.
	 */
	const std::set<GridPosition> occupiedArea() const;

	/**
	 * @brief Returns the blocked area around the ship.
	 *
	 * Computes all positions adjacent to the ship that cannot be
	 * occupied by another ship, including diagonals.
	 *
	 * @return Set of GridPosition objects representing blocked positions.
	 */
	const std::set<GridPosition> blockedArea() const;

};

#endif /* SHIP_H_ */
