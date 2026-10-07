#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool dfs(vector<vector<char>>& board, string& word, int r, int c, int index) {
    if (index == word.length()) {
        return true;
    }

    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) {
        return false;
    }

    char temp = board[r][c];
    board[r][c] = '#';

    bool found = dfs(board, word, r + 1, c, index + 1) ||
                 dfs(board, word, r - 1, c, index + 1) ||
                 dfs(board, word, r, c + 1, index + 1) ||
                 dfs(board, word, r, c - 1, index + 1);

    board[r][c] = temp;

    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    if (board.empty() || board[0].empty()) {
        return false;
    }

    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == word[0]) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word = "ABCCED";

    if (exist(board, word)) {
        cout << "Word \"" << word << "\" found in the grid.\n";
    } else {
        cout << "Word \"" << word << "\" not found in the grid.\n";
    }

    return 0;
}
