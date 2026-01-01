#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int count = 1;
    int maxcount = 1;
    for (int i = 0; i < nums.size(); i++)
    {
       
        for (int j = i; j < nums.size(); j++)
        {
            if (j + 1 < nums.size() && (nums[j] & nums[j + 1]) == 0)
            {
                cout << nums[j] << " " << nums[j + 1] << endl;
                count++;
                maxcount = max(count, maxcount);
            }
            else
            {
               count=0;
            }
        }
    }

    cout << maxcount << endl;
}

// ✅ TC: O(N^3)      ✅ SC: O(1)
bool isNice(vector<int> &nums, int start, int end)
{
    int mask = 0;
    for (int i = start; i <= end; i++)
    {
        if ((mask & nums[i]) != 0)
            return false; // Agar koi bhi bit overlap ho gayi toh invalid hai
        mask |= nums[i];  // Mask me current element add kar rahe hain
    }
    return true;
}


// void brute()
// {
//     vector<int> nums = {1, 2, 3, 1, 4, 5}; // Example input

//     int n = nums.size();
//     int result = 0;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             if (isNice(nums, i, j))
//             {
//                 result = max(result, j - i + 1);
//             }
//             else
//             {
//                 break; // Agar ek bhi fail ho gaya toh aage check karne ki zarurat nahi
//             }
//         }
//     }
//     cout << "Brute Force Result: " << result << endl;
// }

// ✅ TC: O(N^2)      ✅ SC: O(1)
void better()
{
    vector<int> nums = {1, 2, 3, 1, 4, 5}; // Example input

    int n = nums.size();
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        int mask = 0;
        for (int j = i; j < n; j++)
        {
            if ((mask & nums[j]) != 0)
                break; // Agar bit overlap ho gayi toh break karna padega
            result = max(result, j - i + 1);
            mask |= nums[j]; // Mask update karna hoga
        }
    }
    cout << "Better Approach Result: " << result << endl;
}

// ✅ TC: O(N) (Sliding Window)      ✅ SC: O(1)
void optimal()
{
    vector<int> nums = {1, 2, 3, 1, 4, 5}; // Example input

    int n = nums.size();
    int i = 0, j = 0, result = 1, mask = 0;

    while (j < n)
    {
        while ((mask & nums[j]) != 0)
        { // Jab tak overlap ho raha hai, window ko shrink karo
            mask ^= nums[i];
            i++;
        }
        result = max(result, j - i + 1);
        mask |= nums[j]; // Mask update karo
        j++;
    }
    cout << "Optimal Approach Result: " << result << endl;
}

int main()
{
    brute();
    return 0;
}
