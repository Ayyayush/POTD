#include <bits/stdc++.h>
using namespace std;

void brute()     
{
    // Approach: Brute Force (O(n^2))
    // TC: O(n^2), SC: O(1)

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    double maxAvg = -1e18;             // handles negative values

    for(int i = 0; i < n; i++)
    {
        double sum = 0;

        for(int j = i; j < n; j++)
        {
            sum += nums[j];

            if((j - i + 1) == k)       // window size reached
            {
                double avg = sum / k;
                maxAvg = max(maxAvg, avg);
            }
        }
    }

    cout << maxAvg;
}

void better()    
{
    // Approach: Prefix Sum (Better)
    // TC: O(n), SC: O(n)

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<long long> prefix(n + 1, 0);

    for(int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + nums[i];   // prefix building

    double maxAvg = -1e18;

    for(int i = 0; i + k <= n; i++)
    {
        long long sum = prefix[i + k] - prefix[i];  // subarray sum using prefix
        double avg = (double)sum / k;
        maxAvg = max(maxAvg, avg);
    }

    cout << maxAvg;
}

void optimal()    
{
    // Approach: Sliding Window
    // TC: O(n), SC: O(1)

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    long long windowSum = 0;

    // first window sum
    for(int i = 0; i < k; i++)
        windowSum += nums[i];

    double maxAvg = (double)windowSum / k;

    // sliding window
    for(int i = k; i < n; i++)
    {
        windowSum += nums[i];             // add new element
        windowSum -= nums[i - k];         // remove old element

        double avg = (double)windowSum / k;
        maxAvg = max(maxAvg, avg);
    }

    cout << maxAvg;
}

int main()
{
    // choose function to run here manually if needed
    // brute();
    // better();
    // optimal();

    return 0;
}


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        n = len(nums)

        # build prefix sum array
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]

        maxAvg = -1e18

        for i in range(0, n - k + 1):
            total = prefix[i + k] - prefix[i]
            avg = total / k
            maxAvg = max(maxAvg, avg)

        return maxAvg
