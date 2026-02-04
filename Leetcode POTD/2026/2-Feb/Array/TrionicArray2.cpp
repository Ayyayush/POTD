/**************************************************************************************************
 *  Problem Name : Maximum Sum Trionic Subarray
 *  Platform     : LeetCode (Problem 3640)
 *
 *  Definition:
 *  A Trionic subarray follows this pattern:
 *
 *      Increasing  →  Decreasing  →  Increasing
 *          📈              📉              📈
 *
 *  Goal:
 *  Find the maximum possible sum of any subarray that follows the above pattern.
 *
 *  Constraints Insight:
 *  - Array size can be large
 *  - O(n^2) brute force is NOT allowed
 *  - We must solve it in O(n)
 *
 * ================================================================================================
 *  KEY OBSERVATIONS
 * ================================================================================================
 *
 *  1) Numbers can be NEGATIVE
 *     → Har element ko include karna zaroori nahi
 *     → "skip or take" decision har index par lena padega
 *
 *  2) Pattern based problem hai
 *     → Sirf trend matter karta hai (increasing / decreasing)
 *
 *  3) Once we finish:
 *        increasing → decreasing → increasing
 *     → Trionic sequence complete ho jaati hai
 *
 * ================================================================================================
 *  TREND STATES (MOST IMPORTANT PART)
 * ================================================================================================
 *
 *  trend = 0 → Sequence start hi nahi hui
 *              - elements skip kar sakte hain
 *
 *  trend = 1 → Increasing phase
 *
 *  trend = 2 → Decreasing phase
 *
 *  trend = 3 → Final Increasing phase
 *              - Valid Trionic Subarray completed
 *
 * ================================================================================================
 *  DP DEFINITION
 * ================================================================================================
 *
 *  dp[i][trend] = Maximum sum possible starting from index `i`
 *                 when current trend is `trend`
 *
 *  Total states = n * 4  →  O(n)
 *
 * ================================================================================================
 *  APPROACH
 * ================================================================================================
 *
 *  - Recursion + Memoization (Top Down DP)
 *  - At every index:
 *      a) Skip element (allowed only when trend == 0)
 *      b) Take element (if trend conditions satisfy)
 *
 * ================================================================================================
 *  TIME & SPACE COMPLEXITY
 * ================================================================================================
 *
 *  Time Complexity  : O(n)
 *  Space Complexity : O(n)
 *      - DP table
 *      - Recursion stack
 *
 **************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    int n;

    /*
     * memo[i][trend]
     * i     → current index
     * trend → current phase of trionic sequence
     */
    vector<vector<ll>> memo;

    ll solve(int i, int trend, vector<int>& nums) {

        /************************ BASE CASE ************************/
        if (i == n) {
            /*
             * Agar hum final increasing phase (trend == 3) tak pahunch gaye,
             * toh valid trionic subarray ban chuki hai
             */
            if (trend == 3)
                return 0;

            /*
             * Agar beech mein hi array khatam ho gayi
             * toh ye path invalid hai
             */
            return LLONG_MIN / 2;
        }

        /*********************** MEMO CHECK ************************/
        if (memo[i][trend] != LLONG_MIN)
            return memo[i][trend];

        ll take = LLONG_MIN / 2;
        ll skip = LLONG_MIN / 2;

        /************************ SKIP OPTION ************************/
        /*
         * Skip sirf tab allowed hai jab sequence start nahi hui ho
         */
        if (trend == 0) {
            skip = solve(i + 1, 0, nums);
        }

        /************************ TAKE OPTION ************************/

        /*
         * Agar trionic complete ho chuki hai (trend == 3),
         * toh hum yahin end kar sakte hain
         */
        if (trend == 3) {
            take = nums[i];
        }

        /*
         * Next element exist karta ho tab hi comparison possible hai
         */
        if (i + 1 < n) {
            int curr = nums[i];
            int next = nums[i + 1];

            /************ START INCREASING PHASE ************/
            if (trend == 0 && next > curr) {
                take = max(take, curr + solve(i + 1, 1, nums));
            }

            /************ INCREASING PHASE ************/
            else if (trend == 1) {
                if (next > curr) {
                    // Increasing continue
                    take = max(take, curr + solve(i + 1, 1, nums));
                } else if (next < curr) {
                    // Switch to decreasing
                    take = max(take, curr + solve(i + 1, 2, nums));
                }
            }

            /************ DECREASING PHASE ************/
            else if (trend == 2) {
                if (next < curr) {
                    // Decreasing continue
                    take = max(take, curr + solve(i + 1, 2, nums));
                } else if (next > curr) {
                    // Final increasing starts
                    take = max(take, curr + solve(i + 1, 3, nums));
                }
            }

            /************ FINAL INCREASING PHASE ************/
            else if (trend == 3 && next > curr) {
                take = max(take, curr + solve(i + 1, 3, nums));
            }
        }

        /*********************** STORE & RETURN ************************/
        return memo[i][trend] = max(take, skip);
    }

    ll maxSumTrionic(vector<int>& nums) {
        n = nums.size();

        /*
         * Initialize memo with very small values
         */
        memo.assign(n + 1, vector<ll>(4, LLONG_MIN));

        /*
         * Start from index 0
         * trend = 0 → sequence not started
         */
        return solve(0, 0, nums);
    }
};
