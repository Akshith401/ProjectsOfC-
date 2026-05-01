/*
 * part3tests.cpp
 *
 *  Created on: 08-Jan-2026
 *      Author: akshi
 */




#include <iostream>

using namespace std;

#include "TestUtils.h"

#include "TestUtils.h"      // for assertTrue
#include "GridPosition.h"   // for GridPosition
#include "Ship.h"           // if Ship is used
#include "OwnGrid.h"        // for OwnGrid
#include "Shot.h"           // for Shot



void part3tests() {
	OwnGrid myGrid(10, 10);

	// ---------- PLACE FIRST SHIP ----------
	Ship ship1(GridPosition{"B2"}, GridPosition{"B4"});
	assertTrue(myGrid.placeShip(ship1), "Failed to place ship1");

	// ---------- SHOOTING TESTS ----------

	// Shoot at empty cell -> MISS
	Shot missShot(GridPosition{"A1"});
	assertTrue(myGrid.takeBlow(missShot) == Shot::Impact::None,
	           "Missed shot incorrectly reported");

	// Shoot at ship -> HIT
	Shot hitShot1(GridPosition{"B2"});
	assertTrue(myGrid.takeBlow(hitShot1) == Shot::Impact::HIT,
	           "Hit not detected");

	// Shoot remaining ship cells -> HIT then SUNKEN
	Shot hitShot2(GridPosition{"B3"});
	assertTrue(myGrid.takeBlow(hitShot2) == Shot::Impact::HIT,
	           "Hit not detected");

	Shot hitShot3(GridPosition{"B4"});
	assertTrue(myGrid.takeBlow(hitShot3) == Shot::Impact::SUNKEN,
	           "Ship not sunk correctly");

	// Shoot the same cell again -> should return same impact
	Shot repeatShot(GridPosition{"B2"});
	assertTrue(myGrid.takeBlow(repeatShot) == Shot::Impact::HIT,
	           "Repeating shot on same cell did not return correct impact");

	// Shoot out-of-bounds -> should handle gracefully
	Shot outOfBoundsShot(GridPosition{"Z1"});
	assertTrue(myGrid.takeBlow(outOfBoundsShot) == Shot::Impact::None,
	           "Out-of-bounds shot incorrectly reported");

	// ---------- PLACE SECOND SHIP ----------
	Ship ship2(GridPosition{"E5"}, GridPosition{"G5"});
	assertTrue(myGrid.placeShip(ship2), "Failed to place second ship");

	// Shoot all cells of second ship -> HIT then SUNKEN
	assertTrue(myGrid.takeBlow(Shot(GridPosition{"E5"})) ==
			Shot::Impact::HIT,
	           "Hit on second ship not detected");
	assertTrue(myGrid.takeBlow(Shot(GridPosition{"F5"})) ==
			Shot::Impact::HIT,
	           "Hit on second ship not detected");
	assertTrue(myGrid.takeBlow(Shot(GridPosition{"G5"})) ==
			Shot::Impact::SUNKEN,
	           "Second ship not sunk correctly");

	// ---------- OPPONENT GRID TRACKING ----------
	OpponentGrid oppGrid(10, 10);
	oppGrid.shotResult(Shot(GridPosition{"C1"}), Shot::Impact::None);
	oppGrid.shotResult(Shot(GridPosition{"D2"}), Shot::Impact::HIT);

	assertTrue(oppGrid.getShotsAt().size() == 2,
	           "Opponent shots not tracked");

}

