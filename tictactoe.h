#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <string>
#include <random>  
using std::cout; using std::cin; using std::endl; using std::string;

class TTTBoard {
private:
    char board[10];

public: 
    TTTBoard();

    void display() const;
    string firstMove() const;
    bool occupied(int) const;
    bool isFull() const;
    int askForInput() const;
    void update(int, char); 
    bool win(char) const;
    bool playAgain() const;
    void clearBoard();

};

#endif