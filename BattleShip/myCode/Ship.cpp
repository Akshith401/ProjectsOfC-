/**
 * @file Ship.cpp
 * @author Akshith
 * @date 14-Dec-2025
 *
 * Implements the Ship class, representing a ship on the grid.
 * Handles validation, calculation of occupied positions, blocked
 * areas, length computation, and console visualization.
 */

#include<iostream>
#include "Ship.h"
#include <set>
#include <string.h>
#include <cmath>

/**
 * @brief Constructs a Ship object with bow and stern positions.
 *
 * Initializes the ship with the provided starting and ending
 * positions, defining its orientation and size.
 *
 * @param bow GridPosition representing the bow of the ship.
 * @param stern GridPosition representing the stern of the ship.
 */
Ship::Ship(const GridPosition &bow, const GridPosition &stern)
: bow(bow), stern(stern)
{
}

/**
 * @brief Destroys the Ship object.
 *
 * Virtual destructor allows safe inheritance and ensures
 * proper cleanup if extended in derived classes.
 */
Ship::~Ship() {
}

/**
 * @brief Checks whether the ship's placement is valid.
 *
 * A valid ship is placed either horizontally or vertically,
 * has positions within grid bounds, and a length between 2-5.
 *
 * @return True if the ship is valid, false otherwise.
 */
bool Ship::isValid() const{


	int len_ship = length();



	if(((bow.getRow() == stern.getRow()) ||
			(bow.getCoulumn() == stern.getCoulumn())) &&
			(bow.getCoulumn() > 0
					&& stern.getCoulumn() > 0)
					&& (len_ship >=2 && len_ship <= 5))
	{
		return true;
	}
	return false;
}

/**
 * @brief Returns the bow (start) position of the ship.
 *
 * Provides access to the ship's starting position on the grid.
 *
 * @return GridPosition of the bow.
 */
GridPosition Ship::getBow() const {

	return bow;

}

/**
 * @brief Returns the stern (end) position of the ship.
 *
 * Provides access to the ship's ending position on the grid.
 *
 * @return GridPosition of the stern.
 */
GridPosition Ship::getStern() const {

	return stern;
}

/**
 * @brief Computes the length of the ship.
 *
 * Calculates horizontal or vertical length based on bow and
 * stern coordinates, including both endpoints.
 *
 * @return Length of the ship as an integer.
 */
int Ship::length() const {

	if(bow.getRow() == stern.getRow())
	{
		int horizontal =  stern.getCoulumn() - bow.getCoulumn();
		if(horizontal < 0)
		{
			return horizontal*(-1) + 1;
		}
		else
		{
			return horizontal + 1;
		}
	}
	int vertical = bow.getRow() - stern.getRow();
	if(vertical < 0)
	{
		vertical = vertical * (-1);
		return vertical + 1;
	}
	return vertical + 1;
}

/**
 * @brief Returns all grid positions occupied by the ship.
 *
 * Computes a set of GridPosition objects covering every cell
 * that the ship occupies horizontally or vertically.
 *
 * @return Set of GridPosition objects representing occupied area.
 */
const std::set<GridPosition> Ship::occupiedArea() const{

	std::set<GridPosition> area; //local set area

	if(bow.getCoulumn() == stern.getCoulumn())
	{
		char startRow = std::min(bow.getRow(),stern.getRow());
		char endRow = std::max(bow.getRow(),stern.getRow());
		for(char row = startRow; row <= endRow; row++ )
		{
			area.insert(GridPosition(row,bow.getCoulumn()));
		}
	}
	else if(bow.getRow() == stern.getRow())
	{
		int startCol = std::min(bow.getCoulumn(),stern.getCoulumn());
		int endCol = std::max(bow.getCoulumn(),stern.getCoulumn());
		for(int col = startCol; col <= endCol; col++ )
		{
			area.insert(GridPosition(bow.getRow(),col));
		}
	}
	return area;


}

/**
 * @brief Computes the blocked area around the ship.
 *
 * Returns a set of positions that cannot be occupied by another
 * ship, typically all adjacent diagonal, vertical, and horizontal
 * positions around the ship.
 *
 * @return Set of GridPosition objects representing blocked area.
 */
const std::set<GridPosition> Ship::blockedArea() const {

	std::set<GridPosition> blockarea;

	std::set<GridPosition> shipOccupiedArea = occupiedArea();


	for(auto itr = shipOccupiedArea.begin();
			itr != shipOccupiedArea.end(); itr++)
	{
		GridPosition pos = *itr;

		for(int dr = -1; dr <= 1; dr++)
		{
			for(int dc = -1; dc <= 1; dc++)
			{

				char newrow = dr + pos.getRow();
				int newcol = dc + pos.getCoulumn();


				GridPosition pos2(newrow,newcol);
				if(pos2.isValid())
				{
					blockarea.insert(pos2);
				}
			}
		}
	}

	return blockarea;

}
