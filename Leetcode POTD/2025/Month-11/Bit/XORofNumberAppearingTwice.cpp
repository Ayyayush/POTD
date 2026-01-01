#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Problem: Find XOR of all numbers which appear twice in the array
// Example: nums = [1,2,3,2,4,1] → duplicates = [1,2] → XOR = 1^2 = 3
/////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Brute (Nested Loops)
// Logic: Har element ke liye array me count karo, jo 2 baar aaye unhe XOR karo
// T.C. => O(n^2)          (Nested loop)
// S.C. => O(1)            (Extra space nahi use hota)
/////////////////////////////////////////////////////////////////////////////////////////////////////

void brute()
{
    vector<int> nums = {1, 2, 3, 2, 4, 1};
    vector<int> duplicates;

    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
                count++;
        }
        if (count == 2) duplicates.push_back(nums[i]);
    }

    int xr = 0;
    for (int x : duplicates)
        xr ^= x;                          // XOR all duplicate elements

    cout << "Duplicate Numbers XOR (Brute): " << xr << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach
