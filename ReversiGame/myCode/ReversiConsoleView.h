/*
 * ReversiConsoleView.h
 *
 *  Created on: 12-Nov-2025
 *      Author: akshi
 */

/**
 * @file ReversiConsoleView.h
 * @brief Declares the ReversiConsoleView class
 * for console-based board display.
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_

#include "ReversiBoard.h"

/**
 * @class ReversiConsoleView
 * @brief Handles printing the Reversi game board to the console.
 *
 * This class takes a pointer to a ReversiBoard object and prints the current
 * board state in a readable format. Player 1 pieces are shown as 'B',
 * Player 2 pieces as 'W', and empty cells as '.'.
 */
class ReversiConsoleView {

private:
    /// Pointer to the ReversiBoard to display
    ReversiBoard *board;

public:
    /**
     * @brief Constructor initializes the view with a board pointer.
     * @param b Pointer to a ReversiBoard instance
     */
    ReversiConsoleView(ReversiBoard *b);

    /**
     * @brief Destructor for the console view.
     */
    virtual ~ReversiConsoleView();

    /**
     * @brief Prints the current board to the console.
     *
     * Displays row and column numbers for reference, Player 1 pieces as 'B',
     * Player 2 pieces as 'W', and empty cells as '.'.
     */
    void print() const;
};

#endif /* REVERSICONSOLEVIEW_H_ */
