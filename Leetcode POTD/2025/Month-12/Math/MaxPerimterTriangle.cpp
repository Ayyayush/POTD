#include <bits/stdc++.h>
using namespace std;

void brute() 
{
    /*
        APPROACH: Check all possible triplets (Brute Force)
        T.C. = O(n^3)
        S.C. = O(1)
    */

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());                         // sort array for consistency

    int maxpmt = 0;

    for (int i = 0; i < n; i++)                             // pick first side
    {
        for (int j = i + 1; j < n; j++)                     // pick second side
        {
            for (int k = j + 1; k < n; k++)                 // pick third side
            {
                int a = nums[i];
                int b = nums[j];
                int c = nums[k];

                // full triangle check (needed because order not guaranteed)
                if (a + b > c && a + c > b && b + c > a)    
                {
                    maxpmt = max(maxpmt, a + b + c);        // update maximum perimeter
                }
            }
        }
    }

    cout << maxpmt;
}

void optimal()
{
    /*
        APPROACH: Greedy + Sorting  
        After sorting, for any 3 sides a ≤ b ≤ c:
            Only need to check: a + b > c  
        T.C. = O(n log n)
        S.C. = O(1)
    */

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());                         // sort ascending

    // Check triplets from end → largest numbers first
    for(int k = n - 1; k >= 2; k--)
    {
        int a = nums[k - 2];                                // smallest in the triple
        int b = nums[k - 1];                                // middle
        int c = nums[k];                                    // largest side

        if(a + b > c)                                       // valid triangle condition
        {
            cout << (a + b + c);                            // print and return immediately
            return;
        }
    }

    cout << 0;                                               // no triangle found
}

int main()
{
    // brute();
    optimal();
    return 0;
}
