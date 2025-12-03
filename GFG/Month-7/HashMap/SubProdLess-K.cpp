class Solution {
public:
    // Time Complexity: O(N)              // Ek pass mein hi sab handle ho raha hai
    // Space Complexity: O(1)              // Sirf prod aur 2 pointers use ho rahe hain

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;                    // Edge case: k=0 ya k=1 ke liye koi product < k nahi ho sakta

        int i = 0, j = 0, count = 0;
        long long prod = 1;

        while (j < nums.size()) {
            prod *= nums[j];                      // Window mein element multiply karo

            while (prod >= k && i <= j) {         // Jab tak product bada ho, left shrink karo
                prod /= nums[i];
                i++;
            }

            count += (j - i + 1);                 // Har valid window ke subarrays count karo

            j++;
        }

        return count;
    }
};