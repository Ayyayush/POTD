#include <bits/stdc++.h>
using namespace std;

/*
============================================================
BRUTE FORCE APPROACH
Approach Name: Generate all subarrays
Time Complexity: O(N^2)
Space Complexity: O(1)

Idea:
- Generate every possible subarray
- Compute sum for each subarray
- If sum == goal → count it

Works for all arrays but very slow.
============================================================
*/
void brute()
{
    int n, goal;
    cin >> n >> goal;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int count = 0;

    for(int i = 0; i < n; i++)                      // starting index
    {
        int sum = 0;
        for(int j = i; j < n; j++)                  // ending index
        {
            sum += nums[j];                         // calculate subarray sum

            if(sum == goal)
                count++;                            // valid subarray
        }
    }

    cout << count;
}

/*
============================================================
BETTER APPROACH
Approach Name: Prefix Sum + Hash Map
Time Complexity: O(N)
Space Complexity: O(N)

Key Idea:
- Let prefixSum[i] = sum of elements till index i
- If prefixSum[j] - prefixSum[i] = goal
  → subarray (i+1 to j) has sum = goal

Used when array is NOT restricted to binary.
============================================================
*/
void better()
{
    int n, goal;
    cin >> n >> goal;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    unordered_map<int,int> mp;                      // stores prefix sum frequency
    mp[0] = 1;                                      // base case

    int prefixSum = 0;
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        prefixSum += nums[i];

        if(mp.count(prefixSum - goal))
            count += mp[prefixSum - goal];

        mp[prefixSum]++;
    }

    cout << count;
}

/*
============================================================
OPTIMAL APPROACH
Approach Name: Sliding Window + Prefix Zeros (Binary Array)
Time Complexity: O(N)
Space Complexity: O(1)

IMPORTANT:
- Works ONLY because the array is binary (0s and 1s)

Core Concept:
- When window sum == goal
- Multiple subarrays can be formed by removing leading zeros
- prefix_zeros stores how many such zeros exist

Why NOT j - i + 1?
- Because NOT all subarrays inside the window have exact sum = goal
============================================================
*/
void optimal()
{
    int n, goal;
    cin >> n >> goal;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int prefix_zeros = 0;                           // count of removable leading zeros
    int window_sum = 0;                             // sum of current window
    int count = 0;

    int i = 0, j = 0;                               // sliding window pointers

    while(j < n)
    {
        window_sum += nums[j];                      // expand window

        /*
        Shrink window if:
        1) sum becomes greater than goal
        2) leading element is zero (safe to remove)
        */
        while(i < j && (nums[i] == 0 || window_sum > goal))
        {
            if(nums[i] == 1)
                prefix_zeros = 0;                   // removing 1 breaks prefix count
            else
                prefix_zeros++;                     // one more zero can be skipped

            window_sum -= nums[i];                  // shrink window
            i++;
        }

        /*
        If exact sum achieved:
        - 1 valid subarray with current window
        - +prefix_zeros more by skipping zeros
        */
        if(window_sum == goal)
            count += 1 + prefix_zeros;

        j++;                                        // move right pointer
    }

    cout << count;
}

int main()
{
    // Uncomment the version you want to run

    // brute();
    // better();
    optimal();

    return 0;
}
