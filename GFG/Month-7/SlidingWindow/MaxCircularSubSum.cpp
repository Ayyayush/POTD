// ✅ Approach: Kadane's Algorithm (Max + Min separately)
// ✅ T.C. = O(N), S.C. = O(1)

class Solution {
public:

    // Kadane’s algorithm to find maximum subarray sum
    int kadanesMax(vector<int>& nums, int n) {
        int sum = nums[0];                             // current max sum ending here
        int maxSum = nums[0];                          // overall max sum found so far

        for (int i = 1; i < n; i++) {
            sum = max(nums[i], sum + nums[i]);         // either extend the subarray or start new from current
            maxSum = max(maxSum, sum);                 // update the global max
        }

        return maxSum;
    }

    // Kadane’s algorithm to find minimum subarray sum
    int kadanesMin(vector<int>& nums, int n) {
        int sum = nums[0];                             // current min sum ending here
        int minSum = nums[0];                          // overall min sum found so far

        for (int i = 1; i < n; i++) {
            sum = min(nums[i], sum + nums[i]);         // either extend or start new
            minSum = min(minSum, sum);                 // update the global min
        }

        return minSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);    // sum of entire array

        int maxKadane = kadanesMax(nums, n);                       // maximum normal subarray sum
        int minKadane = kadanesMin(nums, n);                       // minimum normal subarray sum

        int circularMax = totalSum - minKadane;                    // max circular subarray sum

        // If all numbers are negative, then circularMax will be 0 which is invalid.
        // So in that case, return the maxKadane itself.
        if (maxKadane > 0)
            return max(maxKadane, circularMax);
        else
            return maxKadane;
    }
};



// ✅ Approach: One loop for Kadane's Max and Min
// ✅ T.C. = O(N), S.C. = O(1)

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);    // Total sum of the array

        int currentMax = nums[0];          // Current max subarray sum ending at i
        int maxSum = nums[0];              // Overall max subarray sum

        int currentMin = nums[0];          // Current min subarray sum ending at i
        int minSum = nums[0];              // Overall min subarray sum

        for (int i = 1; i < n; i++) {
            // Maximum subarray logic
            currentMax = max(nums[i], currentMax + nums[i]);       // Extend or start new
            maxSum = max(maxSum, currentMax);                      // Update overall max

            // Minimum subarray logic
            currentMin = min(nums[i], currentMin + nums[i]);       // Extend or start new
            minSum = min(minSum, currentMin);                      // Update overall min
        }

        int circularMax = totalSum - minSum;                       // Max circular subarray sum

        // If all elements are negative, circularMax will become 0, which is wrong
        if (maxSum > 0)
            return max(maxSum, circularMax);                       // Return the better of two
        else
            return maxSum;                                         // Return non-circular max in negative case
    }
};
