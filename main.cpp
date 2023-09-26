#include <iostream>
#include "TicTacToe.h"

int main() {
    Board gameBoard;
    Player player1("Player 1", 'X');
    Player player2("Player 2", 'O');
    Player* currentPlayer = &player1;
    bool gameIsOver = false;

    while (!gameIsOver) {
        gameBoard.displayBoard();
        std::cout << currentPlayer->getName() << ", enter your move (row and column): ";
        int row, col;
        std::cin >> row >> col;

        if (currentPlayer->isValidMove(gameBoard, row, col)) {
            // gameBoard.setBoard(currentPlayer->recvGameState());
            currentPlayer->makeMove(gameBoard, row, col);
            currentPlayer->sendMove(gameBoard.getBoard());

            if (gameBoard.checkForWin(currentPlayer->getSymbol())) {
                gameBoard.displayBoard();
                std::cout << currentPlayer->getName() << " wins!" << std::endl;
                gameIsOver = true;
            } else if (gameBoard.checkForFull()) {
                gameBoard.displayBoard();
                std::cout << "It's a drawn!" << std::endl;
                gameIsOver = true;
            } else {
                currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
            }
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    return 0;
}
