#include <bits/stdc++.h>
using namespace std;

void brute()    
{
    // 🔹 Approach: Brute Force - sabhi subarrays banake AND nikalna
    // 🔹 Time Complexity: O(N^2)
    // 🔹 Space Complexity: O(1)

    int n;
    cin >> n;                                      // Array size input lo

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];    // Array elements input lo

    int maxsize = 0;                               // Longest subarray size store karega
    int maxbit = INT_MIN;                          // Maximum AND value store karega

    for (int i = 0; i < n; i++)
    {
        int result = nums[i];                      // Subarray ka starting element
        int count = 0;                             // Current subarray length

        for (int j = i; j < n; j++)
        {
            result &= nums[j];                     // AND karte jao current element ke saath
            count++;                               // Subarray length increase karo

            if (result == maxbit)                  // Agar same max AND mila toh size check karo
            {
                maxsize = max(maxsize, count);
            }
            else if (result > maxbit)              // Agar naya max AND mila toh usko update karo
            {
                maxbit = result;
                maxsize = count;
            }
        }
    }

    cout << maxsize << endl;                       // Final answer print karo
}

/**
 * BETTER THOUGHT PROCESS
 * a1 & a2 is always <= (a1 and a2) 
 * kbhi bhi ye bada nhi ho skta 
 * toh simply maximum and ussi subarray jka na hoga jaha max elet ho array ka 
 * line se jitne max elt honge whi max length banega subarray ka 
 * 
 */


 
void better()
{
    // 🔹 Approach: Optimized Linear Scan
    // 🔹 T.C = O(N), S.C = O(1)
    // 🔹 Logic: Sirf max element ke continuous streak ko track karna hai

    int n;
    cin >> n;                                     // Array size input lo

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];   // Array elements input lo

    int maxval = 0;                               // Maximum element track karega
    int result = 0;                               // Max length of subarray with all max elements
    int streak = 0;                               // Current streak of max element

    for (int i = 0; i < n; i++)
    {
        int num = nums[i];

        if (num > maxval)                         // Naya max mila toh reset everything
        {
            maxval = num;
            result = 0;
            streak = 1;                           // Streak ko 1 se start karo
        }
        else if (num == maxval)                   // Same max mila toh streak badhao
        {
            streak++;
        }
        else                                       // Chota element mila toh streak tod do
        {
            streak = 0;
        }

        result = max(result, streak);             // Max streak ko update karo
    }

    cout << result << endl;                       // Final answer print karo
}

int main()
{
    better();
    return 0;
}
