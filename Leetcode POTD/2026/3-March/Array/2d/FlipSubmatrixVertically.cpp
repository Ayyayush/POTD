/*
 * ! Approach: Stack (Row Reversal using Extra Space)
 * T.C = O(k * k)
 * S.C = O(k * k)
 */

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {

        stack<vector<int>> st;             // store rows of submatrix

        // ! Step 1: push all rows of submatrix into stack
        for (int i = x; i < x + k; i++) {
            vector<int> arr;
            for (int j = y; j < y + k; j++) {
                arr.push_back(grid[i][j]);   // collect row
            }
            st.push(arr);                   // push to stack
        }

        // ! Step 2: pop and overwrite → reversed row order
        for (int i = x; i < x + k; i++) {
            vector<int> arr = st.top();     // get last row
            st.pop();

            int idx = 0;
            for (int j = y; j < y + k; j++) {
                grid[i][j] = arr[idx++];    // fill back
            }
        }

        return grid;
    }
};


/*
 * ! Approach: Two Pointer (In-place Row Swap)
 * T.C = O(k * k)
 * S.C = O(1)
 */

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {

        // ! swap rows from top and bottom
        for (int toprow = x, bottomrow = x + k - 1;
             toprow < bottomrow;
             toprow++, bottomrow--) 
        {
            for (int col = y; col < y + k; col++) {

                // ! swap elements column-wise
                int temp = grid[toprow][col];
                grid[toprow][col] = grid[bottomrow][col];
                grid[bottomrow][col] = temp;
            }
        }

        return grid;
    }
};


/*
 * ! Approach: Optimized In-place Swap (Clean Version)
 * T.C = O(k * k)
 * S.C = O(1)
 */

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {

        // ! iterate half rows only
        for (int i = 0; i < k / 2; i++) {
            int topRow = x + i;                 // top row index
            int bottomRow = x + k - 1 - i;      // bottom row index

            for (int j = 0; j < k; j++) {

                // ! direct swap (clean)
                swap(grid[topRow][y + j], grid[bottomRow][y + j]);
            }
        }

        return grid;
    }
};