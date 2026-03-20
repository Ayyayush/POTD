#include <bits/stdc++.h>
using namespace std;

/**
 * ! Count Submatrices with Equal Frequency of X and Y
 * 
 * ------------------ PROBLEM DESCRIPTION ------------------
 * Hume ek 2D grid diya gaya hai jisme characters 'X' aur 'Y' hain
 * 
 * Hume count karna hai kitne submatrices (0,0 → i,j) me:
 * → number of 'X' == number of 'Y'
 * → aur at least 1 element ho (non-empty)
 * 
 * --------------------------------------------------------
 * ! THOUGHT PROCESS
 * 
 * Ye problem same pattern follow karti hai:
 * → "Count Submatrices with Sum ≤ k" (Leetcode 3070 type)
 * 
 * Yaha:
 * → Instead of sum, hum frequency track kar rahe hain
 * 
 * Trick:
 * → 2 prefix sum grids maintain karenge:
 *    1. cumSumX → count of 'X'
 *    2. cumSumY → count of 'Y'
 * 
 * --------------------------------------------------------
 * ! APPROACH (2D PREFIX SUM)
 * 
 * Har cell (i,j) par:
 * → cumSumX[i][j] = total X in (0,0 → i,j)
 * → cumSumY[i][j] = total Y in (0,0 → i,j)
 * 
 * Formula same rahega:
 * → top + left - overlap
 * 
 * --------------------------------------------------------
 * ! CONDITION CHECK
 * 
 * Agar:
 * → cumSumX[i][j] == cumSumY[i][j]
 * → aur cumSumX[i][j] > 0
 * 
 * toh:
 * → valid submatrix
 * 
 * --------------------------------------------------------
 * ! TIME COMPLEXITY
 * O(m * n) → har cell ek baar process
 * 
 * --------------------------------------------------------
 * ! SPACE COMPLEXITY
 * O(m * n) → 2 prefix matrices use ho rahe hain
 * 
 */

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int m = grid.size();                    // total rows
        int n = grid[0].size();                 // total cols

        // ! prefix sum for 'X'
        vector<vector<int>> cumSumX(m, vector<int>(n, 0));

        // ! prefix sum for 'Y'
        vector<vector<int>> cumSumY(m, vector<int>(n, 0));

        int count = 0;                          // final answer

        // ! traverse grid
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // ! current cell contribution
                cumSumX[i][j] = (grid[i][j] == 'X');   // 1 if X else 0
                cumSumY[i][j] = (grid[i][j] == 'Y');   // 1 if Y else 0

                // ! add top
                if(i-1 >= 0) {
                    cumSumX[i][j] += cumSumX[i-1][j];
                    cumSumY[i][j] += cumSumY[i-1][j];
                }

                // ! add left
                if(j-1 >= 0) {
                    cumSumX[i][j] += cumSumX[i][j-1];
                    cumSumY[i][j] += cumSumY[i][j-1];
                }

                // ! remove overlap
                if(i-1 >= 0 && j-1 >= 0) {
                    cumSumX[i][j] -= cumSumX[i-1][j-1];
                    cumSumY[i][j] -= cumSumY[i-1][j-1];
                }

                // ! check equal frequency condition
                if(cumSumX[i][j] == cumSumY[i][j] && cumSumX[i][j] > 0) {
                    count++;                          // valid submatrix
                }
            }
        }

        return count;                                 // final answer
    }
};