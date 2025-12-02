#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // ✅ LeetCode 1588 - Sum of All Odd Length Subarrays
    // 🔗 https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
    // ✅ T.C = O(n^3)         (3 nested loops: start, end, sum)
    // ✅ S.C = O(n)           (temporary vector used for subarrays)

    vector<int> arr = {1, 4, 2, 5, 3};
    int n = arr.size();
    int sumodd = 0;

    for (int i = 0; i < n; i++)                          // starting index of subarray
    {
        vector<int> vec;
        for (int j = i; j < n; j++)                      // ending index of subarray
        {
            vec.push_back(arr[j]);                       // push element into current subarray

            if (vec.size() % 2 != 0)                     // agar subarray length odd hai
            {
                for (int k = 0; k < vec.size(); k++)     // subarray ka sum le lo
                {
                    sumodd += vec[k];
                }
            }
        }
    }

    cout << "Brute: " << sumodd << endl;
}

void better()
{
    // ✅ T.C = O(n^2)         (2 nested loops)
    // ✅ S.C = O(1)           (no extra space except vars)

    vector<int> arr = {1, 4, 2, 5, 3};
    int n = arr.size();
    int sumodd = 0, totalsum = 0;

    for (int i = 0; i < n; i++)                         // subarray starting index
    {
        sumodd = 0;
        for (int j = i; j < n; j++)                     // subarray ending index
        {
            sumodd += arr[j];                           // accumulate running sum
            int len = j - i + 1;                        // current subarray length
            if (len % 2 != 0)                           // agar length odd hai
            {
                totalsum += sumodd;                     // toh sum add kar do
            }
        }
    }

    cout << "Better: " << totalsum << endl;
}

void optimal()
{
    // ✅ T.C = O(n)           (single loop)
    // ✅ S.C = O(1)           (no extra space)
    // ✅ Approach: Element Contribution in odd-length subarrays

    vector<int> arr = {1, 4, 2, 5, 3};
    int n = arr.size();
    int result = 0;

    for (int i = 0; i < n; ++i)
    {
        int totalSubarrays = (i + 1) * (n - i);                // total subarrays in which arr[i] is present
        int oddSubarrays = (totalSubarrays + 1) / 2;           // only odd-length subarrays
        result += arr[i] * oddSubarrays;                       // add contribution
    }

    cout << "Optimal: " << result << endl;
}

int main()
{
    brute();
    better();
    optimal();
    return 0;
}
