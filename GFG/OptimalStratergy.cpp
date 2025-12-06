class Solution {
  public:
    // Approach: Dynamic Programming (Interval DP / Game Theory)
    // T.C. : O(n^2)           (we fill an n x n DP table)
    // S.C. : O(n^2)           (DP table to store answers for all subarrays)

    int maximumAmount(vector<int> &arr) {
        int n = arr.size();                                                                  

        // dp[i][j] = maximum amount current player can collect from subarray arr[i...j]
        vector<vector<long long>> dp(n, vector<long long>(n, 0));                            

        // Base case: when there is only one coin, we must pick it
        for (int i = 0; i < n; i++) {                                                        
            dp[i][i] = arr[i];                                                               
        }

        // Consider all lengths from 2 to n
        for (int len = 2; len <= n; len++) {                                                 
            // i = starting index of the subarray
            for (int i = 0; i + len - 1 < n; i++) {                                          
                int j = i + len - 1;  // j = ending index of the subarray                    

                // If we pick arr[i], opponent will play optimally to minimize our future gain
                // So in the next move, remaining subarray is:
                //   either (i+2, j) if opponent takes (i+1)
                //   or     (i+1, j-1) if opponent takes j
                long long x = (i + 2 <= j) ? dp[i + 2][j] : 0;                               
                long long y = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;                       

                // If we pick arr[j], opponent will again minimize our gain on remaining:
                //   either (i+1, j-1) if opponent takes i
                //   or     (i, j-2)   if opponent takes (j-1)
                long long z = (i <= j - 2) ? dp[i][j - 2] : 0;                               

                long long takeLeft  = arr[i] + std::min(x, y);                               
                long long takeRight = arr[j] + std::min(y, z);                               

                // We choose the better of the two options
                dp[i][j] = std::max(takeLeft, takeRight);                                    
            }
        }

        // Answer for the full array [0...n-1]
        return (int)dp[0][n - 1];                                                            
    }
};
