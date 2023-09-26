#include "TicTacToe.h"

Board::Board()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            table[i][j] = ' ';
        }
    }
}

void Board::displayBoard()
{
    std::cout << "Player 1 (X) - Player 2 (O)" << "\n\n";

    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << table[0][0] << "  |  " << table[0][1] << "  |  " << table[0][2] << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << table[1][0] << "  |  " << table[1][1] << "  |  " << table[1][2] << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << table[2][0] << "  |  " << table[2][1] << "  |  " << table[2][2] << std::endl;
    std::cout << "     |     |     " << std::endl << std::endl;
}


bool Board::makeMove(int row, int col, char syb)
{
    if (isMoveValid(row, col)) {
        table[row][col] = syb;
        return true;
    } else {
        return false;
    }
}

bool Board::isMoveValid(int row, int col)
{   if (row < 0 || row > 3 || col < 0 || col > 3) {
        return false;
    }

    if (table[row][col] == ' ') {
        return true;
    } 
    return false;
}

bool Board::isGameOver()
{
    if (checkForWin('x') == false && checkForFull() == false) {
        return false;
    } else if (checkForWin('o') == false && checkForFull() == false) {
        return false;
    } else {
        return true;
    }
}

bool Board::checkForWin(char syb)
{
    for (int i = 0; i < 3; ++i) {
        if (table[i][0] == syb && table[i][1] == syb && table[i][2] == syb) {
            return true;
        }
    }


    for (int i = 0; i < 3; ++i) {
        if (table[0][i] == syb && table[1][i] == syb && table[2][i] == syb) {
            return true;
        }
    }

    if (table[0][0] == table[1][1] == table[2][2] == syb) {
        return true;
    } else if (table[2][0] == table[1][1] == table[0][2] == syb) {
        return true;
    }

    return false;
}

bool Board::checkForFull()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (table[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}

std::string Board::getBoard() {
    std::string s;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            s += table[i][j];
        }
    }
    return s;
}

void Board::setBoard(const std::string& s) {
    int id = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            table[i][j] = s[id++];
        }
    }
}

void Player::sendMove(const std::string& s) const {
    std::ofstream outputFile;
    outputFile.open("soket.txt");
    if (!outputFile) {
        std::cerr << "Failed to open the file." << std::endl;
        throw std::exception();
    }
    // outputFile.clear();
    outputFile << s;
    outputFile.close();
}


std::string Player::recvGameState() {
    std::ifstream inputFile;
    inputFile.open("soket.h");
    if (!inputFile) {
        std::cerr << "Failed to open the file." << std::endl;
        throw std::exception();
    }
    std::string s;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            inputFile >> s;
        }
    }

    inputFile.close();
    return s;
}

Player::Player(const std::string &name, char syb)
{
    playerName = name;
    playerSyb = syb;

}


std::string Player::getName() const {
    return playerName;
}

char Player::getSymbol() const {
    return playerSyb;
}

bool Player::makeMove(Board& board, int row, int col) {
    return board.makeMove(row, col, playerSyb);
}

bool Player::isValidMove(Board& board, int row, int col)
{
    return board.isMoveValid(row, col);
}
