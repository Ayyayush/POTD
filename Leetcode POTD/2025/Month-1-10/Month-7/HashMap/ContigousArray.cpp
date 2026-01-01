#include <bits/stdc++.h>
using namespace std;

void better()
{
    // Time Complexity: O(N)                       // Har element ke liye ek hi baar kaam ho raha
    // Space Complexity: O(N)                      // Map me har prefix sum ek baar ja raha max

    vector<int> nums = {0, 1, 0, 1, 1, 0};         // Sample input
    unordered_map<int, int> mp;                   // Prefix sum -> first index
    mp[0] = -1;                                    // Base case: sum 0 before array starts

    int currsum = 0, maxlength = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0)
            currsum -= 1;                          // 0 ko -1 count karo
        else
            currsum += 1;                          // 1 ko +1 count karo

        if (mp.count(currsum)) {
            maxlength = max(maxlength, i - mp[currsum]);   // Length of subarray
        } else {
            mp[currsum] = i;                       // Store first occurrence of sum
        }
    }

    cout << "Maximum length of equal 0s and 1s subarray: " << maxlength << endl;
}

int main()
{
    better();
    return 0;
}
