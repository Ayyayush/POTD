#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // using nested loops
}

void better()                                      // ✅ Time: O(N + M), Space: O(128) ~ O(1)
{
    string s, t;
    cin >> s >> t;

    if (s.size() < t.size())                        // Agar s chhoti hai t se, toh window possible hi nahi
    {
        cout << "" << endl;
        return;
    }

    unordered_map<char, int> mp2;                   // t ke characters ka freq store karne ke liye
    for (char c : t) mp2[c]++;

    int i = 0, j = 0, start = 0, minLen = INT_MAX;  // i = window start, j = window end
    int count = 0;                                  // Kitne required characters match ho chuke

    unordered_map<char, int> mp1;                   // Current window ka character freq

    while (j < s.size())
    {
        char ch = s[j];
        mp1[ch]++;

        if (mp2.count(ch) && mp1[ch] <= mp2[ch])    // Agar character t mein hai aur required limit tak hai
            count++;

        while (count == t.size())                   // Jab poora t match ho gaya window ke andar
        {
            if (j - i + 1 < minLen)                 // Minimum length window update karo
            {
                minLen = j - i + 1;
                start = i;
            }

            // Window chhoti karo left se
            mp1[s[i]]--;
            if (mp2.count(s[i]) && mp1[s[i]] < mp2[s[i]])
                count--;                            // Agar required character kam ho gaya toh count ghatana padega

            i++;                                    // Move window forward
        }

        j++;                                        // Expand window
    }

    if (minLen == INT_MAX)
        cout << "" << endl;                         // Agar koi window nahi mila
    else
        cout << s.substr(start, minLen) << endl;    // Minimum window print karo
}


void optimal

int main()
{
    optimal();
    return 0;
}
