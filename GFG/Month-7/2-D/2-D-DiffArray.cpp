#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        Brute Force Approach
        --------------------
        T.C. = O(K * N * M)   // For each of K updates, we loop over N*M submatrix cells
        S.C. = O(1)           // No extra space except variables
    */
    void applyDiff2D_Brute(vector<vector<int>>& mat, vector<vector<int>>& opr) {
        for (auto &op : opr) {
            int v  = op[0];
            int r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];

            // Update each cell in rectangle directly
            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    mat[i][j] += v;
                }
            }
        }
    }

    /*
        Better Approach: 2D Difference Array
        ------------------------------------
        T.C. = O(K + N * M)   // K updates to diff array, then build prefix sum in N*M
        S.C. = O(N * M)       // Extra diff array of size (rows+1) x (cols+1)
    */
    void applyDiff2D_Better(vector<vector<int>>& mat, vector<vector<int>>& updates) {
        int rows = mat.size();
        int cols = mat[0].size();

        // Step 1: Initialize difference array
        vector<vector<int>> diff(rows + 1, vector<int>(cols + 1, 0));

        // Step 2: Apply updates in O(1) per query
        for (auto& query : updates) {
            int val = query[0];
            int r1  = query[1], c1 = query[2];
            int r2  = query[3], c2 = query[4];

            diff[r1][c1]         += val;
            diff[r1][c2 + 1]     -= val;
            diff[r2 + 1][c1]     -= val;
            diff[r2 + 1][c2 + 1] += val;
        }

        // Step 3: Prefix sum to apply updates to matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i > 0) diff[i][j] += diff[i - 1][j];
                if (j > 0) diff[i][j] += diff[i][j - 1];
                if (i > 0 && j > 0) diff[i][j] -= diff[i - 1][j - 1];

                mat[i][j] += diff[i][j];
            }
        }
    }
};
