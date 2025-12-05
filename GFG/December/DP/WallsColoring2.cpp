class Solution {
  public:
    // Approach: DP with row-wise 2 minimums (K Colors Optimized)
    // Time Complexity: O(n * k)
    // Space Complexity: O(1) extra (ignoring input storage)
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();                     // number of walls
        if (n == 0) return 0;                     // no walls, no cost
        
        int k = costs[0].size();                  // number of colors
        if (k == 0) return 0;                     // no colors, trivial case
        
        // If only 1 color but more than 1 wall, adjacent walls can't have different colors
        if (k == 1) {
            if (n == 1) return costs[0][0];       // single wall, single color is fine
            return -1;                            // impossible if n > 1
        }
        
        long long prevMin1 = 0;                   // smallest total cost till previous row
        long long prevMin2 = 0;                   // second smallest total cost till previous row
        int prevMin1Color = -1;                   // color index that gave prevMin1
        
        // Process each wall i
        for (int i = 0; i < n; i++) {
            long long curMin1 = LLONG_MAX;        // smallest cost for current row i
            long long curMin2 = LLONG_MAX;        // second smallest cost for current row i
            int curMin1Color = -1;                // color index for curMin1
            
            // Try painting wall i with each color c
            for (int c = 0; c < k; c++) {
                long long bestPrev;
                
                // If we pick same color as prevMin1Color, we must use prevMin2
                if (c == prevMin1Color) {
                    bestPrev = prevMin2;
                } else {
                    bestPrev = prevMin1;
                }
                
                long long curCost = costs[i][c] + bestPrev;   // total cost till wall i with color c
                
                // Update current row's smallest and second smallest
                if (curCost < curMin1) {
                    curMin2 = curMin1;            // old min1 becomes min2
                    curMin1 = curCost;            // new smallest
                    curMin1Color = c;             // store color index of smallest
                } else if (curCost < curMin2) {
                    curMin2 = curCost;            // update second smallest
                }
            }
            
            // Move current minimums to previous for next iteration (next wall)
            prevMin1 = curMin1;
            prevMin2 = curMin2;
            prevMin1Color = curMin1Color;
        }
        
        // For k >= 2, it is always possible, so prevMin1 is the answer
        return (int)prevMin1;
    }
};
