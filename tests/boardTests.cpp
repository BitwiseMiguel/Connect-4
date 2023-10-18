#include "testFunctions.hpp"
#include "../runTests.hpp"
#include "../src/board.hpp"

void runBoardTests() {

    std::cout << ansi::foreground_yellow << "BOARD TESTS" << ansi::reset << std::endl;
    
    { // Constructor Test 1

        Board game;

        uint128_t zero;

        EQ_TEST((std::vector<uint128_t>){game.getBoard(), game.getPlayerPieces(), game.getCurrentPlayer()},
            (std::vector<uint128_t>){zero, zero, true}, "Constructor Test 1");
    }

    { // Constructor Test 2

        Board game{false};

        uint128_t zero;

        EQ_TEST((std::vector<uint128_t>){game.getBoard(), game.getPlayerPieces(), game.getCurrentPlayer()},
            (std::vector<uint128_t>){zero, zero, false}, "Constructor Test 2");
    }

    { // Constructor Test 3

        uint128_t board{256ULL, 216176110713504000ULL};
        uint128_t player{0ULL, 144116309062385664ULL};

        int play[63] {4, 4, 5, 9, 2, 7, 7, 5, 4, 1};

        Board game{board, player, false, play, 10};

        EQ_TEST((std::vector<uint128_t>){game.getBoard(), game.getPlayerPieces(), game.getOpponentPieces(), game.getCurrentPlayer(),
                (uint128_t)game.getPlayHistory(3), (uint128_t)game.getPlayHistory(7), (uint128_t)*(game.getCurrentPlay() - 1)},
            (std::vector<uint128_t>){board, player, board ^ player, false, (uint128_t)play[3], (uint128_t)play[7], (uint128_t)play[9]}, 
           "Constructor Test 3");
    }

    { // Constructor Test 4

        uint128_t board{256ULL, 216176110713504000ULL};
        uint128_t player{0ULL, 144116309062385664ULL};

        int play[63] {4, 4, 5, 9, 2, 7, 7, 5, 4, 1};

        Board first_game{board, player, false, play, 10};

        Board game{first_game};

        EQ_TEST((std::vector<uint128_t>){game.getBoard(), game.getPlayerPieces(), game.getOpponentPieces(), game.getCurrentPlayer(),
                (uint128_t)game.getPlayHistory(3), (uint128_t)game.getPlayHistory(7), (uint128_t)*(game.getCurrentPlay() - 1)},
            (std::vector<uint128_t>){board, player, board ^ player, false, (uint128_t)play[3], (uint128_t)play[7], (uint128_t)play[9]}, 
           "Constructor Test 4");
    }

    { // Function getNumberOfPlays Test 1

        Board game;

        EQ_TEST(game.getNumberOfPlays(), 0, "Function getNumberOfPlays Test 1");
    }

    { // Function getNumberOfPlays Test 2

        uint128_t board{256ULL, 216176110713504000ULL};
        uint128_t player{0ULL, 144116309062385664ULL};

        int play[63] {4, 4, 5, 9, 2, 7, 7, 5, 4, 1};

        Board game{board, player, false, play, 10};

        EQ_TEST(game.getNumberOfPlays(), 10, "Function getNumberOfPlays Test 2");
    }

    { // Function getNumberOfPlays Test 3

        uint128_t board{256ULL, 216176110713504000ULL};
        uint128_t player{0ULL, 144116309062385664ULL};

        int play[63] {4, 4, 5, 9, 2, 7, 7, 5, 4, 1};

        Board game{board, player, false, play, 10};

        game.playMove(5);

        EQ_TEST(game.getNumberOfPlays(), 11, "Function getNumberOfPlays Test 3");
    }

    { // Function getNumberOfPlays Test 4

        uint128_t board{256ULL, 216176110713504000ULL};
        uint128_t player{0ULL, 144116309062385664ULL};

        int play[63] {4, 4, 5, 9, 2, 7, 7, 5, 4, 1};

        Board game{board, player, false, play, 10};

        game.undoLastMove();

        EQ_TEST(game.getNumberOfPlays(), 9, "Function getNumberOfPlays Test 4");
    }

    { // Function isValidPosition Test 1

        Board game;
        game.playMove(4);
        game.playMove(4);
        game.playMove(4);
        game.playMove(4);
        game.playMove(4);
        game.playMove(4);
        game.playMove(4);
        game.playMove(3);
        game.playMove(3);
        game.playMove(3);
        game.playMove(3);
        game.playMove(3);
        game.playMove(3);

        EQ_TEST(std::vector<bool>{game.isValidPosition(3), game.isValidPosition(4)},
            std::vector<bool>{true, false}, "Function isValidPosition Test 1");
    }

    { // Function isValidPosition Test 2

        Board game;
        game.playMove(4);
        game.playMove(4);
        game.playMove(4);
        game.playMove(4);
        game.playMove(4);
        game.playMove(4);
        game.playMove(4);

        bool first_check = game.isValidPosition(4);

        game.undoLastMove();

        bool second_check = game.isValidPosition(4);

        EQ_TEST(std::vector<bool>{first_check, second_check},
            std::vector<bool>{false, true}, "Function isValidPosition Test 2");
    }

    { // Function playMove Test

        uint128_t board{256ULL, 216176110713504000ULL};
        uint128_t player{0ULL, 144116309062385664ULL};
        int play[63] {4, 4, 5, 9, 2, 7, 7, 5, 4, 1};
        Board game{board, player, false, play, 10};
        int next_col = 4;

        game.playMove(next_col);

        uint128_t expected_board{256ULL, 216176145073242368ULL};
        uint128_t expected_player{256ULL, 72059801651118336ULL};

        EQ_TEST((std::vector<uint128_t>){game.getBoard(), game.getPlayerPieces(), game.getCurrentPlayer(),
                (uint128_t)game.getPlayHistory(3), (uint128_t)game.getPlayHistory(7), (uint128_t)*(game.getCurrentPlay() - 1)},
            (std::vector<uint128_t>){expected_board, expected_player, true, (uint128_t)play[3], (uint128_t)play[7], (uint128_t)next_col}, 
           "Function playMove Test");
    }

    { // Function undoLastMove Test

        uint128_t board{256ULL, 216176110713504000ULL};
        uint128_t player{0ULL, 144116309062385664ULL};
        int play[63] {4, 4, 5, 9, 2, 7, 7, 5, 4, 1};
        Board game{board, player, false, play, 10};
        int next_col = 4;

        game.playMove(next_col);
        game.undoLastMove();

        EQ_TEST((std::vector<uint128_t>){game.getBoard(), game.getPlayerPieces(), game.getCurrentPlayer(),
                (uint128_t)game.getPlayHistory(3), (uint128_t)game.getPlayHistory(7), (uint128_t)*(game.getCurrentPlay() - 1)},
            (std::vector<uint128_t>){board, player, false, (uint128_t)play[3], (uint128_t)play[7], (uint128_t)play[9]}, 
           "Function undoLastMove Test");
    }

    { // Function checkLastPlayerWin Test 1

        Board game;

        //player 1 moves (4, 3, 2, 5 win)
        //player 2 moves (6, 8, 7)
        game.playMove(4); //player 1
        game.playMove(6); //player 2
        game.playMove(3); //player 1
        game.playMove(8); //player 2
        game.playMove(2); //player 1
        game.playMove(7); //player 2

        bool first_verification = game.checkLastPlayerWin();
        game.playMove(5); //player 1

        bool second_verification = game.checkLastPlayerWin();

        EQ_TEST((std::vector<bool>){first_verification, second_verification},
            (std::vector<bool>){false, true}, "Function checkLastPlayerWin Test 1");
    }

    { // Function checkLastPlayerWin Test 2

        Board game;

        //player 1 moves (4, 3, 4, 3, 3, 5)
        //player 2 moves (4, 4, 2, 2, 2, 2 win)
        game.playMove(4); //player 1
        game.playMove(4); //player 2
        game.playMove(3); //player 1
        game.playMove(4); //player 2
        game.playMove(4); //player 1
        game.playMove(2); //player 2
        game.playMove(3); //player 1
        game.playMove(2); //player 2
        game.playMove(3); //player 1
        game.playMove(2); //player 2
        game.playMove(5); //player 1

        bool first_verification = game.checkLastPlayerWin();
        game.playMove(2); //player 2

        bool second_verification = game.checkLastPlayerWin();

        EQ_TEST((std::vector<bool>){first_verification, second_verification},
            (std::vector<bool>){false, true}, "Function checkLastPlayerWin Test 2");
    }

    { // Function checkLastPlayerWin Test 3

        Board game;

        //player 1 moves (4, 3, 3, 2, 2, 4)
        //player 2 moves (4, 5, 3, 1, 2, 2 win)
        game.playMove(4); //player 1
        game.playMove(4); //player 2
        game.playMove(3); //player 1
        game.playMove(5); //player 2
        game.playMove(3); //player 1
        game.playMove(3); //player 2
        game.playMove(2); //player 1
        game.playMove(1); //player 2
        game.playMove(2); //player 1
        game.playMove(2); //player 2
        game.playMove(4); //player 1

        bool first_verification = game.checkLastPlayerWin();
        game.playMove(2); //player 2

        bool second_verification = game.checkLastPlayerWin();

        EQ_TEST((std::vector<bool>){first_verification, second_verification},
            (std::vector<bool>){false, true}, "Function checkLastPlayerWin Test 3");
    }
    
    { // Function checkLastPlayerWin Test 4

        Board game;

        //player 1 moves (4, 5, 5, 6, 6, 4)
        //player 2 moves (4, 3, 5, 7, 6, 6 win)
        game.playMove(4); //player 1
        game.playMove(4); //player 2
        game.playMove(5); //player 1
        game.playMove(3); //player 2
        game.playMove(5); //player 1
        game.playMove(5); //player 2
        game.playMove(6); //player 1
        game.playMove(7); //player 2
        game.playMove(6); //player 1
        game.playMove(6); //player 2
        game.playMove(4); //player 1

        bool first_verification = game.checkLastPlayerWin();
        game.playMove(6); //player 2

        bool second_verification = game.checkLastPlayerWin();

        EQ_TEST((std::vector<bool>){first_verification, second_verification},
            (std::vector<bool>){false, true}, "Function checkLastPlayerWin Test 4");
    }

    { // Function checkFinishDraw Test

        Board game;
        for (int repetitions = 0; repetitions < 7; repetitions++) {
            for (int column = 0; column < 8; column++) {
                game.playMove(column);
            }
            if (repetitions % 4 == 0) {
                game.playMove(8);
                game.playMove(8);
                game.playMove(8);
            }
        }
        bool first_verification = game.checkFinishDraw();

        game.playMove(8);
        bool second_verification = game.checkFinishDraw();

        EQ_TEST((std::vector<bool>){first_verification, second_verification},
            (std::vector<bool>){false, true}, "Function checkFinishDraw Test");
    }

    { // Function getValidPositions Test

        uint128_t board{0ULL, 34631386595328ULL};
        uint128_t player{0ULL, 11175862796288ULL};
        int play[63];
        Board game{board, player, false, play, 26};

        EQ_TEST(game.getValidPositions(), 491, "Function getValidPositions Test");
    }

    { // Function getWinningPositions Test
        
        Board game;

        game.playMove(8); //player 1
        game.playMove(2); //player 2
        game.playMove(8); //player 1
        game.playMove(3); //player 2
        game.playMove(8); //player 1
        game.playMove(3); //player 2
        game.playMove(2); //player 1
        game.playMove(4); //player 2
        game.playMove(3); //player 1
        game.playMove(4); //player 2
        game.playMove(5); //player 1
        game.playMove(4); //player 2
        game.playMove(4); //player 1
        game.playMove(5); //player 2
        game.playMove(5); //player 1
        game.playMove(5); //player 2

        EQ_TEST(game.getWinningPositions(), 290, "Function getWinningPositions Test");
    }

    { // Function isBoardSymmetrical Test 1

        Board game;

        game.playMove(4); //player 1
        game.playMove(4); //player 2
        game.playMove(5); //player 1
        game.playMove(3); //player 2
        game.playMove(3); //player 1
        game.playMove(5); //player 2

        EQ_TEST(game.isBoardSymmetrical(), false, "Function isBoardSymmetrical Test 1");
    }

    { // Function isBoardSymmetrical Test 2

        Board game;

        game.playMove(4); //player 1
        game.playMove(4); //player 2
        game.playMove(7); //player 1
        game.playMove(2); //player 2
        game.playMove(1); //player 1
        game.playMove(6); //player 2

        EQ_TEST(game.isBoardSymmetrical(), true, "Function isBoardSymmetrical Test 2");
    }

    { // Function isBoardSymmetrical Test 3

        Board game;

        game.playMove(1); //player 1
        game.playMove(1); //player 2
        game.playMove(7); //player 1
        game.playMove(7); //player 2
        game.playMove(1); //player 1
        game.playMove(1); //player 2
        game.playMove(7); //player 1
        game.playMove(7); //player 2
        game.playMove(1); //player 1
        game.playMove(1); //player 2
        game.playMove(7); //player 1
        game.playMove(7); //player 2
        game.playMove(1); //player 2
        game.playMove(2); //player 2
        game.playMove(7); //player 2
        game.playMove(6); //player 2

        EQ_TEST(game.isBoardSymmetrical(), true, "Function isBoardSymmetrical Test 3");
    }

};
