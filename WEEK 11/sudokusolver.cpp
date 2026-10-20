#include <bits/stdc++.h>
using namespace std;
 
// Can digit num be placed at (row, col) without breaking any rule?
bool isSafe(vector<vector<char>> &board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) return false;     // same row
        if (board[i][col] == num) return false;     // same column
    }
 
    int startRow = (row / 3) * 3;                   // top-left of the 3x3 box
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) return false;
        }
    }
    return true;
}
 
bool solveSudoku(vector<vector<char>> &board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {           // found an empty cell
                for (char num = '1'; num <= '9'; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;      // choose
                        if (solveSudoku(board)) return true;
                        board[row][col] = '.';      // un-choose (backtrack)
                    }
                }
                return false;                       // no digit fits this cell
            }
        }
    }
    return true;                                    // no empty cell left
}
 
int main() {
    vector<vector<char>> board(9, vector<char>(9));
 
    cout << "Enter the board: 9 rows of 9 characters, use '.' for empty:\n";
    for (int i = 0; i < 9; i++) {
        string rowStr;
        cin >> rowStr;
        for (int j = 0; j < 9; j++) board[i][j] = rowStr[j];
    }
 
    if (solveSudoku(board)) {
        cout << "\nSolved board:\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) cout << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }
 
    return 0;
}
