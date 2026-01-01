#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(n)                     // 1 baar array traverse kar rahe hain
    // Space Complexity: O(1)                    // Koi extra space use nahi ho raha

    int n;
    cin >> n;
    vector<int> arr(n);                          // Input array
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (n == 1)                                  // Ek element ka array ka max turbulence size 1 hi hoga
    {
        cout << 1 << endl;
        return;
    }

    int count = 1, maxcount = 1;

    for (int i = 1; i < n; i++)
    {
        if (i >= 2 && ((arr[i - 2] < arr[i - 1] && arr[i - 1] > arr[i]) || 
                       (arr[i - 2] > arr[i - 1] && arr[i - 1] < arr[i])))    // 3 elements ka alternating pattern check
        {
            count++;                                  // Pattern continue ho raha
        }
        else if (arr[i] != arr[i - 1])                // Agar aage pichle element equal nahi hain
        {
            count = 2;                                // New alternating sequence start
        }
        else
        {
            count = 1;                                // Sequence break ho gaya
        }

        maxcount = max(maxcount, count);              // Max turbulence update karte jao
    }

    cout << maxcount << endl;
}

int main()
{
    brute();
    return 0;
}
