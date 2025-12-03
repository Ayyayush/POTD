/**
 * Problem: Minimum Cost to Cut a Stick of Length N
 *
 * You are given a stick of length 'n' labeled from 0 to n.
 * You are also given an array 'cuts[]' representing positions along the stick 
 * where you can make a cut.
 *
 * RULE:
 *   - Each cut costs equal to the current length of the stick being cut.
 *   - After a cut, stick divides into two smaller sticks.
 *   - Cuts can be performed in any order.
 *
 * Objective:
 *   Find the minimum total cost to perform all cuts.
 *
 * Example 1:
 *   n = 10, cuts = [2,4,7]
 *   Optimal order: [4,2,7] → Cost = 10 + 4 + 6 = 20
 *
 * Example 2:
 *   n = 8, cuts = [1,6,3,5]
 *   Optimal order: [3,6,1,5] → Cost = 8 + 5 + 3 + 3 = 19
 *
 * Approach:
 *   This is a standard "DP on intervals" problem.
 *
 *   Steps:
 *     1. Add 0 and n to cuts array to represent full stick boundaries.
 *     2. Sort cuts so that we can consider sub-sticks in order.
 *     3. Define dp[i][j] = minimum cost to cut the stick between cuts[i] and cuts[j].
 *     4. Use the formula:
 *           dp[i][j] = min(dp[i][k] + dp[k][j] + (cuts[j] - cuts[i]))
 *        for all i < k < j
 *     5. The final answer is dp[0][m+1], where m = original cuts.size()
 *
 * Time Complexity: O(m^3)   (m = cuts.size())
 * Space Complexity: O(m^2)
 */

class Solution {
  public:
    int minCutCost(int n, vector<int>& cuts) {

        int m = cuts.size();

        // Add 0 and n as stick boundaries
        cuts.push_back(0);
        cuts.push_back(n);

        // Sort the cuts so we can process intervals in order
        sort(cuts.begin(), cuts.end());

        // dp[i][j] = min cost to cut stick from cuts[i] to cuts[j]
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));

        // len = length of interval in terms of number of cuts
        for (int len = 2; len < m + 2; len++) {
            for (int i = 0; i + len < m + 2; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;

                // Try every possible cut between i and j
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i][k] + dp[k][j] + (cuts[j] - cuts[i])  // cost of current cut
                    );
                }
            }
        }

        // Answer = min cost to cut full stick from 0 to n
        return dp[0][m + 1];
    }
};
