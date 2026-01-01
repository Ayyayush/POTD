#include <bits/stdc++.h>
using namespace std;

/*
 * ✅ Problem Link: https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k
 *
 * Problem:
 * Given a binary string `s` and an integer `k`, find the length of the longest subsequence of `s`
 * such that the binary value of the subsequence is less than or equal to `k`.
 *
 * Example:
 * Input: s = "1001010", k = 5
 * Output: 5
 *
 * Explanation:
 * One such subsequence is "00010" which is binary 2 <= 5 and has length 5.
 */

// ----------------------------------------------------------------------------------------------------
// 🔴 Brute Force Approach (Recursive Take/Skip)
// ----------------------------------------------------------------------------------------------------
/*
 * Time Complexity  : O(2^n)         // Every bit is either taken or skipped
 * Space Complexity : O(n)          // Max recursion depth is n
 */
void brute() {
    cout << "\n🔴 Brute Force Approach (Recursive)\n";

    string s = "1001010";
    int k = 5;
    int n = s.length();

    function<int(int, int)> solve = [&](int i, int kLeft) -> int {
        if (i < 0)
            return 0;

        int take = 0;
        int bit = s[i] - '0';
        long long value = (bit == 1 ? (1LL << (n - i - 1)) : 0);

        if (value <= kLeft) {
            take = 1 + solve(i - 1, kLeft - value);
        }

        int skip = solve(i - 1, kLeft);

        return max(take, skip);
    };

    int maxLength = solve(n - 1, k);

    cout << "Max Length Subsequence (<= " << k << ") = " << maxLength << endl;
}

// ----------------------------------------------------------------------------------------------------
// 🟡 Better Approach (Greedy from Right to Left)
// ----------------------------------------------------------------------------------------------------
/*
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */
void better() {
    cout << "\n🟡 Better Approach (Greedy Right to Left)\n";

    string s = "1001010";
    int k = 5;

    int length = 0;
    long long powerValue = 1;

    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '0') {
            /*
             * Always take '0' as it doesn't increase binary value
             */
            length++;
        } else if (powerValue <= k) {
            /*
             * Take '1' only if it fits within current value of k
             */
            length++;
            k -= powerValue;
        }

        /*
         * Prepare powerValue for next left-side bit
         */
        if (powerValue <= k)
            powerValue <<= 1; // Multiply by 2
    }

    cout << "Max Length Subsequence (<= " << k << ") = " << length << endl;
}

// ----------------------------------------------------------------------------------------------------
// 🟢 Main Function to Call Both Approaches
// ----------------------------------------------------------------------------------------------------
int main() {
    brute();   // 🔴 Brute force using recursion
    better();  // 🟡 Greedy optimized solution
    return 0;
}
