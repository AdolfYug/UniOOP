#include <iostream>

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        currentPlayer = 'X';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }

    void printBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            return false;
        }

        board[row][col] = currentPlayer;
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
        return true;
    }

    char checkWinner() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
                return board[i][0];
            }
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
                return board[0][i];
            }
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            return board[0][0];
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return board[0][2];
        }
        return ' ';
    }
};

int main() {
    TicTacToe game;
    int row, col;
    
    while (game.checkWinner() == ' ') {
        game.printBoard();
        
        std::cout << "Player " << game.currentPlayer << ", enter your move (row col): ";
        std::cin >> row >> col;
        
        if (!game.makeMove(row, col)) {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    game.printBoard();
    char winner = game.checkWinner();
    
    if (winner == ' ') {
        std::cout << "It's a draw!" << std::endl;
    } else {
        std::cout << "Player " << winner << " wins!" << std::endl;
    }

    return 0;
}