/**
 * @file OwnGrid.cpp
 * @author Akshith
 * @date 15-Dec-2025
 *
 * Implements the OwnGrid class, which stores the player's ships,
 * tracks hits and sunken ships, and provides console visualization
 * for the player's own board.
 */
#include<iostream>
#include "OwnGrid.h"
#include <set>
#include <string.h>
int NumberOfShips = 10;


/**
 * @brief Constructs an OwnGrid with specified dimensions.
 *
 * Initializes the grid with the given number of rows and columns
 * and prepares internal containers for ships and shot tracking.
 */
OwnGrid::OwnGrid(int rows, int columns) {
	// TODO Auto-generated constructor stub

	this->rows = rows;
	this->columns = columns;
}

/**
 * @brief Destroys the OwnGrid object.
 *
 * Explicit destructor is defined for completeness and potential
 * future extensions, though no dynamic resources are freed.
 */
OwnGrid::~OwnGrid() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief Row Returns a grid dimension.
 *
 * Provides the number of rows or columns of the player's own grid.
 * Both getters share the same documentation for consistency.
 */
int OwnGrid::getRows() {

	return rows;
}

/**
 * @brief Returns a grid dimension.
 *
 * Provides the number of rows or columns of the player's own grid.
 * Both getters share the same documentation for consistency.
 */
int OwnGrid::getColumns() {

	return columns;
}

/**
 * @brief Places a ship on the player's grid.
 *
 * Validates the ship's position, checks for overlaps, blocked areas,
 * and length limits before adding the ship to the internal container.
 *
 * @param ship Reference to the Ship object to be placed.
 * @return True if placement succeeds, false otherwise.
 */
bool OwnGrid::placeShip(const Ship &ship) {


	if(!ship.isValid())
	{
		//std::cout<<"Ship bow and stern positions "
			//	"are placed diagonally"<<std::endl;
		return false;
	}

	std::set<GridPosition> shipArea = ship.occupiedArea();
	for (const auto &pos : shipArea) {
		if (pos.getRow() < 'A' || pos.getRow() > 'A' + rows - 1 ||
				pos.getCoulumn() < 1 || pos.getCoulumn() > columns)
		{
			//std::cout<<"Index of ships are not valid"<<std::endl;
			return false;  // Out of grid
		}
	}

	// Fetching the blocked area

	std::set<GridPosition> newShipArea = ship.occupiedArea();

	for(const Ship &existingShip : ships)
	{
		std::set<GridPosition>
		blockedbyexisitingship = existingShip.blockedArea();
		for(const GridPosition& pos : newShipArea)
		{
			if(blockedbyexisitingship.find(pos) !=
					blockedbyexisitingship.end())
			{
				//std::cout << "New ship touches an existing ship
				//" << std::endl;
				return false;
			}
		}
	}

	for(Ship &existingShip : ships)
	{
		std::set<GridPosition> exisitngArea = existingShip.occupiedArea();
		for(const GridPosition &pos : shipArea)
		{
			if (exisitngArea.find(pos) != exisitngArea.end())
			{
				//std::cout<<"Overlaps on another ships"<<std::endl;
				return false;  // Overlaps another ship
			}
		}
	}

	static std::map<int, int> maxShipsByLength = {
			{5, 1},  // Carrier
			{4, 2},  // Battleship
			{3, 3},  // Destroyer
			{2, 4}   // Submarine
	};

	// Count ships already placed by length
	std::map<int, int> shipsCount;
	for (const Ship &existingShip : ships) {
		shipsCount[existingShip.length()]++;
	}

	int length = ship.length();
	if (maxShipsByLength.find(length) == maxShipsByLength.end()) {
		//std::cout << "Invalid ship length" << std::endl;
		return false;
	}
	if (shipsCount[length] >= maxShipsByLength[length]) {
		//std::cout << "Too many ships of length "
		//<< length << " allowed" << std::endl;
		return false;
	}

	ships.push_back(ship);
	return true;
}


/**
 * @brief Returns a list of all ships on the grid.
 *
 * Provides read-only access to the vector of ships owned by
 * the player.
 *
 * @return Vector of Ship objects.
 */
const std::vector<Ship> OwnGrid::getShips() const{

	return ships;
}

/**
 * @brief Processes a shot fired at the player's grid.
 *
 * Checks whether the shot hits, sinks, or misses a ship and
 * updates internal tracking accordingly.
 *
 * @param shot Reference to the fired Shot object.
 * @return Impact result: HIT, SUNKEN, or NONE.
 */
Shot::Impact OwnGrid::takeBlow(const Shot &shot) {



	for(const Ship &ship : ships)
	{
		std::set<GridPosition> shiparea = ship.occupiedArea();


		if(shiparea.find(shot.getTargetPosition())!=shiparea.end())
		{
			int count = 0;

			for(const GridPosition &pos : shiparea)
			{
				if(shotAt.find(pos)!=shotAt.end())
				{
					count++;
				}
			}

			if(count == ship.length() - 1)
			{
				shotAt.insert(std::make_pair(shot.getTargetPosition(),
						shot.Impact::SUNKEN));

				return Shot::Impact::SUNKEN;

			}
			else
			{
				shotAt.insert(std::make_pair(shot.getTargetPosition(),
						shot.Impact::HIT));

				return Shot::Impact::HIT;
			}
		}

	}
	shotAt.insert(std::make_pair(shot.getTargetPosition(),
			shot.Impact::None));

	return shot.Impact::None;

}

/**
 * @brief Returns all recorded shots on the grid.
 *
 * Provides a mapping from grid positions to shot impacts for
 * read-only access.
 *
 * @return Map of GridPosition to Shot::Impact.
 */
const std::map<GridPosition, Shot::Impact> OwnGrid::getShotAt() {

	return shotAt;
}
