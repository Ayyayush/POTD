class Solution {
public:
    // Approach: Dynamic Programming (O(n^2))
    // T.C : O(n^2)
    // S.C : O(n)
    int maxSumIS(vector<int>& arr) {

        int n = arr.size();

        // dp[i] = max sum of increasing subsequence ending at index i
        vector<int> dp(n);

        // Initially each element forms a subsequence of its own
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i];
        }

        int ans = arr[0];     // final answer

        // Try to extend subsequence from previous smaller elements
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {

                // Check increasing condition
                if (arr[j] < arr[i]) {
                    // Update dp[i] if we get a better sum
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
            ans = max(ans, dp[i]);      // track global max
        }

        return ans;
    }
};
