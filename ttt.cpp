#include "tictactoe.h"

// Member Functions

TTTBoard::TTTBoard() {
    for (int i = 0; i < 10; ++i) {
        board[i] = ' ';
    }
}

void TTTBoard::display() const {
    cout << "-----+-----+-----" << endl;
    cout << "     |     |" << endl;
    cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << endl;
    cout << "     |     |" << endl;
    cout << "-----+-----+-----" << endl;
    cout << "     |     |" << endl;
    cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << endl;
    cout << "     |     |" << endl;
    cout << "-----+-----+-----" << endl;
    cout << "     |     |" << endl;
    cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << endl;
    cout << "     |     |" << endl;
    cout << "-----+-----+-----" << endl;
}

string TTTBoard::firstMove() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 2);

    int first = distribution(gen);

    if (first == 1) {
        return "Player 1 goes first";
    } 
    else {
        return "Player 2 goes first";
    }
}

bool TTTBoard::occupied(int entry) const {
    if ((board[entry] == 'X') || board[entry] == 'O') {
        return true;
    }
    else {
        return false;
    }
}

bool TTTBoard::isFull() const {
    int emptySpaces = 0;

    for (int i = 1; i <= 9; ++i) {
        if (board[i] == ' ') {
            ++emptySpaces;
        }
    }

    if (emptySpaces == 0) {
        return true;
    }
    else {
        return false;
    }
}

int TTTBoard::askForInput() const {
    int index = 0;

    while ( (index < 1 || index > 9) || occupied(index) ) {
        cout << "Enter a number from 1-9: " << endl;
        cin >> index;
        if (occupied(index)) {
            cout << "Space taken." << endl;
        }
    }

    return index;
}

void TTTBoard::update(int entry, char p) {
    if (!occupied(entry)) {
        board[entry] = p;
    }
}

bool TTTBoard::win(char p) const {
    return ( ((board[1] == p) && (board[2] == p) && (board[3]==p)) ||
    ((board[4] == p) && (board[5] == p) && (board[6]==p)) ||
    ((board[7] == p) && (board[8] == p) && (board[9]==p)) ||

    ((board[1] == p) && (board[4] == p) && (board[7]==p)) ||
    ((board[2] == p) && (board[5] == p) && (board[8]==p)) ||
    ((board[3] == p) && (board[6] == p) && (board[9]==p)) ||

    ((board[1] == p) && (board[5] == p) && (board[9]==p)) ||
    ((board[3] == p) && (board[5] == p) && (board[7]==p)) );
}

bool TTTBoard::playAgain() const {

    char choice; 

    while (choice != 'y' and choice != 'n') {
        cout << "Do you want to play again? Enter y or n: " << endl;
        cin >> choice;
    }
    if (choice == 'y') {
        return true;
    }
    else {
        cout << "You have ended the game!" << endl;
        return false;
    }
}

void TTTBoard::clearBoard() {
    for (int i = 0; i < 10; ++i) {
        board[i] = ' ';
    }
}