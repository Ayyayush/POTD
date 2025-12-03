#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // T.C. = O(N^2), S.C. = O(1)                            🟠 Brute Force Approach
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int maxsum = INT_MIN;                                  // initially very small
    for (int i = 0; i < n; i++)
    {
        int sum = 0;                                        // start fresh from index i
        for (int j = i; j < n; j++)
        {
            sum += nums[j];                                 // add jth element
            maxsum = max(maxsum, sum);                      // update maxsum
        }
    }
    cout << maxsum << endl;
}

void better()
{
    // T.C. = O(N), S.C. = O(1)                              🟢 Kadane’s Algorithm
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int currsum = 0, maxsum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currsum += nums[i];                                // add current element
        maxsum = max(maxsum, currsum);                     // update max sum
        if (currsum < 0)                                   // if sum becomes negative, discard
        {
            currsum = 0;
        }
    }
    cout << maxsum << endl;
}

int main()
{
    // brute();
    better();
    return 0;
}
