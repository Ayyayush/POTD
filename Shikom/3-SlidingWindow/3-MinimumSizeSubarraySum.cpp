#include <bits/stdc++.h>
using namespace std;

void brute() 
{
    // Approach: Brute Force (Check all subarrays)
    // Time Complexity: O(N^2)         			// two loops
    // Space Complexity: O(1)          			// no extra space

    int n, target;
    cin >> n >> target;            			// take input inside function (as per user rule)
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    int minlength = INT_MAX;

    for(int i = 0; i < n; i++) {
        long long sum = 0;
        for(int j = i; j < n; j++) {
            sum += nums[j];             			// adding elements to current subarray
            if(sum >= target) {
                minlength = min(minlength, j - i + 1);
                break;                  			// break early because adding more elements only increases length
            }
        }
    }

    if(minlength == INT_MAX) cout << 0;
    else cout << minlength;
}

void better() 
{
    // Approach: Prefix Sum + Binary Search
    // Time Complexity: O(N log N)       		// binary search for each index
    // Space Complexity: O(N)            		// prefix array

    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<long long> prefix(n + 1, 0);

    // prefix[i] = sum of nums[0..i-1]
    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + nums[i-1];    	// building prefix sums
    }

    int minlength = INT_MAX;

    for(int i = 0; i < n; i++) {
        long long req = target + prefix[i];     	// we need prefix[j] >= prefix[i] + target

        // binary search for the lowest j such that prefix[j] >= req
        int j = lower_bound(prefix.begin(), prefix.end(), req) - prefix.begin();

        if(j <= n) {
            minlength = min(minlength, j - i);
        }
    }

    if(minlength == INT_MAX) cout << 0;
    else cout << minlength;
}

void optimal() 
{
    // Approach: Sliding Window (Two Pointers)
    // Time Complexity: O(N)            		// each pointer moves at most N steps
    // Space Complexity: O(1)            		// no extra memory

    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    int minlength = INT_MAX;
    long long sum = 0;

    int i = 0, j = 0;

    while(j < n)
    {
        sum += nums[j];               			// expand window

        while(sum >= target)          			// shrink window from left
        {
            minlength = min(minlength, j - i + 1);
            sum -= nums[i];
            i++;
        }

        j++;                          			// expand right pointer
    }

    if(minlength == INT_MAX) cout << 0;
    else cout << minlength;
}

int main()
{
    return 0;
}


import bisect
from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:

        n = len(nums)

        # Build prefix sum array
        prefix = [0] * (n + 1)
        for i in range(1, n + 1):
            prefix[i] = prefix[i - 1] + nums[i - 1]

        minlength = float('inf')

        for i in range(n):
            req = target + prefix[i]            # Required prefix value to reach target

            j = bisect.bisect_left(prefix, req) # Same as lower_bound

            if j <= n:
                minlength = min(minlength, j - i)

        return 0 if minlength == float('inf') else minlength
