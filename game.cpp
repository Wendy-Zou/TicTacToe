#include "tictactoe.h"

int main() {

    TTTBoard gameBoard;

    bool subsequentRounds = true;
    while (subsequentRounds) {
        cout << "Player 1 is X, Player 2 is O" << endl;

        bool gameRunning = true;

        string move = gameBoard.firstMove();
        cout << move << endl;

        while (gameRunning) {

            if (move == "Player 1 goes first") {
                gameBoard.display();
                cout << "Player 1's turn" << endl;
                
                int num = gameBoard.askForInput();
                gameBoard.update(num, 'X'); 

                if (gameBoard.win('X')) {
                    gameBoard.display();
                    cout << "Player 1 wins!" << endl;
                    gameRunning = false;
                }
                else {
                    
                    if (gameBoard.isFull()) {
                        cout << "Tie Game" << endl;
                        gameRunning = false;
                    }
                    else {
                        move = "Player 2 goes first";
                    }
                }
            }

            else {

                gameBoard.display();
                cout << "Player 2's turn" << endl;
                
                int num2 = gameBoard.askForInput();
                gameBoard.update(num2, 'O');

                if (gameBoard.win('O')) {
                    gameBoard.display();
                    cout << "Player 2 wins!" << endl;
                    gameRunning = false;
                }
                
                else {
                    
                    if (gameBoard.isFull()) {
                        cout << "Tie Game" << endl;
                        gameRunning = false;
                    }
                    else {
                        move = "Player 1 goes first";
                    }
                }
            }
        }
        
        subsequentRounds = gameBoard.playAgain();
        if (subsequentRounds) {
            gameBoard.clearBoard();
            gameRunning = true;
        }
    }

    return 0;
}
