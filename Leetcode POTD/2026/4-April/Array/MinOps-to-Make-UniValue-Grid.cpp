/**
 * 
 * Problem: Minimum Operations to Make Grid Equal (Brute Force)
 * 
 * Idea:
 * - Har element ko target maan ke poori grid ko uske equal banane ki cost calculate karo
 * - Agar kisi element ke saath diff % x != 0 → impossible
 * 
 * T.C : O((m*n)^2)
 * S.C : O(1)
 * 
 * 
 */

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int minops = INT_MAX;

        // try every cell as target
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int ops = 0;
                bool possible = true;

                // compare with whole grid
                for (int k = 0; k < m; k++) {
                    for (int l = 0; l < n; l++) {

                        int diff = abs(grid[i][j] - grid[k][l]);

                        if (diff % x != 0) {
                            possible = false;
                            break;
                        }

                        ops += diff / x;
                    }
                    if (!possible) break;
                }

                if (possible)
                    minops = min(minops, ops);
            }
        }

        return (minops == INT_MAX) ? -1 : minops;
    }
};

/****************************************************************** C++ ******************************************************************
 * Problem: Minimum Operations to Make Grid Equal
 * 
 * Approach: Median Optimization
 * 
 * Steps:
 * 1. Flatten grid into 1D array
 * 2. Sort array
 * 3. Choose median
 * 4. Calculate operations
 * 
 * T.C : O(m*n log(m*n))
 * S.C : O(m*n)
 ******************************************************************/

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<int> flatten;

        // step 1: flatten grid
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                flatten.push_back(grid[i][j]);
            }
        }

        // step 2: sort
        sort(flatten.begin(), flatten.end());

        int len = flatten.size();

        // step 3: median
        int median = flatten[len / 2];

        int ops = 0;

        // step 4: calculate operations
        for(int i = 0; i < len; i++) {

            int diff = abs(flatten[i] - median);

            // if not divisible → impossible
            if(diff % x != 0)
                return -1;

            ops += diff / x;
        }

        return ops;
    }
};