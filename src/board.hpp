#ifndef BOARD_HPP
#define BOARD_HPP

#include "../external/libs/uint128_API.hpp"

/**
 * @class Board
 * A class representing a game board.
 * The board is a rectangular structure with 7 rows and 9 columns, resulting in a total of 63 single positions. However, 
 * to efficiently represent the state of the board, we have chosen to use a single 128-bit integer to store the information.
 * In each column of the board, we include an additional position that aids in specific calculations. This extra position is
 * not visible on the game board itself, but it is used internally to simplify operations and calculations. As a result, we
 * require 72 bits to store all the necessary board information.
 * The `uint128_t` data type is a 128-bit unsigned integer that can accommodate all possible combinations of the board. The
 * `board` variable is used to store the current state of the board.
 * This streamlined representation of the board as a single 128-bit integer enables faster and more efficient mathematical and
 * logical operations during the game. It also facilitates the implementation of functions and algorithms related to the board.
 * Overall, this approach optimizes the storage and processing of the game board, resulting in improved performance and ease of
 * development.
 */
class Board {
private:
    uint128_t board; // The game board represented as a 128-bit unsigned integer
    uint128_t player_pieces; // The current player pieces in the board
    bool current_player; // The current player (true for player 1, false for player 2)
    int play_history[63]; // Array to store the play history (up to 63 moves)
    int *current_play; // Pointer to the current play in the play history

public:
    /**
     * @brief Constructor.
     * Initializes a new instance of the Board class.
     * @param thePlayer The current player. Default value is true.
     */
    Board(const bool &thePlayer = true);

    #ifdef DEBUG
    /**
     * @brief Constructor.
     * Initializes a new instance of the Board class.
     * Only for debugging purposes.
     * @param theBoard The board state.
     * @param thePlayerPieces The player's pieces.
     * @param theCurrentPlayer The current player.
     * @param thePlayHistory The play history.
     * @param theActualPlay The number of plays in the play history.
     */
    Board(
        const uint128_t &theBoard, 
        const uint128_t &thePlayerPieces, 
        const bool theCurrentPlayer, 
        const int *thePlayHistory, 
        const int theActualPlay
    );

    /**
     * @brief Copy constructor.
     * Creates a new instance of the Board class from an existing instance.
     * Only for debugging purposes.
     * @param other The other Board instance to copy from.
     */
    Board(const Board &other);
    #endif

    /**
     * @brief Get the game board.
     * @return The game board as a 128-bit unsigned integer.
     */
    uint128_t getBoard() const;

    /**
     * @brief Get the actual player's pieces.
     * @return The actual player's pieces as a 128-bit unsigned integer.
     */
    uint128_t getPlayerPieces() const;

    /**
     * @brief Get the opponent player's pieces.
     * @return The opponent player's pieces as a 128-bit unsigned integer.
     */
    uint128_t getOpponentPieces() const;

    /**
     * @brief Get the current player.
     * @return The current player (true for player 1, false for player 2).
     */
    bool getCurrentPlayer() const;

    #ifdef DEBUG
    /**
     * @brief Get the play at the specified index in the play history.
     * Only for debugging purposes.
     * @param play_index The index of the play in the play history.
     * @return The play at the specified index.
     */
    auto getPlayHistory(const int play_index) const {return play_history[play_index];}

    /**
     * @brief Get the current play in the play history.
     * Only for debugging purposes.
     * @return The current play.
     */
    auto getCurrentPlay() const {return current_play;}
    #endif

    /**
     * @brief Get the number of moves made.
     * @return The number of moves made.
     */
    int getNumberOfPlays() const;

    /**
     * @brief Check if a given column is a valid position.
     * @param column The column to check.
     * @return True if the column is a valid position, false otherwise.
     */
    bool isValidPosition(const int &column) const;

    /**
     * @brief Play a move in the specified column.
     * @param column The column to play the move in.
     */
    void playMove(const int &column);

    /**
     * @brief Undo the last move played.
     */
    void undoLastMove();

    /**
     * @brief Check if the last player is the winner.
     * @return True if the last player is the winner, false otherwise.
     */
    bool checkLastPlayerWin() const;

    /**
     * @brief Check if the game finish as a draw.
     * @return True if the game finish as a draw, false otherwise.
     */
    bool checkFinishDraw() const;

    /**
     * @brief Get a bitmask of valid positions on the board.
     * @return The bitmask of valid positions on the board.
     */
    int getValidPositions() const;

    /**
     * @brief Get a bitmask of winning positions on the board.
     * @return The bitmask of winning positions on the board.
     */
    int getWinningPositions();

    /**
     * @brief Get a unique key for the current state of the game board.
     * @return The unique key for the current game board state.
     */
    uint128_t getBoardKey() const;

    /**
     * @brief Retrieves the column at the specified index.
     * @param column The index of the column to retrieve.
     * @return The column represented as a 64-bit unsigned integer.
     */
    auto getColumn(const uint128_t &key, const int column) const;

    /**
     * @brief Calculates the symmetric key for the current board state.
     * This function calculates and returns the symmetric key for the current board state.
     * The symmetric key is a 128-bit unsigned integer.
     * @return The symmetric key for the current board state.
     */
    auto calculateSymmetricKey() const;

    /**
     * @brief Check if the board is symmetrical.
     * @return True if the board is symmetrical, false otherwise.
     */
    bool isBoardSymmetrical() const;

};

#endif
