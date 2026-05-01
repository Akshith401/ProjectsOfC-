/**
 * @file Shot.cpp
 * @author Akshith
 * @date 24-Dec-2025
 *
 * Implements the Shot class, representing a single shot fired
 * on the Battleship grid. Tracks the target position of the
 * shot and provides access methods.
 */

#include "Shot.h"

/**
 * @brief Constructs a Shot object at a specific grid position.
 *
 * Initializes the shot with the target position where it is aimed
 * on the grid. This position is used for determining hit or miss.
 *
 * @param targetPosition GridPosition where the shot is targeted.
 */
Shot::Shot(GridPosition targetPosition) :targetPosition(targetPosition) {

}

/**
* @brief Destroys the Shot object.
*
* Virtual destructor allows safe inheritance and proper cleanup
* if the class is extended in the future.
*/
Shot::~Shot() {
}

/**
 * @brief Returns the target position of the shot.
 *
 * Provides read-only access to the grid position that the shot
 * is aimed at. Used for hit/miss evaluation and updating grids.
 *
 * @return GridPosition of the shot target.
 */
GridPosition Shot::getTargetPosition() const{

	return targetPosition;
}
