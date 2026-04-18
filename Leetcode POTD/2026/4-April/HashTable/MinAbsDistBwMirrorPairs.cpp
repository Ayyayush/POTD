/**
 * 🔥 Leetcode 3761: Minimum Mirror Pair Distance
 * --------------------------------------------------
 * 
 * 🧠 Problem Description (Hinglish)
 * --------------------------------------------------
 * Tumhe ek array diya gaya hai `nums`
 * 
 * 👉 Do numbers ko "mirror pair" bolte hain agar:
 *     ek number dusre ka reverse ho
 * 
 * Example:
 * 12 ↔ 21
 * 34 ↔ 43
 * 
 * 👉 Hume find karna hai:
 * Minimum distance (i - j) such that:
 * nums[i] == reverse(nums[j])
 * 
 * Agar aisa koi pair nahi mila → return -1
 * 
 * --------------------------------------------------
 * 🐢 Brute Approach (Nested Loop)
 * --------------------------------------------------
 * 👉 Har pair (i, j) check karo
 * 👉 Check karo nums[i] == reverse(nums[j])
 * 
 * ⏱️ T.C = O(N^2 * digits)
 * 🧠 S.C = O(1)
 * ❌ TLE for large input
 * 
 * --------------------------------------------------
 * ⚡ Better Approach (HashMap + Reverse)
 * --------------------------------------------------
 * 👉 Ek map maintain karo:
 *     reversed number → index
 * 
 * 👉 Traverse array:
 *     - Agar current number map me hai → pair mil gaya
 *     - Distance calculate karo
 *     - Reverse store karo map me
 * 
 * ⏱️ T.C = O(N * log10(num))
 * 🧠 S.C = O(N)
 */

class Solution {
public:

    /**
     * 🔁 Helper: Reverse number
     * --------------------------------------------------
     * Example:
     * 123 → 321
     */
    int getReverse(int n) {
        int rev = 0;

        while (n > 0) {
            int rem = n % 10;
            rev = rev * 10 + rem;
            n /= 10;
        }

        return rev;
    }

    /**
     * 🚀 Main Function
     */
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp; 
        // key   = reversed number
        // value = index

        int result = INT_MAX;

        for (int i = 0; i < n; i++) {

            /**
             * 🔍 Check:
             * Agar current number pehle kisi ka reverse tha
             */
            if (mp.count(nums[i])) {
                result = min(result, i - mp[nums[i]]);
            }

            /**
             * 📝 Store:
             * Current number ka reverse → index
             */
            mp[getReverse(nums[i])] = i;
        }

        return result == INT_MAX ? -1 : result;
    }
};