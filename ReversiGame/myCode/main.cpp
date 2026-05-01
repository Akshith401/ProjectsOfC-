/*
 * ReversiConsoleView.h
 *
 *  Created on: 12-Nov-2025
 *      Author: akshi
 */

/**
 * @file main.cpp
 * @brief Entry point of the Reversi console game.
 *
 * Handles player turns, move validation, board updates,
 * optional game exit, and end-game winner calculation.
 */

// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>
#include "ReversiBoard.h"
#include "ReversiConsoleView.h"
#include <limits>
using namespace std;

/**
 * @brief Main function that runs the Reversi gameplay loop.
 *
 * Controls player input, validates moves, updates the board, switches turns,
 * and determines the winner when the board is filled or
 * when the user exits early.
 *
 * @return int Program exit status (0 = success).
 */
int main ()
{
    ReversiBoard Board1; ///< Main reversible board instance
    ReversiConsoleView disp(&Board1); ///< Console visualizer for the board

    int row = 0, col = 0; ///< Player-chosen coordinates
    int gameover = 0; ///< Counts successful moves to detect full board

    ReversiBoard::BoardState currentPlayer =
    		ReversiBoard::BoardState::PLAYER1; ///< Tracks the active player

    disp.print();

    // Main game loop continues until all board cells are filled
    while(gameover < 64)
    {
    	///< True when move is valid and turn should change
        bool switchPlayer = false;


        cout << "Player " << (currentPlayer ==
                ReversiBoard::PLAYER1 ? "1" : "2") << " Turn" << endl;

        cout<<"Enter the row and column for validation and set"<<endl;
        cin>>row>>col;

        // Check if input failed (non-numeric input)
            if(cin.fail()) {
                cin.clear(); // clear error flags
                // discard invalid input
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                cout << "Characters are not supported\n";
                cout << "Please enter numbers only. \n";
                continue; // ask again
            }

        /** @brief Validates the player's chosen
         *  cell before placing a piece. */
        if(Board1.validate(row,col,currentPlayer))
        {
            /** @brief Places the player's piece
             *  and flips necessary tiles. */
            Board1.setBoard(row,col,currentPlayer);

            /** @brief Increases total placed piece
             * count after each valid move. */
            gameover++;

            /** @brief Player successfully made a move,
             * so switch after printing. */
            switchPlayer = true;
        }

        disp.print();

        /** @brief Switches turn between Player 1 and Player 2
         *  after a legal move. */
        if(switchPlayer)
        {
            currentPlayer = (currentPlayer == ReversiBoard::PLAYER1)
                                    ? ReversiBoard::PLAYER2
                                    : ReversiBoard::PLAYER1;
        }
        else
        {
            /** @brief Invalid move → retry same player
             * without switching turn. */
            continue;
        }

        // -------------------------------------------------------------
        // EXIT OPTION (COMMENTED OUT IN ORIGINAL CODE)
        // -------------------------------------------------------------

        /**
         * @brief (Optional feature) Allows player to exit the game early.
         *
         * Although currently commented out, this block was intended to let
         * the player press '1' to exit mid-game.
         *
         * @code
         * int exitgame;
         * cout<<"Want to exit, press 1"<<endl;
         * cin >> exitgame;
         * if(exitgame == 1)
         * {
         *     cout<<"Game Exited..."<<endl;
         *     break;
         * }
         * @endcode
         *
         * These lines remain commented out but are
         * kept for future expansion.
         */
        // int exitgame;
        // cout<<"Want to exit, press 1"<<endl;
        // cin >> exitgame;
        // if(exitgame == 1)
        // {
        //     cout<<"Game Exited..."<<endl;
        //     break;
        // }

    }

    /** @brief Count tiles owned by both players to determine the winner. */
    int Player1Pieces =
    		Board1.countPieces(ReversiBoard::BoardState::PLAYER1);
    int Player2Pieces =
    		Board1.countPieces(ReversiBoard::BoardState::PLAYER2);

    /** @brief Compares piece totals and announces final game result. */
    if(Player1Pieces > Player2Pieces)
    {
        cout<<"Congratulations! Player 1 Won"<<endl;
    }
    else if(Player1Pieces < Player2Pieces)
    {
        cout<<"Congratulations! Player 2 Won"<<endl;
    }
    else if(Player1Pieces == Player2Pieces)
    {
        cout<<"Draw..!"<<endl;
    }
    else
    {
        // do nothing
    }

    return 0;
}
