#include <bits/stdc++.h>
using namespace std;

/*
 * 🔴 Brute Force Approach – Greedy Matching Left and Right for Each Cop
 * Time Complexity  : O(N * K)         // Har policeman ke liye max K range mein thief dhoondhna hai
 * Space Complexity : O(1)             // Extra space nahi lagta, in-place mark karte hain
 */
void brute()
{
    vector<char> copsAndThieves = {'T', 'T', 'P', 'P', 'T', 'P'};  // Hardcoded input
    int k = 2;                                                     // Max range to catch

    int totalCaught = 0;

    for (int i = 0; i < copsAndThieves.size(); i++)
    {
        if (copsAndThieves[i] == 'P')
        {
            bool caught = false;

            // Left scan
            for (int j = i - k; j < i && !caught; j++)
            {
                if (j >= 0 && copsAndThieves[j] == 'T')
                {
                    copsAndThieves[j] = '{';  // Mark thief as caught
                    totalCaught++;
                    caught = true;
                }
            }

            // Right scan
            for (int j = i + 1; j <= i + k && !caught; j++)
            {
                if (j < copsAndThieves.size() && copsAndThieves[j] == 'T')
                {
                    copsAndThieves[j] = '{';  // Mark thief as caught
                    totalCaught++;
                    caught = true;
                }
            }
        }
    }

    cout << "Brute Answer: " << totalCaught << endl;
}


/*
 * 🟢 Better Approach – Two Pointers (One for Cop, One for Thief)
 * Time Complexity  : O(N)             // Har pointer ek element sirf ek baar traverse karta hai
 * Space Complexity : O(1)             // Sirf pointers and counter use kar rahe hain
 */
void better()
{
    vector<char> arr = {'T', 'T', 'P', 'P', 'T', 'P'};  // Hardcoded input
    int k = 2;
    int n = arr.size();

    int i = 0;     // Pointer for policeman
    int j = 0;     // Pointer for thief
    int count = 0;

    while (i < n && j < n)
    {
        // Move i to next policeman
        while (i < n && arr[i] != 'P') i++;

        // Move j to next thief
        while (j < n && arr[j] != 'T') j++;

        // If both found and distance is valid
        if (i < n && j < n && abs(i - j) <= k)
        {
            count++;
            i++;
            j++;
        }
        else if (j < n && j < i)
        {
            j++;  // Thief too far left
        }
        else if (i < n && i < j)
        {
            i++;  // Cop too far left
        }
    }

    cout << "Better Answer: " << count << endl;
}


/*
 * MAIN FUNCTION
 */
int main()
{
    brute();    // Call brute force version
    better();   // Call better (two-pointer) version

    return 0;
}
