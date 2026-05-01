/**
 * @file OpponentGrid.cpp
 * @author Akshith
 * @date 15-Dec-2025
 *
 * Implements the OpponentGrid class, which stores and visualizes
 * shot results fired at the opponent during gameplay.
 */

#include "OpponentGrid.h"


/**
 * @brief Constructs an OpponentGrid with given dimensions.
 *
 * Initializes the grid with the specified number of rows and columns
 * used for tracking shots against the opponent.
 */
OpponentGrid::OpponentGrid(int rows, int columns) {

	this->rows = rows;
	this->columns = columns;
}
/**
 * @brief Destroys the OpponentGrid object.
 *
 * The destructor is explicitly defined for completeness and future
 * extensions, although no resources are released.
 */
OpponentGrid::~OpponentGrid() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief Row Returns a grid dimension.
 *
 * The value represents either the number of rows or columns and
 * defines the bounds of the opponent grid.
 */
int OpponentGrid::getRows() {

	return rows;
}
/**
 * @brief Column Returns a grid dimension.
 *
 * The value represents either the number of rows or columns and
 * defines the bounds of the opponent grid.
 */
int OpponentGrid::getColumns() {

	return columns;
}

/**
 * @brief Stores the result of a fired shot.
 *
 * Inserts the shot target position together with its impact result
 * into the internal shot tracking structure.
 */
void OpponentGrid::shotResult(const Shot &shot, Shot::Impact impact) {


	if(impact == Shot::Impact::HIT){
		shots.insert(std::make_pair(shot.getTargetPosition(),
				Shot::Impact::HIT));

	}
	else if(impact == Shot::Impact::SUNKEN)
	{
		shots.insert(std::make_pair(shot.getTargetPosition(),
				Shot::Impact::SUNKEN));
	}
	else if(impact == Shot::Impact::None)
	{
		shots.insert(std::make_pair(shot.getTargetPosition(),
				Shot::Impact::None));
	}


}
/**
 * @brief Returns all recorded shots.
 *
 * Provides read-only access to the mapping between grid positions
 * and their corresponding shot impacts.
 */
const std::map<GridPosition, Shot::Impact>& OpponentGrid::getShotsAt() const {

	return shots;
}
