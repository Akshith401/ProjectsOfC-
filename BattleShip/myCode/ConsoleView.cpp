/**
 * @file ConsoleView.cpp
 * @author Akshith
 * @date 15-Dec-2025
 *
 * Implements the ConsoleView class, which is responsible for
 * presenting the current state of the board using console output.
 */

#include "ConsoleView.h"

int oppsunkCount = 0;
int mysunkCount = 0;

/**
 * @brief Constructs a ConsoleView object.
 *
 * Stores a pointer to the board instance that provides the data
 * required for rendering the board state on the console.
 */

ConsoleView::ConsoleView(Board *board) {

	this->board = board;
}

/**
 * @brief Destroys the ConsoleView object.
 *
 * The destructor is defined explicitly for completeness and future
 * extensions, although no resources are released at present.
 */

ConsoleView::~ConsoleView() {
}
/**
 * @brief Prints the player's own grid.
 *
 * Displays the positions of all ships, and shows impacts of
 * opponent shots as HIT, SUNKEN, or NONE.
 */
void ConsoleView::printOwngrid() {

    OwnGrid& ownGrid = board->getOwnGrid();

    std::map<GridPosition, Shot::Impact> shipImpact = ownGrid.getShotAt();

    std::set<GridPosition> occupiedAll;
    for (const Ship& ship : ownGrid.getShips()) {
        std::set<GridPosition> shipArea = ship.occupiedArea();
        occupiedAll.insert(shipArea.begin(), shipArea.end());
    }

    std::set<GridPosition> blockedAreaByShips;
    for (const Ship& ship : ownGrid.getShips()) {
        std::set<GridPosition> blockArea = ship.blockedArea();
        blockedAreaByShips.insert(blockArea.begin(), blockArea.end());
    }

    // Column numbers
    for (int k = 1; k <= ownGrid.getColumns(); k++) {
        std::cout << "  " << k;
    }
    std::cout << std::endl;

    // Grid rows
    for (int row = 1; row <= ownGrid.getRows(); row++) {
        std::cout << char('A' + row - 1) << "  ";

        for (int col = 1; col <= ownGrid.getColumns(); col++) {

            GridPosition pos(char('A' + row - 1), col);

            auto impact = shipImpact.find(pos);
            if (impact != shipImpact.end()) {

                if (impact->second == Shot::Impact::HIT) {
                    std::cout << "O  ";
                }
                else if (impact->second == Shot::Impact::SUNKEN) {
                    std::cout << "S  ";
                    mysunkCount++;
                }
                else if (impact->second == Shot::Impact::None) {
                    std::cout << "^  ";
                }
            }
            else if (occupiedAll.find(pos) != occupiedAll.end()) {
                std::cout << "#  ";
            }
            else {
                std::cout << "~  ";
            }
        }
        std::cout << std::endl;
    }
}
/**
 * @brief Prints the player's opponent grid.
 *
 * Displays the positions of all ships, and shows impacts of
 * opponent shots as HIT, SUNKEN, or NONE.
 */
void ConsoleView::printOpponentgrid() {

    OpponentGrid& opponentGrid = board->getOpponentGrid();
    std::map<GridPosition, Shot::Impact> result = opponentGrid.getShotsAt();

    // Column numbers
    for (int k = 1; k <= opponentGrid.getColumns(); k++) {
        std::cout << "  " << k;
    }
    std::cout << std::endl;

    // Grid rows
    for (int row = 1; row <= opponentGrid.getRows(); row++) {
        std::cout << char('A' + row - 1) << "  ";

        for (int col = 1; col <= opponentGrid.getColumns(); col++) {

            GridPosition pos(char('A' + row - 1), col);

            auto it = result.find(pos);
            if (it != result.end()) {

                if (it->second == Shot::Impact::HIT) {
                    std::cout << "O  ";
                }
                else if (it->second == Shot::Impact::SUNKEN) {
                    std::cout << "S  ";
                    oppsunkCount++;
                }
                else { // MISS / NONE
                    std::cout << "^  ";
                }
            }
            else {
                std::cout << "~  ";
            }
        }
        std::cout << std::endl;
    }
}
/**
 * @brief Prints the board state to the console.
 *
 * The method outputs both the player's grid and the opponent's grid
 * by delegating the printing operation to the respective grid objects.
 */

void ConsoleView::print() {


	printOwngrid();
	printOpponentgrid();

}
