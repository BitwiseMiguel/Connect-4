#include "board.hpp"
#include "general.hpp"

constexpr auto ROWS_NUM{8}; // Number of rows (including the additional position)
constexpr auto COLS_NUM{9}; // Number of columns

Board::Board(const bool &thePlayer)
        : current_player(thePlayer), current_play(&play_history[0]) {};

#ifdef DEBUG
Board::Board(
    const uint128_t &theBoard, const uint128_t &thePlayerPieces, const bool theCurrentPlayer,
    const int *thePlayHistory, const int theActualPlay
) : board(theBoard), player_pieces(thePlayerPieces), current_player(theCurrentPlayer), 
    current_play(&play_history[theActualPlay]) {
    // Copy the play history to the current play
    std::copy(thePlayHistory, thePlayHistory + theActualPlay, play_history);
};

Board::Board(const Board &other)
    : board(other.board), player_pieces(other.player_pieces), 
    current_player(other.current_player), 
    current_play(play_history + (other.current_play - other.play_history)) {
    // Copy the play history to the current play
    std::copy(other.play_history, other.play_history + (other.current_play - other.play_history), play_history);
};
#endif

uint128_t Board::getBoard() const {
    return board;
}

uint128_t Board::getPlayerPieces() const {
    return player_pieces;
}

uint128_t Board::getOpponentPieces() const {
    return board ^ player_pieces;
}

bool Board::getCurrentPlayer() const {
    return current_player;
}

int Board::getNumberOfPlays() const {
    return current_play - play_history;
}

bool Board::isValidPosition(const int &column) const {
    #ifdef DEBUG
    // Check if the column is valid
    assertError(0 <= column, "Invalid column selection. The chosen column cannot be negative!");
    assertError(column < COLS_NUM, "Invalid column selection. The chosen column exceeds the maximum number of columns.");
    #endif
    
    return ((board >> ((column + 1) * ROWS_NUM - 2)) & 1ULL) == 0ULL;
}

void Board::playMove(const int &column) {
    #ifdef DEBUG
    assertError(isValidPosition(column) == true, "Invalid column selection. The chosen column does not belong to the valid positions.");
    #endif

    // Toggle the player's pieces
    player_pieces ^= board;

    // Add the current player's piece to the specified column
    board |= (board + ((uint128_t)1ULL << (ROWS_NUM * column)));

    // Switch to the next player's turn
    current_player = !current_player;

    // Store the played column in the play history
    *current_play = column;

    // Move to the next position in the play history
    current_play++;
}

void Board::undoLastMove() {
    #ifdef DEBUG
    // Check if there are any moves recorded before attempting to undo a move
    assertError(getNumberOfPlays() != 0, "Unable to undo move because there are no recorded moves.");
    #endif

    // Decrement the current play pointer
    current_play--;

    // Start at the top row of the specified column
    auto row = ROWS_NUM - 1;

    // Find the highest occupied row in the specified column
    while (((board >> (ROWS_NUM * (*current_play) + row)) & 1ULL) == 0ULL) {
        row--;
    }

    // Remove the piece from the specified column and row
    board ^= (uint128_t)1ULL << (ROWS_NUM * (*current_play) + row);

    // Toggle the player's pieces
    player_pieces ^= board;

    // Switch to the next player's turn
    current_player = !current_player;
}

bool Board::checkLastPlayerWin() const {
    const auto last_player_pieces{getOpponentPieces()};
    uint128_t checker; // Variable used for checking winning conditions

    // Horizontal check
    checker = last_player_pieces & (last_player_pieces >> ROWS_NUM);
    checker &= checker >> (2 * ROWS_NUM);
    if (checker != 0ULL) return true; // Current player has a winning horizontal line

    // Diagonal (\) check
    checker = last_player_pieces & (last_player_pieces >> (ROWS_NUM - 1));
    checker &= checker >> (2 * (ROWS_NUM - 1));
    if (checker != 0ULL) return true; // Current player has a winning diagonal (\) line

    // Diagonal (/) check
    checker = last_player_pieces & (last_player_pieces >> (ROWS_NUM + 1));
    checker &= checker >> (2 * (ROWS_NUM + 1));
    if (checker != 0ULL) return true; // Current player has a winning diagonal (/) line

    // Vertical check
    checker = last_player_pieces & (last_player_pieces >> 1);
    checker &= checker >> 2;
    if (checker != 0ULL) return true; // Current player has a winning vertical line
    
    // If no winning condition is found
    return false;
}

bool Board::checkFinishDraw() const {
    static const uint128_t FULLBOARD{127ULL, 9187201950435737471ULL};
    return board == FULLBOARD;
}

int Board::getValidPositions() const {
    auto mask{0};
    for (int column{0}; column < COLS_NUM; column++) { // Iterate over each column
        if (isValidPosition(column)) { // If the column is valid
            mask |= 1 << column; // Set the corresponding bit in the mask
        }
    }

    // Return the mask indicating valid positions
    return mask; 
};

int Board::getWinningPositions() {
    auto mask{0};
    for (int column{0}; column < COLS_NUM; column++) { // Iterate over each column
        if (!isValidPosition(column)) continue;

        playMove(column);
        if (checkLastPlayerWin()) {
            // Set the corresponding bit in the mask
            mask |= 1 << column;
        }
        undoLastMove();
    }

    // Return the mask indicating valid positions
    return mask; 
};

uint128_t Board::getBoardKey() const {
    static const uint128_t BOTTOMLINE{1ULL, 72340172838076673ULL};
    // Return the sum of the 'BOTTOMLINE', 'board' and 'player_pieces' as the board key
    return BOTTOMLINE + board + player_pieces;
};


auto Board::getColumn(const uint128_t &key, const int column) const {
    #ifdef DEBUG
    // Check if the column is valid
    assertError(0 <= column, "Invalid column selection. The chosen column cannot be negative!");
    assertError(column < COLS_NUM, "Invalid column selection. The chosen column exceeds the maximum number of columns.");
    #endif
    static const auto FULLCOLUMN{255ULL};

    return (uint64_t)(key >> (column * ROWS_NUM)) & FULLCOLUMN;
}

auto Board::calculateSymmetricKey() const {
    #ifdef DEBUG
    // Check if the assumption (COLS_NUM - 1) * ROWS_NUM = 64 holds true
    assertError((COLS_NUM - 1) * ROWS_NUM == 64, "The calculateSymmetricKey function's implementation assumes that (COLS_NUM - 1) * ROWS_NUM = 64. If this condition is not met, please refactor the implementation.");
    #endif

    const auto board_key = getBoardKey();

    uint128_t symetric_key{getColumn(board_key, 0), 0ULL};

    for (int column{1}; column < COLS_NUM; column++) { // Iterate over each column
        symetric_key |= getColumn(board_key, column) << ((COLS_NUM - column - 1) * ROWS_NUM);
    }

    return symetric_key;
}

bool Board::isBoardSymmetrical() const {
    // Get the key of the current board
    const auto board_key = getBoardKey();

    // Calculate the symmetric key for the board
    const auto symmetric_key = calculateSymmetricKey();

    // Check if the symmetric key is equal to the original board key
    return board_key == symmetric_key;
};

