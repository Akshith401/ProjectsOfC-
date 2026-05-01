/**
 * @file Board.cpp
 * @author akshi
 * @date 15-Dec-2025
 *
 * Implements the Board class, which encapsulates both the player's
 * grid and the opponent's grid, providing a unified interface for
 * accessing board dimensions and grid objects.
 */

#include "Board.h"
/**
 * @brief Constructs a Board with given dimensions.
 *
 * Initializes the player's grid and the opponent's grid with the
 * same number of rows and columns to ensure consistent board size.
 */
Board::Board(int rows, int columns):ownGrid(rows, columns),
opponentGrid(rows, columns){

}
/**
 * @brief Destroys the Board object.
 *
 * The destructor is defined explicitly for completeness and to
 * support future extensions that may require resource cleanup.
 */
Board::~Board() {
}
/**
 * @brief Rows Returns a board dimension.
 *
 * The value is obtained from the player's own grid, as both grids
 * share identical dimensions throughout the lifetime of the board.
 */
int Board::getRows() {

	return ownGrid.getRows();
}
/**
 * @brief Columns Returns a board dimension.
 *
 * The value is obtained from the player's own grid, as both grids
 * share identical dimensions throughout the lifetime of the board.
 */
int Board::getColumns() {

	return ownGrid.getColumns();
}

/**
 * @brief Provides access to the player's own grid.
 *
 * A reference is returned to allow direct interaction while avoiding
 * unnecessary copying of the grid object.
 */
OwnGrid& Board::getOwnGrid() {

	return ownGrid;
}

/**
 * @brief Provides access to the opponent's grid.
 *
 * The returned reference allows interaction with the opponent grid
 * while preserving separation from the player's own grid.
 */
OpponentGrid& Board::getOpponentGrid() {

	return opponentGrid;
}
