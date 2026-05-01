/**
 * @file Board.h
 * @author Akshith
 * @date 15-Dec-2025
 *
 * Declares the Board class, which manages the player's grid and the
 * opponent's grid and provides access to board-related information.
 */

#ifndef BOARD_H_
#define BOARD_H_
#include "OwnGrid.h"
#include "OpponentGrid.h"

/**
 * @class Board
 *
 * Represents the complete game board consisting of two separate
 * grids: one for the player and one for the opponent.
 */

class Board {

private:
	/**
	 * @brief Player's own grid.
	 *
	 * Stores the state and content of the player's board and defines
	 * the reference dimensions for the entire board.
	 */
	OwnGrid ownGrid;
	/**
	 * @brief Opponent's grid.
	 *
	 * Represents the opponent's board and mirrors the dimensions of
	 * the player's grid for consistency.
	 */
	OpponentGrid opponentGrid;
public:
	/**
	 * @brief Constructs a Board with given dimensions.
	 *
	 * Initializes both grids using the same number of rows and columns
	 * to ensure a consistent board layout.
	 */
	Board(int rows, int columns);
	/**
	 * @brief Destroys the Board object.
	 *
	 * The destructor is virtual to support safe polymorphic use and
	 * future class extensions.
	 */
	virtual ~Board();
	/**
	 * @brief Row - Returns a board dimension.
	 *
	 * The value is obtained from the player's own grid, as both grids
	 * share identical dimensions throughout the board lifetime.
	 */
	int getRows();
	/**
	 * @brief Column - Returns a board dimension.
	 *
	 * The value is obtained from the player's own grid, as both grids
	 * share identical dimensions throughout the board lifetime.
	 */
	int getColumns();
	/**
	 * @brief Provides access to the player's own grid.
	 *
	 * Returns a reference to allow interaction without copying the
	 * underlying grid object.
	 */


	OwnGrid& getOwnGrid() ;
	/**
	 * @brief Provides access to the opponent's grid.
	 *
	 * Returns a reference that enables interaction while preserving
	 * logical separation from the player's grid.
	 */

	OpponentGrid& getOpponentGrid();
};

#endif /* BOARD_H_ */
