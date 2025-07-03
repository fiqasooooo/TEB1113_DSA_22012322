/*
ID = 22012322
Name = Nur Afiqah Solehah binti Mazlan 
Lab = G3
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to check if a player has won
bool isWinner(vector<string>& board, char player) {
    // 3 rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;

    // 3 columns
    for (int j = 0; j < 3; j++)
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;

    // 2 diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

bool isValidTicTacToe(vector<string>& board) {
    int xCount = 0, oCount = 0;

    // Count Xs and Os
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') xCount++;
            else if (board[i][j] == 'O') oCount++;
        }

    // Rule 1: X always goes first
    if (oCount > xCount) return false;

    // Rule 2: X cannot play more than one extra move
    if (xCount > oCount + 1) return false;

    // Check if X or O has won
    bool xWin = isWinner(board, 'X');
    bool oWin = isWinner(board, 'O');

    // Rule 3: Both players can't win
    if (xWin && oWin) return false;

    // Rule 4: If X wins, X must have 1 more move
    if (xWin && xCount != oCount + 1) return false;

    // Rule 5: If O wins, counts must be equal
    if (oWin && xCount != oCount) return false;

    return true; // valid board
}

int main() {
    vector<string> board(3);
    cout << "Enter the board (3 rows of 3 characters each, using X, O or _):\n";
    for (int i = 0; i < 3; i++)
        cin >> board[i];

    if (isValidTicTacToe(board))
        cout << "The board is VALID.\n";
    else
        cout << "The board is INVALID.\n";

    return 0;
}

