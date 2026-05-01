/*
 * part2tests.cpp
 *
 *  Created on: 08-Jan-2026
 *      Author: akshi
 */



#include <iostream>


using namespace std;
#include "TestUtils.h"



void part2tests() {
	OwnGrid grid(10, 10);

	// ---------- VALID SHIP PLACEMENTS ----------

	// 1. Carrier (length 5, 1 allowed)
	assertTrue(
	    grid.placeShip(Ship(GridPosition{"B6"}, GridPosition{"B10"})),
	    "Carrier placement rejected"
	);

	// 2. Battleships (length 4, 2 allowed)
	// First Battleship
	assertTrue(
	    grid.placeShip(Ship(GridPosition{"D1"}, GridPosition{"G1"})),
	    "First Battleship placement rejected"
	);

	// Second Battleship
	assertTrue(
	    !grid.placeShip(Ship(GridPosition{"H2"}, GridPosition{"H5"})),
	    "Second Battleship placement rejected"
	);

	// 3. Destroyers (length 3, 3 allowed)
	// First Destroyer
	assertTrue(
	    grid.placeShip(Ship(GridPosition{"A1"}, GridPosition{"A3"})),
	    "First Destroyer placement rejected"
	);

	// Second Destroyer
	assertTrue(
	    !grid.placeShip(Ship(GridPosition{"C5"}, GridPosition{"E5"})),
	    "Second Destroyer placement rejected"
	);

	// Third Destroyer
	assertTrue(
	    grid.placeShip(Ship(GridPosition{"F7"}, GridPosition{"F9"})),
	    "Third Destroyer placement rejected"
	);

	// 4. Submarines (length 2, 4 allowed)
	// First Submarine
	assertTrue(
	    grid.placeShip(Ship(GridPosition{"J1"}, GridPosition{"J2"})),
	    "First Submarine placement rejected"
	);

	// Second Submarine
	assertTrue(
	    grid.placeShip(Ship(GridPosition{"H7"}, GridPosition{"H8"})),
	    "Second Submarine placement rejected"
	);

	// Third Submarine
	assertTrue(
	    !grid.placeShip(Ship(GridPosition{"D10"}, GridPosition{"E10"})),
	    "Third Submarine placement rejected"
	);

	// Fourth Submarine
	assertTrue(
	    !grid.placeShip(Ship(GridPosition{"A8"}, GridPosition{"B8"})),
	    "Fourth Submarine placement rejected"
	);

	// ---------- INVALID ATTEMPTS ----------

	// Placing a second Carrier → should fail
	assertTrue(
	    !grid.placeShip(Ship(GridPosition{"C6"}, GridPosition{"C10"})),
	    "Second Carrier allowed"
	);

	// Placing a third Battleship → should fail
	assertTrue(
	    !grid.placeShip(Ship(GridPosition{"F1"}, GridPosition{"I1"})),
	    "Third Battleship allowed"
	);

	// Placing a fourth Destroyer → should fail
	assertTrue(
	    !grid.placeShip(Ship(GridPosition{"G3"}, GridPosition{"I3"})),
	    "Fourth Destroyer allowed"
	);

	// Placing a fifth Submarine → should fail
	assertTrue(
	    grid.placeShip(Ship(GridPosition{"J5"}, GridPosition{"J6"})),
	    "Fifth Submarine allowed"
	);

	// Overlapping ship → should fail
	assertTrue(
	    !grid.placeShip(Ship(GridPosition{"B6"}, GridPosition{"B10"})),
	    "Overlapping ship allowed"
	);

	// Touching ship → should fail
	assertTrue(
	    !grid.placeShip(Ship(GridPosition{"A3"}, GridPosition{"A4"})),
	    "Touching ship allowed"
	);

	// Diagonal ship → should fail
	assertTrue(
	    !grid.placeShip(Ship(GridPosition{"C1"}, GridPosition{"E3"})),
	    "Diagonal ship allowed"
	);

	// Out-of-bounds → should fail
	assertTrue(
	    !grid.placeShip(Ship(GridPosition{"I9"}, GridPosition{"K9"})),
	    "Out-of-bounds ship allowed"
	);
}


