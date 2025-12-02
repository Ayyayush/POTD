class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // Time Complexity: O(n^2)
        // Space Complexity: O(n)

        int n = mat.size();                                        // square matrix
        vector<int> sumrow(n, 0), sumcol(n, 0);                    // har row/col ke sum store karne ke liye

        int maxsum = INT_MIN;                                      // max row/col sum ka track rakhne ke liye

        // row-wise and column-wise sum nikalna
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sumrow[i] += mat[i][j];                            // ith row ka sum
                sumcol[j] += mat[i][j];                            // jth column ka sum
            }
        }

        // max sum nikalna (either row-wise ya column-wise max)
        for (int i = 0; i < n; i++) {
            maxsum = max(maxsum, max(sumrow[i], sumcol[i]));
        }

        int totalop = 0;                                           // final operations count

        // har cell ko maxsum banana ke liye required operations
        for (int i = 0; i < n; i++) {
            totalop += (maxsum - sumrow[i]);                      // har row ko maxsum banane ke liye
        }

        return totalop;
    }
};
