/*
Question Link:- https://leetcode.com/problems/word-search/
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int k) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) {
            return false;
        }

        if (k == word.size() - 1) {
            return true;
        }

        char temp = board[i][j];
        board[i][j] = '*';  // Mark the cell as visited

        // Check the neighboring cells
        if (dfs(board, word, i - 1, j, k + 1) || dfs(board, word, i + 1, j, k + 1) ||
            dfs(board, word, i, j - 1, k + 1) || dfs(board, word, i, j + 1, k + 1)) {
            return true;
        }

        board[i][j] = temp;  // Restore the cell

        return false;
    }
};
