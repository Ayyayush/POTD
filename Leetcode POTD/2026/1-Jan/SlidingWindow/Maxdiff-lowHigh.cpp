#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Approach: Sorting + Sliding Window
    // Time Complexity: O(n log n)
    // Space Complexity: O(1)

    vector<int> nums = {9, 4, 1, 7};
    int k = 2;

    sort(nums.begin(), nums.end());              // Sort the array

    int mindiff = INT_MAX;                        // Initialize with large value

    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (j - i + 1 == k)                       // Window size becomes k
        {
            int diff = nums[j] - nums[i];         // Difference of current window
            mindiff = min(mindiff, diff);         // Update minimum difference
            i++;                                  // Slide the window
        }
    }

    cout << mindiff << endl;
}

int main()
{
    brute();
    return 0;
}
