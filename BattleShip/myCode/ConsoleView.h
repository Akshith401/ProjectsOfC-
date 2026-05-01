/**
 * @file ConsoleView.h
 * @author Akshith
 * @date 15-Dec-2025
 *
 * Declares the ConsoleView class, which provides a console-based
 * representation of the current board state.
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_
#include "Board.h"

/**
 * @class ConsoleView
 *
 * Implements a simple view component responsible for displaying
 * the board contents using standard console output.
 */
class ConsoleView {

private:
	/**
	 * @brief Pointer to the board instance.
	 *
	 * Stores a reference to the board whose state is rendered by
	 * the ConsoleView component.
	 */
	Board* board;
public:
	/**
	 * @brief Constructs a ConsoleView object.
	 *
	 * Initializes the view with a pointer to the board that supplies
	 * the data to be displayed.
	 */
	ConsoleView(Board* board);
	/**
	 * @brief Destroys the ConsoleView object.
	 *
	 * The virtual destructor ensures safe cleanup when used through
	 * a base-class pointer.
	 */
	virtual ~ConsoleView();
	/**
	 * @brief Prints the board state to the console.
	 *
	 * Outputs the player's grid and the opponent's grid by delegating
	 * the rendering task to the board object.
	 */
	void printOwngrid();
	void printOpponentgrid();
	void print();

};

#endif /* CONSOLEVIEW_H_ */
