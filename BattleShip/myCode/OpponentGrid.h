/**
 * @file OpponentGrid.h
 * @author Akshith
 * @date 15-Dec-2025
 *
 * Declares the OpponentGrid class, which tracks the state of shots
 * fired at the opponent and provides a console view of hits, misses,
 * and sunken ships.
 */
#include <iostream>
#include <cstdlib>
#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_
#include "Ship.h"
#include "Shot.h"
#include <vector>
#include <map>

/**
 * @class OpponentGrid
 *
 * Stores the dimensions of the opponent's board, keeps track of all
 * fired shots and their results, and provides visualization methods.
 */
class OpponentGrid {

private:
	/**
	 * @brief Number of rows in the opponent grid.
	 *
	 * Defines the vertical extent of the grid and is used for
	 * indexing shots and printing the board.
	 */
	int rows;
	/**
	 * @brief Number of columns in the opponent grid.
	 *
	 * Defines the horizontal extent of the grid and is used for
	 * indexing shots and printing the board.
	 */
	int columns;
	/**
	 * @brief Container for all sunken ships.
	 *
	 * Stores references to ships that have been completely sunk
	 * during the game.
	 */
	std::vector<Ship> sunkenShips;
	/**
	 * @brief Maps grid positions to shot impacts.
	 *
	 * Tracks each shot fired at the opponent, including HIT, SUNKEN,
	 * and MISS results.
	 */
	std::map<GridPosition,Shot::Impact> shots;
public:
	/**
	 * @brief Constructs an OpponentGrid with given dimensions.
	 *
	 * Initializes the grid and prepares internal structures to
	 * track shots and sunken ships.
	 */
	OpponentGrid(int rows, int columns);

	/**
	 * @brief Destroys the OpponentGrid object.
	 *
	 * The destructor is virtual to support future class extensions
	 * and safe polymorphic cleanup.
	 */
	virtual ~OpponentGrid();

	/**
	 * @brief Returns a grid dimension.
	 *
	 * Provides the number of rows or columns in the opponent grid.
	 * Both getters use the same documentation for consistency.
	 */
	int getRows();

	/**
	 * @brief Returns a grid dimension.
	 *
	 * Provides the number of rows or columns in the opponent grid.
	 * Both getters use the same documentation for consistency.
	 */
	int getColumns();


	/**
	 * @brief Records the result of a shot.
	 *
	 * Updates the internal mapping between grid positions and
	 * impact results (HIT, SUNKEN, or None).
	 */
	void shotResult(const Shot& shot, Shot::Impact impact);

	/**
	 * @brief Returns all recorded shots.
	 *
	 * Provides read-only access to the mapping of positions and
	 * their associated shot impacts.
	 */
	const std::map<GridPosition,Shot::Impact>& getShotsAt() const;

};

#endif /* OPPONENTGRID_H_ */
