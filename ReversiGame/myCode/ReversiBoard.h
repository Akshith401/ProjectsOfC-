/*
 * ReversiBoard.h
 *
 *  Created on: 12-Nov-2025
 *      Author: akshi
 */

/**
 * @file ReversiBoard.h
 * @brief Defines the ReversiBoard class for managing the game board,
 *  validating moves,
 * updating pieces, and counting player pieces.
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

/**
 * @class ReversiBoard
 * @brief Handles the internal logic and state of the Reversi game board.
 *
 * This class provides methods to validate moves, place pieces, flip opponent
 * pieces, query board states, and count pieces for each player.
 */
class ReversiBoard {

public:

    /// Enum representing the state of each board cell
    typedef enum {
        EMPTY,   ///< Cell is empty
        PLAYER1, ///< Cell occupied by Player 1
        PLAYER2  ///< Cell occupied by Player 2
    } BoardState;

    /// Constructor initializes the board with starting 4-piece pattern
    ReversiBoard();

    /// Destructor
    virtual ~ReversiBoard();

    /**
     * @brief Checks if placing a piece at
     * (row, col) is valid for the current player.
     * @param row Row number (1–8) where the player wants to place a piece
     * @param col Column number (1–8) where the player wants to place a piece
     * @param currentPlayer The player attempting the move
     * (PLAYER1 or PLAYER2)
     * @return true if the move is valid
     * (captures at least one opponent piece)
     * @return false if the move is invalid
     */
    bool validate(int row, int col, BoardState currentPlayer);

    /**
     * @brief Places a piece for the
     * current player at (row, col) and flips opponent pieces.
     * Only executes if the move is valid.
     * @param row Row number (1–8)
     * @param col Column number (1–8)
     * @param currentPlayer The player making the move
     */
    void setBoard(int row, int col, BoardState currentPlayer);

    /**
     * @brief Returns the state of a specific cell on the board.
     * @param row Row index (0–7)
     * @param col Column index (0–7)
     * @return BoardState State of the cell (EMPTY, PLAYER1, or PLAYER2)
     */
    BoardState getBoardState(int row, int col);

    /// The fixed size of the board (8x8)
    static const int SIZE = 8;

    /**
     * @brief Counts the number of pieces belonging to a specific player.
     * @param piece The player to count pieces for (PLAYER1 or PLAYER2)
     * @return int Total number of pieces of that player on the board
     */
    int countPieces(BoardState piece);

private:

    /// 2D array representing the board state
    BoardState Board[SIZE][SIZE];
};

#endif /* REVERSIBOARD_H_ */
