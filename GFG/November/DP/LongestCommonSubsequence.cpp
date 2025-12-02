class Solution {
public:
    int LCIS(vector<int> &a, vector<int> &b) {

        int n = a.size();
        int m = b.size();

        vector<int> dp(m, 0);  
        // dp[j] = LCIS ending at b[j]

        int answer = 0;

        for (int i = 0; i < n; i++) {

            int bestBefore = 0;  
            // a[i] se chhota b[j] milega toh uska best dp store rakhenge

            for (int j = 0; j < m; j++) {

                if (a[i] == b[j]) {
                    // Same element → LCIS possible
                    dp[j] = bestBefore + 1;
                }
                else if (a[i] > b[j]) {
                    // Increase chahiye → a[i] > b[j]
                    bestBefore = max(bestBefore, dp[j]);
                }
                // else a[i] < b[j] → kuch nahi karna
            }
        }

        // final answer = max of dp[]
        for (int x : dp) answer = max(answer, x);

        return answer;
    }
};
