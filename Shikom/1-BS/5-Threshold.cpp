#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ----------------------------------------------------------
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Helper function to check if divisor is valid
    // ----------------------------------------------------------
    bool find(vector<int>& nums, int divisor, int threshold)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += (nums[i] + divisor - 1) / divisor;   // ceil division
        }

        return sum <= threshold;
    }

    
    // ----------------------------------------------------------
    // Time Complexity: O(n * max(nums))
    // Space Complexity: O(1)
    // Brute force: Try all divisors from 1 to max(nums)
    // ----------------------------------------------------------
    int smallestDivisor(vector<int>& nums, int threshold) {
        int result = INT_MAX;
        int maxnum = *max_element(nums.begin(), nums.end());

        for (int i = 1; i <= maxnum; i++)
        {
            if (find(nums, i, threshold))
            {
                result = i;
                break;
            }
        }

        return result;
    }
};










// =================================================================
// ======================= OPTIMAL SOLUTION =========================
// =================================================================

class SolutionOptimal {
public:

    // ----------------------------------------------------------
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Helper function for binary search
    // ----------------------------------------------------------
    bool isPossible(vector<int> &nums, int divisor, int threshold) 
    {
        int sum = 0;

        for (int x : nums)
        {
            sum += (x + divisor - 1) / divisor;     // ceil division
            if (sum > threshold) return false;      // Early stop
        }

        return sum <= threshold;
    }


    // ----------------------------------------------------------
    // Approach: Binary Search on Answer
    // Time Complexity: O(n · log(max(nums)))
    // Space Complexity: O(1)
    // ----------------------------------------------------------
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (isPossible(nums, mid, threshold))
            {
                ans = mid;
                right = mid - 1;      
            }
            else
            {
                left = mid + 1;       
            }
        }

        return ans;
    }
};





class Solution:

    # ----------------------------------------------------------
    # Time Complexity: O(n)
    # Space Complexity: O(1)
    # Helper function to check if a divisor is valid
    # ----------------------------------------------------------
    def find(self, nums, divisor, threshold):

        total = 0
        for x in nums:
            total += (x + divisor - 1) // divisor      # ceil division

        return total <= threshold


    # ----------------------------------------------------------
    # Time Complexity: O(n * max(nums))
    # Space Complexity: O(1)
    # Brute force: Try all divisors from 1 to max(nums)
    # ----------------------------------------------------------
    def smallestDivisor(self, nums, threshold):

        result = float('inf')
        maxnum = max(nums)

        for d in range(1, maxnum + 1):
            if self.find(nums, d, threshold):
                result = d
                break

        return result
