/**
 * @file OwnGrid.h
 * @author Akshith
 * @date 15-Dec-2025
 *
 * Declares the OwnGrid class, which represents the player's own
 * grid, stores ships, tracks hits and sunken ships, and provides
 * methods for visualization and game interaction.
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_

#include <iostream>
#include <cstdlib>
#include "Ship.h"
#include "Shot.h"
#include <vector>
#include <map>

/**
 * @class OwnGrid
 *
 * Manages the player's ships and their placement, records all
 * incoming shots, and displays the current state of the board.
 */
class OwnGrid
{
private:
    /**
     * @brief Number of rows in the player's grid.
     *
     * Defines the vertical extent of the grid and is used for
     * indexing ships and shots.
     */
    int rows;

    /**
     * @brief Number of columns in the player's grid.
     *
     * Defines the horizontal extent of the grid and is used for
     * indexing ships and shots.
     */
    int columns;

    /**
     * @brief Container storing all ships placed on the grid.
     *
     * Each ship is represented as a Ship object and is used to
     * check collisions, blocked areas, and ship impacts.
     */
    std::vector<Ship> ships;

    /**
     * @brief Maps grid positions to shot impacts.
     *
     * Tracks all incoming shots fired at the player's grid, storing
     * results as HIT, SUNKEN, or NONE.
     */
    std::map<GridPosition, Shot::Impact> shotAt;

public:
    /**
     * @brief Constructs an OwnGrid with given dimensions.
     *
     * Initializes the grid and prepares internal containers to
     * manage ships and shots.
     *
     * @param rows Number of rows in the grid.
     * @param columns Number of columns in the grid.
     */
    OwnGrid(int rows, int columns);

    /**
     * @brief Destroys the OwnGrid object.
     *
     * Destructor is virtual to allow safe inheritance and proper
     * cleanup in extended classes.
     */
    virtual ~OwnGrid();

    /**
     * @brief Returns a grid dimension.
     *
     * Provides the number of rows or columns. Both getters share
     * the same documentation for consistency.
     *
     * @return Number of rows.
     */
    int getRows();

    /**
     * @brief Returns a grid dimension.
     *
     * Provides the number of rows or columns. Both getters share
     * the same documentation for consistency.
     *
     * @return Number of columns.
     */
    int getColumns();


    /**
     * @brief Places a ship on the grid.
     *
     * Validates the ship's position, prevents overlapping or
     * blocked placement, and checks the maximum allowed by length.
     *
     * @param ship Reference to the Ship object to place.
     * @return True if placement succeeds, false otherwise.
     */
    bool placeShip(const Ship &ship);

    /**
     * @brief Processes a shot fired at the grid.
     *
     * Determines if the shot hits, sinks, or misses a ship and
     * updates the internal state accordingly.
     *
     * @param shot Reference to the fired Shot object.
     * @return Resulting impact: HIT, SUNKEN, or NONE.
     */
    Shot::Impact takeBlow(const Shot &shot);

    /**
     * @brief Returns all recorded shots on the grid.
     *
     * Provides read-only access to the mapping of positions to
     * shot results for external inspection.
     *
     * @return Map of GridPosition to Shot::Impact.
     */
    const std::map<GridPosition, Shot::Impact> getShotAt();

    /**
     * @brief Returns all ships placed on the grid.
     *
     * Allows read-only access to the internal vector of Ship objects
     * owned by the player.
     *
     * @return Vector of Ship objects.
     */
    const std::vector<Ship> getShips() const;
};

#endif /* OWNGRID_H_ */
