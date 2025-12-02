#include <bits/stdc++.h>
using namespace std;

// T.C: O(N), S.C: O(1) ............................ Kadane's Algorithm for max & min subarray sum separately
void brute()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int currSubSum = nums[0], maxSubSum = nums[0];

    // Kadane's Algorithm to find max subarray sum
    for (int i = 1; i < n; i++)
    {
        currSubSum = max(nums[i], currSubSum + nums[i]); // Maximum sum till index i
        maxSubSum = max(maxSubSum, currSubSum);          // Store maximum encountered sum
    }

    int minSubSum = nums[0];
    currSubSum = nums[0];

    // Kadane's Algorithm to find min subarray sum
    for (int i = 1; i < n; i++)
    {
        currSubSum = min(nums[i], currSubSum + nums[i]); // Minimum sum till index i
        minSubSum = min(minSubSum, currSubSum);          // Store minimum encountered sum
    }

    cout << max(maxSubSum, abs(minSubSum)) << endl;
}


// T.C: O(N), S.C: O(1) ............................ Optimized approach (Single Pass Kadane's Algorithm)
void optimal()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int maxSum = nums[0], minSum = nums[0];
    int currSumMax = nums[0], currSumMin = nums[0];

    for (int i = 1; i < n; i++)
    {
        currSumMax = max(nums[i], currSumMax + nums[i]); // Kadane's for max subarray sum
        maxSum = max(maxSum, currSumMax);

        currSumMin = min(nums[i], currSumMin + nums[i]); // Kadane's for min subarray sum
        minSum = min(minSum, currSumMin);
    }

    cout << max(maxSum, abs(minSum)) << endl;
}

int main()
{
    optimal();
    return 0;
}
