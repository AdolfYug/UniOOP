#include <iostream>
#include <string>

using namespace std;

class TicTacToe {
private:
    char field[3][3];

public:
    char currentPlayer;

    TicTacToe() {
        currentPlayer = 'X';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                field[i][j] = ' ';
            }
        }
    }

    void printField() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << field[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || field[row][col] != ' ') {
            return false;
        }

        field[row][col] = currentPlayer;
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        }
        else {
            currentPlayer = 'X';
        }
        return true;
    }

    char checkWinner() {
        for (int i = 0; i < 3; i++) {
            if (field[i][0] != ' ' && field[i][0] == field[i][1] && field[i][0] == field[i][2]) {
                return field[i][0];
            }
            if (field[0][i] != ' ' && field[0][i] == field[1][i] && field[0][i] == field[2][i]) {
                return field[0][i];
            }
        }
        if (field[0][0] != ' ' && field[0][0] == field[1][1] && field[0][0] == field[2][2]) {
            return field[0][0];
        }
        if (field[0][2] != ' ' && field[0][2] == field[1][1] && field[0][2] == field[2][0]) {
            return field[0][2];
        }
        return ' ';
    }
};

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    TicTacToe game;
    int row, col;

    while (game.checkWinner() == ' ') {
        game.printField();
        char player = game.currentPlayer;

        cout << "Игрок " << player  << " вводит координаты хода от 0 до 2 (x y) : "; 

        cin >> row >> col;

        if (!game.makeMove(row, col)) {
            cout << "Невозможно совершить такой ход. Повторите ввод снова : ";
        }
    }

    game.printField();
    char winner = game.checkWinner();

    if (winner == ' ') {
        cout << "Ничья!" << endl;
    }
    else {
        cout << "Игрок " << winner << " побеждает!" << endl;
    }

    return 0;
}