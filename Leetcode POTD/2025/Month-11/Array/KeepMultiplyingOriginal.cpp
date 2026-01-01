#include <bits/stdc++.h>
using namespace std;

/**
 * ---------------------- PROBLEM EXPLANATION ----------------------
 * Tumhe ek array 'nums' diya gaya hai aur ek starting value 'original'.
 * Jab tak 'original' nums me exist kare, tumhe original = original * 2
 * karte rehna hai.
 * 
 * Example:
 * nums = [2, 7, 9], original = 2
 * → 2 array me hai → 4
 * → 4 array me nahi hai → answer = 4
 * 
 * ---------------------- APPROACHES ----------------------
 * APPROACH 1 (Basic Loop) - O(n^2)
 * - Har baar array scan karo.
 * - Agar original mila toh double karo aur loop wapas se chalao.
 * - Slow but simple.
 * 
 * APPROACH 2 (Optimal Using Set) - O(n)
 * - nums ko unordered_set me convert karo.
 * - Jab tak original set me exist kare → double karte raho.
 * - Fastest and cleanest.
 * 
 * ---------------------- TIME & SPACE COMPLEXITY ----------------------
 * Optimal Approach:
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 * 
 * ---------------------- FINAL CODE (Optimal) ----------------------
 */

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {

        // Converting nums into a set → O(1) average lookup
        unordered_set<int> st(nums.begin(), nums.end());

        // Jab tak original set me exist kare, usse double karte raho
        while(st.count(original)) {
            original = original * 2;      // value double ho rahi hai
        }

        return original;                  // final value jab exist na kare
    }
};

/**
 * ---------------------- EXTRA: Your Original Logic (Corrected) ----------------------
 * NOTE: Ye approach slow hai (O(n^2)) par tumhari logic ke close hai.
 * Agar specifically ye chahiye ho toh ise use kar sakte ho.
 *
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == original) {
                original = original * 2;    // spelling fix
                i = -1;                     // scanning reset
            }
        }

        return original;
    }
};
*/

int main() {
    // TESTING (Remove before submitting)
    vector<int> nums = {2, 7, 9};
    int original = 2;

    Solution s;
    cout << s.findFinalValue(nums, original);  // Expected output: 4
    return 0;
}



/**Python  Code  */
class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        """
        Problem: Jab tak 'original' nums me exist kare, usse double karte raho.
        Approach: Set use karke O(1) lookup.
        Time Complexity:  O(n)
        Space Complexity: O(n)
        """

        st = set(nums)

        while original in st:
            original = original * 2      # double karte raho

        return original
