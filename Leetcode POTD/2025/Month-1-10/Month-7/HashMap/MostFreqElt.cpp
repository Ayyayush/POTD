#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(N logN + N) ≈ O(N logN)        // Sorting + single pass
    // Space Complexity: O(N)                            // Unordered map storage

    vector<int> nums = {1, 2, 4};                        // Sample input
    int k = 5;                                           // Sample k

    sort(nums.rbegin(), nums.rend());                   // Descending sort

    unordered_map<int, int> mp;                         // Frequency map
    mp[nums[0]]++;

    for (int i = 1; i < nums.size(); i++) {
        int diff = nums[0] - nums[i];

        if (k - diff >= 0) {
            nums[i] += diff;                             // Increase nums[i] by required diff
            k -= diff;                                   // Decrease k accordingly
        }

        mp[nums[i]]++;

        if (k <= 0) break;                               // No operations left
    }

    int maximum = 0;
    for (auto it : mp) {
        maximum = max(maximum, it.second);              // Find max frequency
    }

    cout << "Maximum Frequency: " << maximum << endl;
}

int main()
{
    brute();
    return 0;
}
