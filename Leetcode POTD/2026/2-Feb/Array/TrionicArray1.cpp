/**
 * leetcode 3637
 * trionic array 1 
 * 
 * 0<p<q-1 aise ke hona haiye 
 * An array is trionic if there exist indices 0 < p < q < n − 1 such that:

nums[0...p] is strictly increasing,
nums[p...q] is strictly decreasing,
nums[q...n − 1] is strictly increasing.
Return true if nums is trionic, otherwise return false.

 
 * 
 */

// Approach: Simple Simulation
// Idea:
// Traverse the array in three phases:
// 1) Strictly increasing
// 2) Strictly decreasing
// 3) Strictly increasing again
//
// Time Complexity: O(n)        // Single pass through the array
// Space Complexity: O(1)       // No extra space used

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();                          // Size of the array
        int i = 0;                                   // Pointer to traverse the array

        // --------------------------------------------------
        // Phase 1: Strictly Increasing (nums[0...p])
        // --------------------------------------------------
        while (i + 1 < n && nums[i] < nums[i + 1]) { // Move forward while strictly increasing
            i++;
        }

        // If no increasing part OR entire array is increasing
        // then trionic condition fails
        if (i == 0 || i == n - 1) {
            return false;
        }

        // --------------------------------------------------
        // Phase 2: Strictly Decreasing (nums[p...q])
        // --------------------------------------------------
        while (i + 1 < n && nums[i] > nums[i + 1]) { // Move forward while strictly decreasing
            i++;
        }

        // If we reached the end here, no final increasing part exists
        if (i == n - 1) {
            return false;
        }

        // --------------------------------------------------
        // Phase 3: Strictly Increasing (nums[q...n-1])
        // --------------------------------------------------
        while (i + 1 < n && nums[i] < nums[i + 1]) { // Move forward while strictly increasing again
            i++;
        }

        // Valid trionic array only if we exactly end at last index
        return i == n - 1;
    }
};
