#include <bits/stdc++.h>
using namespace std;

/*
============================================================
BRUTE FORCE APPROACH
Approach Name: Generate all subarrays
Time Complexity: O(N^2)
Space Complexity: O(1)

Idea:
- Fix a starting index i
- Extend subarray till j
- Count odd numbers in each subarray
- If odd count == k → valid subarray

Example:
nums = [1,1,2,1,1], k = 3

Subarray [1,1,2,1] → odd count = 3 ✅
Subarray [1,2,1,1] → odd count = 3 ✅
Answer = 2
============================================================
*/
void brute()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int subcount = 0;                            // total valid subarrays

    for(int i = 0; i < n; i++)                  // starting index
    {
        int oddCount = 0;                       // odd numbers in current subarray

        for(int j = i; j < n; j++)              // ending index
        {
            if(nums[j] % 2 != 0)
                oddCount++;                     // count odd numbers

            if(oddCount == k)
                subcount++;                     // valid subarray found
        }
    }

    cout << subcount;
}

/*
============================================================
BETTER APPROACH
Approach Name: Prefix Sum + Hash Map
Time Complexity: O(N)
Space Complexity: O(N)

Key Observation:
- Convert problem into:
  "Count subarrays with sum = k"
- Treat odd number as 1, even as 0

oddCount → prefix sum of odd numbers

Formula:
If currentOdd - k exists earlier,
then a subarray with k odds exists.

Example:
nums = [1,1,2,1,1], k = 3

Prefix oddCount:
Index: 0 1 2 3 4
Odds : 1 2 2 3 4

At oddCount = 3
Check (3 - 3) = 0 → exists → valid
============================================================
*/
void better()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    unordered_map<int,int> mp;                  // stores frequency of oddCount
    int oddCount = 0;                            // prefix sum of odd numbers
    int result = 0;

    mp[0] = 1;                                   // base case: before array starts

    for(int i = 0; i < n; i++)
    {
        oddCount += (nums[i] % 2);               // add 1 if odd, 0 if even

        if(mp.count(oddCount - k))
        {
            result += mp[oddCount - k];          // add possible subarrays
        }

        mp[oddCount]++;                          // store current prefix
    }

    cout << result;
}

/*
============================================================
OPTIMAL APPROACH
Approach Name: Sliding Window (Two Pointers)
Time Complexity: O(N)
Space Complexity: O(1)

Core Idea:
- Count subarrays with EXACTLY k odd numbers
- Maintain a window [i...j]
- When oddCount == k:
    Count how many valid starting points exist

prevCount:
- Counts how many times we can shift left pointer
  while keeping k odd numbers

Example:
nums = [1,1,2,1,1], k = 3

Valid windows:
[1,1,2,1]
[1,2,1,1]
============================================================
*/
void optimal()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int oddCount = 0;                            // current odd count in window
    int prevCount = 0;                           // valid left shifts
    int result = 0;

    int i = 0, j = 0;                            // sliding window pointers

    while(j < n)
    {
        if(nums[j] % 2 != 0)
        {
            oddCount++;                          // new odd enters window
            prevCount = 0;                       // reset left possibilities
        }

        while(oddCount == k)
        {
            prevCount++;                         // one valid starting point

            if(nums[i] % 2 != 0)
                oddCount--;                      // removing an odd breaks window

            i++;                                 // shrink window from left
        }

        result += prevCount;                     // add all valid subarrays ending at j
        j++;                                     // expand window
    }

    cout << result;
}

int main()
{
    // Uncomment the approach you want to run

    // brute();
    // better();
    optimal();

    return 0;
}
