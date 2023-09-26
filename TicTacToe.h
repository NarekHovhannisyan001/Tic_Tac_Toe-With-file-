#ifndef TT_H
#define TT_H

#include <iostream>
#include <fstream>


class Board {

public:
    Board();

public:
    void displayBoard();
    bool makeMove(int row, int col, char syb);
    bool isMoveValid(int row, int col);
    bool isGameOver();
    bool checkForWin(char syb);
    bool checkForFull();
    std::string getBoard();
    void setBoard(const std::string&);
private:
    char table[3][3]
;
};


class Player{

public:
    
    Player(const std::string& name, char syb);

public:

    std::string getName() const;
    char getSymbol() const;
    bool makeMove(Board&, int, int);
    bool isValidMove(Board&, int, int);
    void sendMove(const std::string&) const;
    std::string recvGameState();

private:
    std::string playerName;
    char playerSyb;
};




#endif //TT_H