/**
 * @file Shot.h
 * @author Akshith
 * @date 24-Dec-2025
 *
 * Declares the Shot class, which represents a single shot fired
 * on the Battleship grid. Tracks the target position and its
 * impact result (HIT, SUNKEN, or NONE).
 */

#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

/**
 * @class Shot
 *
 * Represents an individual shot fired at a grid position.
 * Provides methods to access the target position and stores
 * the possible impact outcome of the shot.
 */
class Shot
{
private:
	/**
	 * @brief The target position of the shot on the grid.
	 *
	 * Specifies the exact cell on the grid that the shot
	 * is aimed at, used for evaluating hits or misses.
	 */
	GridPosition targetPosition;

public:
	/**
	 * @brief Enumerates possible shot outcomes.
	 *
	 * Defines the result of a shot: None (miss), HIT, or SUNKEN.
	 */
	typedef enum
	{
		None = 0,  /**< Shot missed */
		HIT,       /**< Shot hit a ship but did not sink it */
		SUNKEN     /**< Shot hit and sank a ship */
	} Impact;

	/**
	 * @brief Constructs a Shot object at a given grid position.
	 *
	 * Initializes a shot aimed at the specified target position.
	 *
	 * @param targetPosition GridPosition where the shot is targeted.
	 */
	Shot(GridPosition targetPosition);

	/**
	 * @brief Destroys the Shot object.
	 *
	 * Virtual destructor ensures safe cleanup if the class is
	 * inherited or extended in the future.
	 */
	virtual ~Shot();

	/**
	 * @brief Returns the target position of the shot.
	 *
	 * Provides read-only access to the grid position where the
	 * shot is aimed. Useful for grid updates and impact evaluation.
	 *
	 * @return GridPosition of the shot target.
	 */
	GridPosition getTargetPosition() const;
};

#endif /* SHOT_H_ */
