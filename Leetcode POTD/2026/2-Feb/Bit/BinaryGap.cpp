#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
                    BINARY GAP
===========================================================

🔹 Problem Link:
https://leetcode.com/problems/binary-gap/

🔹 Description:
Given a positive integer n, find the maximum distance between
two consecutive 1's in the binary representation of n.
If there are less than two 1's, return 0.

🔹 Constraints:
1 <= n <= 10^9

-----------------------------------------------------------
HOW TO PROCEED IN INTERVIEW
-----------------------------------------------------------
Step 1: Understand binary representation
Step 2: Identify positions of set bits (1s)
Step 3: Compute distance between consecutive 1s
Step 4: Track maximum distance
Step 5: Optimize space if possible
Step 6: Discuss Time & Space Complexity
-----------------------------------------------------------
*/


/*-----------------------------------------------------------*/

void brute()
{
    /*
        Approach:
        - Convert number to binary string
        - Traverse string and track positions of '1'
        - Calculate max difference

        Time Complexity  : O(32)
        Space Complexity : O(32)
    */

    // 🔹 Hardcoded Input
    int n = 22; // Binary: 10110

    string bin = "";
    while (n > 0)
    {
        bin += (n % 2) + '0';
        n /= 2;
    }

    int last = -1, ans = 0;

    for (int i = 0; i < bin.size(); i++)
    {
        if (bin[i] == '1')
        {
            if (last != -1)
                ans = max(ans, i - last);

            last = i;
        }
    }

    // 🔹 Output
    cout << ans;
}

/*-----------------------------------------------------------*/

void better()
{
    /*
        Approach:
        - Use bitset to directly access bits
        - Track index of previous set bit

        Time Complexity  : O(32)
        Space Complexity : O(1)
    */

    // 🔹 Hardcoded Input
    int n = 22; // Binary: 10110

    bitset<32> b(n);
    int last = -1, ans = 0;

    for (int i = 0; i < 32; i++)
    {
        if (b[i] == 1)
        {
            if (last != -1)
                ans = max(ans, i - last);

            last = i;
        }
    }

    // 🔹 Output
    cout << ans;
}

/*-----------------------------------------------------------*/

void optimal()
{
    /*
        Approach:
        - Use bitwise operations
        - Check LSB using (n & 1)
        - Right shift n step by step

        Time Complexity  : O(32)
        Space Complexity : O(1)
    */

    // 🔹 Hardcoded Input
    int n = 22; // Binary: 10110

    int last = -1, idx = 0, ans = 0;

    while (n > 0)
    {
        if (n & 1)
        {
            if (last != -1)
                ans = max(ans, idx - last);

            last = idx;
        }

        idx++;
        n >>= 1;
    }

    // 🔹 Output
    cout << ans;
}

/*-----------------------------------------------------------*/

int main()
{
    cout << "Brute: ";
    brute();

    cout << "\nBetter: ";
    better();

    cout << "\nOptimal: ";
    optimal();

    return 0;
}

/*
===========================================================
JavaScript Optimal Approach
===========================================================

var binaryGap = function(n) {
    let last = -1, idx = 0, ans = 0;

    while (n > 0) {
        if (n & 1) {
            if (last !== -1)
                ans = Math.max(ans, idx - last);
            last = idx;
        }
        idx++;
        n >>= 1;
    }
    return ans;
};

===========================================================
Python Optimal Approach
===========================================================

def binaryGap(n):
    last = -1
    idx = 0
    ans = 0

    while n > 0:
        if n & 1:
            if last != -1:
                ans = max(ans, idx - last)
            last = idx
        idx += 1
        n >>= 1

    return ans

===========================================================
*/