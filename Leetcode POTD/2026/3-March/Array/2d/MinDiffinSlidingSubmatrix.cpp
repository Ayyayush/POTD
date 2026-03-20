/**
 * ! Minimum Difference in Sliding Submatrix
 * 
 * ! Google Interview Problem
 * 
 * ------------------ PROBLEM DESCRIPTION ------------------
 * Hume ek 2D grid diya gaya hai of size m x n
 * aur ek integer k diya hai
 * 
 * Hume ek naya 2D array (answer matrix) return karna hai
 * jiska size hoga: (m - k + 1) x (n - k + 1)
 * 
 * Har position (i, j) par:
 * → ek k x k ka submatrix consider karna hai
 * → us submatrix ke elements ka "minimum difference" nikalna hai
 * 
 * ! Minimum Difference ka matlab:
 * → submatrix ke elements ko sort karo
 * → consecutive elements ke beech ka minimum absolute difference nikaalo
 * 
 * --------------------------------------------------------
 * ! Example 1:
 * grid = [[3, -1]], k = 1
 * 
 * k = 1 → sirf 1x1 submatrix possible
 * Har submatrix me sirf 1 element hoga
 * → difference = 0 (kyunki compare karne ke liye koi dusra element nahi)
 * 
 * --------------------------------------------------------
 * ! Example 2:
 * grid = [[1, -2, 3],
 *         [2,  3, 5]]
 * k = 2
 * 
 * Har 2x2 submatrix uthake process karenge
 * 
 * --------------------------------------------------------
 * ! GIVEN GRID (5 x 5)
 * 
 *     Col →   0   1   2   3   4
 *           ---------------------
 * Row 0 |    3   1   4   1   5
 * Row 1 |    9   2   6   5   3
 * Row 2 |    5   8   9   7   9
 * Row 3 |    3   2   3   8   4
 * Row 4 |    6   2   6   4   3
 * 
 * ! Given Values:
 * k = 2
 * m = 5
 * n = 5
 * 
 * Result matrix ka size hoga:
 * (5 - 2 + 1) x (5 - 2 + 1) = 4 x 4
 * 
 * --------------------------------------------------------
 * ! THOUGHT PROCESS (Step-by-Step)
 * 
 * Step 1: Har possible top-left index (i, j) ke liye loop chalao
 * → i = 0 to (m - k)
 * → j = 0 to (n - k)
 * 
 * Step 2: Har (i, j) se ek k x k submatrix uthao
 * 
 * Example (i = 0, j = 0):
 * 
 *     3   1
 *     9   2
 * 
 * Step 3: Is submatrix ke saare elements ek array/vector me daalo
 * → [3, 1, 9, 2]
 * 
 * Step 4: Isko sort karo
 * → [1, 2, 3, 9]
 * 
 * Step 5: Consecutive elements ka difference nikaalo:
 * → |2 - 1| = 1
 * → |3 - 2| = 1
 * → |9 - 3| = 6
 * 
 * Step 6: Minimum difference = 1
 * → answer[0][0] = 1
 * 
 * --------------------------------------------------------
 * ! IMPORTANT NOTE (Duplicates Handling)
 * 
 * Agar duplicate elements hain:
 * → jaise [2, 2, 3]
 * → difference = |2 - 2| = 0 (minimum possible)
 * 
 * Isliye:
 * → ya to direct sorted array use karo
 * → ya set use kar sakte ho (unique elements ke liye)
 * 
 * --------------------------------------------------------
 * ! LOOP STRUCTURE IDEA
 * 
 * for (i = 0 to m-k)
 *   for (j = 0 to n-k)
 *     → submatrix collect karo
 *     → sort karo
 *     → min diff calculate karo
 *     → answer[i][j] me store karo
 * 
 * --------------------------------------------------------
 * ! TIME COMPLEXITY
 * 
 * Total submatrices = (m-k+1)*(n-k+1)
 * Har submatrix size = k*k
 * Sorting = O(k^2 log(k^2))
 * 
 * Overall ≈ O(m * n * k^2 log(k))
 * 
 * --------------------------------------------------------
 * ! SPACE COMPLEXITY
 * 
 * Extra space for storing submatrix = O(k^2)
 * 
 */


 class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

     
        vector<vector<int>> res(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                set<int> val;   // (kept as-is, unused but no logic change)


                for (int r = i; r <= i + k - 1; r++) {
                    for (int c = j; c <= j + k - 1; c++) {
                        val.insert(grid[r][c]);   // missing semicolon fixed
                    }
                }

                if (val.size() == 1) {
                    res[i][j] = 0;   // result → res fixed
                    continue;
                }

                int minabsdiff = INT_MAX;

                auto prev = val.begin();
                auto curr = next(prev);

                while (curr != val.end()) {
                    minabsdiff = min(minabsdiff, *curr - *prev);
                    prev = curr;
                    curr++;  
                }

                res[i][j] = minabsdiff;   // name fixed
            }
        }

        return res;   // result → res fixed
    }
};