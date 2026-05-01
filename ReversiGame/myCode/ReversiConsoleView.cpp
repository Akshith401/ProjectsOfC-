/*
 * ReversiConsoleView.cpp
 *
 *  Created on: 12-Nov-2025
 *      Author: akshi
 */

/**
 * @file ReversiConsoleView.cpp
 * @brief Implements console-based visualization for the Reversi game board.
 */

#include "ReversiBoard.h"
#include "ReversiConsoleView.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/**
 * @brief Constructor that sets the board pointer for display.
 * @param b Pointer to the ReversiBoard instance
 */
ReversiConsoleView::ReversiConsoleView(ReversiBoard *b) {
	board = b;
}

/**
 * @brief Destructor for ReversiConsoleView.
 */
ReversiConsoleView::~ReversiConsoleView() {
/**
 * @breif here reversiboad is not using any dynamic memory
 * so, not needed to delete the memory since it already allocated but not on
 * heap memory.
 */
}

/**
 * @brief Prints the current state of the board to the console.
 *
 * Empty cells are displayed as '.', Player 1 pieces as 'B', and
 * Player 2 pieces as 'W'. Also prints row and column numbers for reference.
 */
void ReversiConsoleView::print() const {

	cout << endl;

	/** @brief Print column numbers 1 to 8 */
	for(int k = 1; k <= 8; k++)
	{
		cout << "  " << k;
	}
	cout << endl;

	/** @brief Print each row of the board */
	for(int i = 0; i < ReversiBoard::SIZE; i++)
	{
		cout << i + 1; ///< Row number

		/** @brief Print each cell in the row */
		for(int j = 0; j < ReversiBoard::SIZE; j++)
		{
			ReversiBoard::BoardState state = board->getBoardState(i, j);

			/** @brief Display
			 * '.' for empty, 'B' for Player1, 'W' for Player2 */
			if(state == ReversiBoard::EMPTY)
			{
				cout << " . ";
			}
			else if(state == ReversiBoard::PLAYER1)
			{
				cout << " B ";
			}
			else if(state == ReversiBoard::PLAYER2)
			{
				cout << " W ";
			}
		}

		cout << endl; ///< Move to next row
	}
}
