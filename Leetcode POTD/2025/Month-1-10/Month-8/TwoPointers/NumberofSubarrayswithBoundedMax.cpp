#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // T.C = O(n^2), S.C = O(1)
    // Naive approach: check all subarrays and find their max

    vector<int> nums = {2, 1, 4, 3};
    int left = 2, right = 3;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int maxi = nums[i];
        for (int j = i; j < nums.size(); j++)
        {
            maxi = max(maxi, nums[j]);               // current subarray ka max update karo
            if (maxi >= left && maxi <= right)       // agar max left-right range mein hai
                count++;                             // valid subarray mila
            else if (maxi > right)                   // agar max right se bada hai, toh baad wale bhi invalid honge
                break;
        }
    }

    cout << count << endl;
}

int countSubarraysWithMaxAtMost(vector<int> &nums, int bound)
{
    // T.C = O(n), S.C = O(1)
    // Sliding-style count for subarrays jinka max <= bound

    int count = 0, result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= bound)
        {
            count++;                    // subarray ko extend kar sakte ho
        }
        else
        {
            count = 0;                  // reset kar do jab bound cross ho
        }
        result += count;                // count add karo
    }
    return result;
}

void better()
{
    // T.C = O(n), S.C = O(1)
    // Count(subarrays with max ≤ right) - Count(subarrays with max < left)

    vector<int> nums = {2, 1, 4, 3};
    int left = 2, right = 3;

    int total = countSubarraysWithMaxAtMost(nums, right)
              - countSubarraysWithMaxAtMost(nums, left - 1);

    cout << total << endl;
}

int main()
{
    // brute();        // Brute-force version
    better();         // Optimized version

    return 0;
}
