class Solution {
  public:
    // Approach: DP on intervals (Optimal BST / Matrix Chain style)
    // -------------------------------------------
    // dp[i][j] = minimum cost of an Optimal BST formed using keys[i..j]
    //
    // Recurrence:
    //   For every possible root r in [i..j]:
    //     cost = cost of left subtree  +  cost of right subtree  +  sum of frequencies in [i..j]
    //          = (r > i ? dp[i][r-1] : 0) + (r < j ? dp[r+1][j] : 0) + sum(freq[i..j])
    //
    // We try all r and take the minimum cost.
    // We precompute prefix sum of freq[] to get sum(freq[i..j]) in O(1).
    //
    // Time Complexity:  O(n^3)   (n^2 intervals * n choices of root)
    // Space Complexity: O(n^2)   (dp table of size n x n)
    
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = (int)keys.size();                         // number of keys
        
        // Edge case: if no keys, cost is 0
        if (n == 0) return 0;                             // safety, though constraints say n >= 1
        
        // prefix[i] = sum of freq[0..i-1]
        // So sum of freq[i..j] = prefix[j+1] - prefix[i]
        vector<int> prefix(n + 1, 0);                     // size n+1 for easy prefix sum
        
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + freq[i];          // build prefix sum array
        }
        
        // dp[i][j] will store minimum cost for keys[i..j]
        vector<vector<int>> dp(n, vector<int>(n, 0));     // initialize all with 0
        
        // We build the solution for increasing lengths of interval
        for (int len = 1; len <= n; len++) {              // len = current length of segment [i..j]
            for (int i = 0; i + len - 1 < n; i++) {       // i = start index of segment
                int j = i + len - 1;                      // j = end index of segment
                
                // Total frequency sum for keys in range [i..j]
                int sumFreq = prefix[j + 1] - prefix[i];  // sum(freq[i..j]) in O(1)
                
                // Initialize dp[i][j] with a large value
                dp[i][j] = INT_MAX;
                
                // Try every key in [i..j] as root 'r'
                for (int r = i; r <= j; r++) {
                    // Cost of left subtree if exists, otherwise 0
                    int leftCost = (r > i) ? dp[i][r - 1] : 0;
                    
                    // Cost of right subtree if exists, otherwise 0
                    int rightCost = (r < j) ? dp[r + 1][j] : 0;
                    
                    // Total cost if 'r' is root:
                    // left subtree + right subtree + sum of all freq in [i..j]
                    int totalCost = leftCost + rightCost + sumFreq;
                    
                    // Take minimum over all choices of root r
                    if (totalCost < dp[i][j]) {
                        dp[i][j] = totalCost;
                    }
                }
            }
        }
        
        // Answer is minimum cost for keys[0..n-1]
        return dp[0][n - 1];
    }
};
