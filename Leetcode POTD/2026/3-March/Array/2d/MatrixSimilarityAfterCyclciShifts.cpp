/*
Leetcode: Are Similar Matrix After Shifts
*/

/*******************************************************
 * 🔴 Approach 1: Brute Force (Simulation)
 * T.C : O(m * n)
 * S.C : O(m * n)
 *******************************************************/
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k = k % n;

        vector<vector<int>> newMat = mat; // copy → O(m*n) space

        for (int i = 0; i < m; i++) {

            vector<int> temp(n);

            for (int j = 0; j < n; j++) {

                if (i % 2 == 0) {
                    // Even row → LEFT shift
                    temp[j] = mat[i][(j + k) % n];
                } else {
                    // Odd row → RIGHT shift
                    temp[j] = mat[i][(j - k + n) % n];
                }
            }

            newMat[i] = temp; // replace row
        }

        // Compare matrices → O(m*n)
        return newMat == mat;
    }
};


/*******************************************************
 * 🟢 Approach 2: Optimal (In-place Comparison)
 * T.C : O(m * n)
 * S.C : O(1)
 *******************************************************/
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k = k % n;              // Reduce unnecessary rotations
        if (k == 0) return true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i % 2 == 0) { // Even row → LEFT shift
                    if (mat[i][j] != mat[i][(j + k) % n])
                        return false;
                } 
                else {            // Odd row → RIGHT shift
                    if (mat[i][j] != mat[i][(j + n - k) % n])
                        return false;
                }
            }
        }
        return true;
    }
};