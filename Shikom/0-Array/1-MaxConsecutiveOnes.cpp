#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------------
BRUTE FORCE APPROACH
Approach: Generate all subarrays and count consecutive 1s
Time Complexity: O(N^2)
Space Complexity: O(1)
------------------------------------------------------------
*/
void brute()
{
    int n;                                      // size of array
    cin >> n;

    vector<int> arr(n);                         // input array
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int maxi = 0;                               // stores maximum consecutive ones

    for(int i = 0; i < n; i++)                  // starting index
    {
        int count = 0;                          // count for current subarray
        for(int j = i; j < n; j++)              // ending index
        {
            if(arr[j] == 1)
                count++;                        // increment if 1 found
            else
                break;                          // stop if 0 encountered

            maxi = max(maxi, count);            // update maximum
        }
    }

    cout << maxi;
}

/*
------------------------------------------------------------
BETTER APPROACH
Approach: Traverse array and count consecutive 1s
Time Complexity: O(N)
Space Complexity: O(1)
------------------------------------------------------------
*/
void better()
{
    int n;                                      // size of array
    cin >> n;

    vector<int> arr(n);                         // input array
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int count = 0;                              // current consecutive ones
    int maxi = 0;                               // maximum consecutive ones

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 1)
        {
            count++;                            // extend current sequence
            maxi = max(maxi, count);            // update maximum
        }
        else
        {
            count = 0;                          // reset on zero
        }
    }

    cout << maxi;
}

/*
------------------------------------------------------------
OPTIMAL APPROACH
Approach: Single pass greedy counting
Time Complexity: O(N)
Space Complexity: O(1)
------------------------------------------------------------
*/
void optimal()
{
    int n;                                      // size of array
    cin >> n;

    vector<int> arr(n);                         // input array
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int count = 0;                              // tracks current streak
    int maxi = 0;                               // stores answer

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 1)
            count++;                            // increase streak
        else
            count = 0;                          // reset streak

        maxi = max(maxi, count);                // update answer
    }

    cout << maxi;
}

int main()
{
    // Call the required function here
    // brute();
    // better();
    optimal();

    return 0;
}
