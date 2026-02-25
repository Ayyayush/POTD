#include <bits/stdc++.h>
using namespace std;

/*
============================================================
PROBLEM: Check if a String Contains All Binary Codes of Size K
LeetCode 1461
============================================================

Interview Steps:
1) Total binary codes = 2^k
2) Window size = k
3) Generate all unique windows
4) Compare with required count
*/


void brute()
{
    /*
    ------------------------------------------------------------
    Approach: Brute Force (Manual substring creation)
    Time Complexity: O(n * k)
    Space Complexity: O(2^k * k)
    ------------------------------------------------------------
    */

    string s = "00110110";
    int k = 2;

    int required = pow(2, k);
    unordered_set<string> st;

    for (int i = 0; i <= s.size() - k; i++)
    {
        string temp = "";

        for (int j = i; j < i + k; j++)
        {
            temp += s[j];
        }

        st.insert(temp);
    }

    cout << "Brute Output: " 
         << (st.size() == required ? "true" : "false") 
         << endl;
}


void better()
{
    /*
    ------------------------------------------------------------
    Approach: Sliding Window + substr()
    Time Complexity: O(n * k)
    Space Complexity: O(2^k * k)
    ------------------------------------------------------------
    */

    string s = "00110110";
    int k = 2;

    int required = pow(2, k);
    unordered_set<string> st;

    for (int i = 0; i <= s.size() - k; i++)
    {
        st.insert(s.substr(i, k));   // direct substring
    }

    cout << "Better Output: " 
         << (st.size() == required ? "true" : "false") 
         << endl;
}


void optimal()
{
    /*
    ------------------------------------------------------------
    Approach: Sliding Window + Bitmask (Rolling Hash)
    Time Complexity: O(n)
    Space Complexity: O(2^k)
    ------------------------------------------------------------
    */

    string s = "00110110";
    int k = 2;

    int n = s.size();
    int required = 1 << k;

    if (n < k)
    {
        cout << "Optimal Output: false" << endl;
        return;
    }

    unordered_set<int> seen;

    int mask = 0;
    int allOnes = required - 1;   // keeps last k bits only

    for (int i = 0; i < n; i++)
    {
        mask = ((mask << 1) & allOnes) | (s[i] - '0');

        if (i >= k - 1)
        {
            seen.insert(mask);

            if (seen.size() == required)
            {
                cout << "Optimal Output: true" << endl;
                return;
            }
        }
    }

    cout << "Optimal Output: false" << endl;
}


int main()
{
    brute();
    better();
    optimal();
    return 0;
}


/*
============================================================
Optimal Approach in JavaScript (Bitmask)
============================================================

function hasAllCodes(s, k) {
    const required = 1 << k;
    if (s.length < k) return false;

    const seen = new Set();
    let mask = 0;
    const allOnes = required - 1;

    for (let i = 0; i < s.length; i++) {
        mask = ((mask << 1) & allOnes) | (s[i] - '0');

        if (i >= k - 1) {
            seen.add(mask);
            if (seen.size === required) return true;
        }
    }
    return false;
}
*/


/*
============================================================
Optimal Approach in Python (Bitmask)
============================================================

def hasAllCodes(s, k):
    required = 1 << k
    if len(s) < k:
        return False

    seen = set()
    mask = 0
    allOnes = required - 1

    for i in range(len(s)):
        mask = ((mask << 1) & allOnes) | int(s[i])
        if i >= k - 1:
            seen.add(mask)
            if len(seen) == required:
                return True

    return False
*/