#include <bits/stdc++.h>
using namespace std;

void better()
{
    // Time Complexity: O(N)                 // sliding window with two pointers
    // Space Complexity: O(N)                // map stores last index of elements

    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];                     // input array
    }

    unordered_map<int, int> mp;             // store last occurrence index
    long long maxsum = 0, sum = 0;          // to track maximum sum
    int i = 0, j = 0;

    while (j < nums.size())
    {
        if (mp.count(nums[j]) && mp[nums[j]] >= i)  // duplicate mila and valid hai
        {
            // Remove all elements from i to mp[nums[j]] from sum
            while (i <= mp[nums[j]])
            {
                sum -= nums[i];             // remove from sum
                i++;                        // window shrink
            }
        }

        sum += nums[j];                     // current element add karo
        mp[nums[j]] = j;                    // last index update karo
        maxsum = max(maxsum, sum);          // max sum update karo
        j++;                                // window grow karo
    }

    cout << maxsum << endl;                 // final output
}

int main()
{
    better();
    return 0;
}
