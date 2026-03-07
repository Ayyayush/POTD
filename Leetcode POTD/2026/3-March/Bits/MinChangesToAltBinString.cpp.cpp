#include <bits/stdc++.h>
using namespace std;

void brute()
{
    //! Approach: Brute Force (Generate both alternating strings)

    //! Time Complexity: O(n)
    //! We traverse the string once to build patterns and compare.

    //! Space Complexity: O(n)
    //! Extra space used for two pattern strings.

    string s = "10010100";                         // hardcoded input
    int n = s.size();

    string pattern1 = "";                          // pattern starting with '0'
    string pattern2 = "";                          // pattern starting with '1'

    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            pattern1 += '0';                       // 0 1 0 1 ...
            pattern2 += '1';                       // 1 0 1 0 ...
        }
        else
        {
            pattern1 += '1';
            pattern2 += '0';
        }
    }

    int count1 = 0, count2 = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] != pattern1[i])                    // mismatch with pattern1
            count1++;

        if(s[i] != pattern2[i])                    // mismatch with pattern2
            count2++;
    }

    int ans = min(count1, count2);

    cout << ans << endl;                           // always give if exists
}

void better()
{
    //! Approach: Count mismatches for both patterns in one traversal

    //! Time Complexity: O(n)

    //! Space Complexity: O(1)

    string s = "10010100";                         // hardcoded input
    int n = s.size();

    int count1 = 0, count2 = 0;                    // mismatches for both patterns

    for(int i = 0; i < n; i++)
    {
        char expected1 = (i % 2 == 0) ? '0' : '1'; // pattern1 → 010101...
        char expected2 = (i % 2 == 0) ? '1' : '0'; // pattern2 → 101010...

        if(s[i] != expected1)
            count1++;

        if(s[i] != expected2)
            count2++;
    }

    int ans = min(count1, count2);

    cout << ans << endl;                           // always give if exists
}

void optimal()
{
    //! Approach: Greedy / Pattern Observation
    //! If mismatches for pattern "010101..." = x
    //! mismatches for "101010..." = n - x

    //! Time Complexity: O(n)

    //! Space Complexity: O(1)

    string s = "10010100";                         // hardcoded input
    int n = s.size();

    int mismatch = 0;                              // mismatches for pattern starting with '0'

    for(int i = 0; i < n; i++)
    {
        char expected = (i % 2 == 0) ? '0' : '1';  // expected char for "010101..."

        if(s[i] != expected)
            mismatch++;
    }

    int ans = min(mismatch, n - mismatch);

    cout << ans << endl;                           // always give if exists
}

int main()
{
    brute();
    better();
    optimal();
    return 0;
}

/*
Optimal Approach in JavaScript

function minOperations(s) {
    let mismatch = 0;

    for (let i = 0; i < s.length; i++) {
        let expected = (i % 2 === 0) ? '0' : '1';

        if (s[i] !== expected)
            mismatch++;
    }

    return Math.min(mismatch, s.length - mismatch);
}
*/

/*
Optimal Approach in Python

def minOperations(s):
    mismatch = 0

    for i in range(len(s)):
        expected = '0' if i % 2 == 0 else '1'

        if s[i] != expected:
            mismatch += 1

    return min(mismatch, len(s) - mismatch)
}
*/