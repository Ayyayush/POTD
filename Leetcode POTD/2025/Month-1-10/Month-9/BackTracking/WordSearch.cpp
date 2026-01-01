#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> direction = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};      // 4 directions: right, down, up, left

    // T.C. = O(m * n * 4^L), where L = length of word
    // S.C. = O(L), recursive call stack depth
    bool solve(vector<vector<char>> &board, int i, int j, int m, int n, string str, string &word)
    {
        if (!(i >= 0 && j >= 0 && j < n && i < m && board[i][j] != '$'))
            return false;

        str += board[i][j];                               // Add current char to str
        if (str == word) return true;                     // If full word formed, return true

        char temp = board[i][j];
        board[i][j] = '$';                                // Mark current cell as visited

        for (auto dir : direction)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (solve(board, i_, j_, m, n, str, word))    // Explore all directions
                return true;
        }

        board[i][j] = temp;                               // Backtrack: unmark visited
        return false;
    }

    // T.C. = O(m * n * 4^L)
    // S.C. = O(L)
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)                        // Traverse every cell
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0] && solve(board, i, j, m, n, "", word))
                    return true;
            }
        }

        return false;
    }
};




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int l, m, n;  // Dimensions and word length
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  // Right, Left, Down, Up

    // T.C. = O(m * n * 4^L)       S.C. = O(L) recursive call stack depth
    bool find(vector<vector<char>>& board, int i, int j, string &word, int idx) {
        if (idx >= l) return true;  // Word matched completely

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])
            return false;           // Invalid cell or char mismatch

        char temp = board[i][j];
        board[i][j] = '$';          // Mark as visited

        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (find(board, i_, j_, word, idx + 1))
                return true;
        }

        board[i][j] = temp;         // Backtrack
        return false;
    }

    // T.C. = O(m * n * 4^L)       S.C. = O(L)
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        l = word.length();

        if (m * n < l) return false;  // If grid has fewer cells than word length

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && find(board, i, j, word, 0))
                    return true;
            }
        }

        return false;
    }
};
