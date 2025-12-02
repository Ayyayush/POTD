#include <bits/stdc++.h>
using namespace std;

/**
 * Approach - Brute Force
 * ------------------------------------------
 * Har length-k substring bana ke check karte hain ki usme (k-1) distinct characters hain ya nahi.
 * Agar haan, toh count increment karte hain.
 * 
 * Time Complexity: O(N * K)             // N = length of string, K = size of each substring
 * Space Complexity: O(K)                // Set to hold at most K characters
 */

void brute()
{
    string s;
    int k;
    cin >> s >> k;

    int count = 0;

    for (int i = 0; i <= s.size() - k; i++)
    {
        string sub = s.substr(i, k);
        unordered_set<char> st;

        for (char c : sub)
        {
            st.insert(c);
        }

        if (st.size() == k - 1)
            count++;
    }

    cout << count << endl;
}



void better()
{
    // ✅ Time Complexity: O(n)
    // ✅ Space Complexity: O(k)    (unordered_map stores at most k characters)

    string s;
    int k;
    cin >> s >> k;                                               // 🔹 Input: string and integer

    int count = 0;
    int i = 0, j = 0;
    unordered_map<char, int> mp;

    while (j < s.size())
    {
        mp[s[j]]++;                                              // 🔹 Add current char to map

        if (j - i + 1 == k)                                      // 🔹 Window size reached
        {
            if (mp.size() == k - 1)                              // 🔹 Valid condition: exactly (k-1) distinct chars
            {
                count++;
            }

            mp[s[i]]--;                                          // 🔹 Shrink window from left
            if (mp[s[i]] == 0) mp.erase(s[i]);                   // 🔹 Clean map entry if frequency becomes 0
            i++;
        }

        j++;
    }

    cout << count << endl;                                       // 🔹 Output the result
}





int main()
{
    brute();
    return 0;
}



