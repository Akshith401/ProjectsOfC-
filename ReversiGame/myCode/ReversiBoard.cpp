/*
 * ReversiBoard.cpp
 *
 *  Created on: 12-Nov-2025
 *      Author: akshi
 */

/**
 * @file ReversiBoard.cpp
 * @brief Implements the logic for validating moves, updating the board,
 * flipping opponent pieces, and counting pieces in the Reversi game.
 */

// Standard (system) header files
#include <iostream>
#include <cstdlib>
#include "ReversiBoard.h"
using namespace std;

/**
 * @brief Constructor initializes the board with the standard Reversi
 * starting pattern of four pieces in the center.
 */
ReversiBoard::ReversiBoard() {
	// TODO Auto-generated constructor stub

	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			/** @brief Setup of standard initial 4-piece configuration. */
			if(i == 3 && j ==3)
			{
				Board[3][3] = BoardState::PLAYER1;
			}
			else if(i == 3 && j == 4)
			{
				Board[3][4] = BoardState::PLAYER2;
			}
			else if(i == 4 && j == 3)
			{
				Board[4][3] = BoardState::PLAYER2;
			}
			else if(i == 4 && j == 4)
			{
				Board[4][4] = BoardState::PLAYER1;
			}
			else
			{
				///< Empty cell initialization
				Board[i][j] = BoardState::EMPTY;
			}
		}
	}
}

/**
 * @brief Destructor for ReversiBoard.
 */
ReversiBoard::~ReversiBoard() {
/**
 * @breif here reversiboad is not using any dynamic memory
 * so, not needed to delete the memory since it already allocated but not on
 * heap memory.
 *
 */
}

/**
 * @brief Validates a move by checking directionally whether placing a piece
 * results in capturing at least one opponent piece.
 *
 * @param row Row position entered by the player (1–8)
 * @param col Column position entered by the player (1–8)
 * @param currentPlayer Player attempting the move
 * @return true if the move is valid in any direction, else false
 */
bool ReversiBoard::validate(int row, int col, BoardState currentPlayer)
{
	/** @brief Convert user-friendly input to 0-based indexing. */
	row -= 1;
	col -= 1;

	/** @brief Determine which player is the opponent. */
	BoardState opponentPlayer =
			(currentPlayer == ReversiBoard::BoardState::PLAYER1)
			? ReversiBoard::BoardState::PLAYER2
					: ReversiBoard::BoardState::PLAYER1;

	/** @brief Movement vectors for scanning 8 directions. */
	int drow[8] = {-1,1,0,0,-1,-1,1,1};
	int dcol[8] = {0,0,-1,1,-1,1,-1,1};

	/** @brief Reject move if outside the 8×8 board. */
	if (row < 0 || row >= 8 || col < 0 || col >= 8)
	{
		cout << "Not Valid Move!!" << endl;
		cout << "Reason: Boundary Limit Exceeded" << endl;
		return false;
	}

	/** @brief Reject move if cell is not empty. */
	if (Board[row][col] != ReversiBoard::BoardState::EMPTY)
	{
		cout << "Not Valid Move!!" << endl;
		cout << "Reason: Already Occupied by another Player" << endl;
		return false;
	}

	bool anyValidDirection = false; ///< Tracks if flipping is possible

	/** @brief Check all 8 directions for valid flipping. */
	for (int d = 0; d < 8; d++)
	{
		int dr = drow[d];
		int dc = dcol[d];

		int newrow = row + dr;
		int newcol = col + dc;

		/** @brief Must begin with an opponent piece to be valid. */
		if (newrow < 0 || newrow >= 8 || newcol < 0 || newcol >= 8)
			continue;
		if (Board[newrow][newcol] != opponentPlayer)
			continue;

		/** @brief Move forward to check if a closing piece exists. */
		newrow += dr;
		newcol += dc;

		while (newrow >= 0 && newrow < 8 && newcol >= 0 && newcol < 8)
		{
			if (Board[newrow][newcol] == opponentPlayer)
			{
				/** @brief Continue scanning over opponent pieces. */
				newrow += dr;
				newcol += dc;
			}
			else if (Board[newrow][newcol] == currentPlayer)
			{
				/** @brief Closing piece found — valid direction. */
				anyValidDirection = true;
				break;
			}
			else
			{
				/** @brief Empty cell blocks flipping. */
				break;
			}
		}
	}

	/** @brief Print result of validation. */
	if (anyValidDirection)
	{
		cout << "Valid Position" << endl;
		return true;
	}
	else
	{
		cout << "Invalid Position" << endl;
		cout << "Reason: No opponent pieces captured in any direction."
				<< endl;
		return false;
	}
}

/**
 * @brief Applies a valid move:
 * places the player's piece and flips any opponent
 * pieces in valid directions until a same-color piece is reached.
 *
 * @param row Row position (1–8)
 * @param col Column position (1–8)
 * @param currentPlayer Player making the move
 */
void ReversiBoard::setBoard(int row, int col, BoardState currentPlayer)
{
	/** @brief Proceed only if the position is validated. */
	if(ReversiBoard::validate(row, col, currentPlayer))
	{
		row -= 1;
		col -= 1;

		/** @brief Determine opponent of the current player. */
		BoardState opponentPlayer =
				(currentPlayer == ReversiBoard::BoardState::PLAYER1)
				? ReversiBoard::BoardState::PLAYER2
						: ReversiBoard::BoardState::PLAYER1;

		/** @brief Direction vectors for flipping. */
		int drow[8] = {-1,1,0,0,-1,-1,1,1};
		int dcol[8] = {0,0,-1,1,-1,1,-1,1};

		bool anyFlipped = false;

		/** @brief Try flipping pieces in all 8 directions. */
		for(int d = 0; d < 8; d++)
		{
			int dr = drow[d];
			int dc = dcol[d];

			int newrow = row + dr;
			int newcol = col + dc;

			/** @brief Skip directions without an adjacent opponent piece. */
			if (newrow < 0 || newrow >= 8 || newcol < 0 || newcol >= 8)
				continue;

			if (Board[newrow][newcol] != opponentPlayer)
				continue;

			/** @brief Continue scanning until flip condition is met. */
			while (newrow >= 0 && newrow < 8 && newcol >= 0 && newcol < 8)
			{
				if(Board[newrow][newcol] == currentPlayer)
				{
					/** @brief Flip opponent pieces backward toward origin. */
					int r = row + dr;
					int c = col + dc;

					while (r != newrow || c != newcol)
					{
						Board[r][c] = currentPlayer;
						r += dr;
						c += dc;
					}
					anyFlipped = true;
					break;
				}
				else if(Board[newrow][newcol] == opponentPlayer)
				{
					/** @brief Continue if still meeting opponent pieces. */
					newrow += dr;
					newcol += dc;
				}
				else
				{
					/** @brief Empty cell stops flipping. */
					break;
				}
			}
		}

		/** @brief Place player's piece only if valid flips occurred. */
		if(anyFlipped)
		{
			Board[row][col] = currentPlayer;
		}
	}
	else
	{
		cout << "Not a valid position to flip" << endl;
	}
}

/**
 * @brief Returns the board state
 * (EMPTY, PLAYER1, PLAYER2) at a given position.
 *
 * @param row Row index (0–7)
 * @param col Column index (0–7)
 * @return BoardState The state of the requested cell
 */
ReversiBoard::BoardState ReversiBoard::getBoardState(int row, int col)
{
	return Board[row][col];
}

/**
 * @brief Counts how many pieces of a given type exist on the board.
 *
 * @param piece The piece type (PLAYER1 or PLAYER2)
 * @return int Number of pieces belonging to the specified player
 */
int ReversiBoard::countPieces(BoardState piece) {
	int count = 0;

	/** @brief Loop through entire 8×8 board. */
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {

			/** @brief Increase count when matching piece is found. */
			if (Board[row][col] == piece) {
				count++;
			}
		}
	}
	return count;
}
