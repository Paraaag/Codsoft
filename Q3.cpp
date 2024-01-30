#include <iostream>
#include <vector>

using namespace std;

void display(const vector<vector<char>>& board);
bool move(vector<vector<char>>& board, char player, int row, int col);
bool win(const vector<vector<char>>& board, char player);
bool draw(const vector<vector<char>>& board);
bool replay();

int main() {
    bool play = true;

    while (play) {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        char currentPlayer = 'X';
        bool endGame = false;

        while (!endGame) {
            display(board);

            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            if (!move(board, currentPlayer, row - 1, col - 1)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            if (win(board, currentPlayer)) {
                display(board);
                cout << "Player " << currentPlayer << " wins!\n";
                endGame = true;
            } else if (draw(board)) {
                display(board);
                cout << "It's a draw!\n";
                endGame = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        play = replay();
    }

    cout << "over n out\n";

    return 0;
}

void display(const vector<vector<char>>& board) {
    cout << "  1 2 3\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2)
                cout << "|";
        }
        cout << endl;
        if (i < 2)
            cout << "  -----\n";
    }
}

bool move(vector<vector<char>>& board, char player, int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool win(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;
    return false;
}

bool draw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

bool replay() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
