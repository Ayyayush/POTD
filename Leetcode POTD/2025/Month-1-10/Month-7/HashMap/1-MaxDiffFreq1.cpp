#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(N) + O(26) = O(N)               // N = length of string, 26 characters max
    // Space Complexity: O(1)                             // max 26 lowercase letters in hashmap

    string s = "aaabbcccdee";                            // Hardcoded input string
    unordered_map<char, int> mp;                         // Character frequency store karne ke liye

    // Step 1: Frequency count har character ka
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;                                      // har character ki frequency count karo
    }

    // Initialize values
    int maxfreq = INT_MIN;                               // maximum difference store karne ke liye
    int maxevenfreq = 0;                                 // even frequency ka maximum
    int minevenfreq = INT_MAX;                           // even frequency ka minimum
    int maxoddfreq = 0;                                  // odd frequency ka maximum
    int minoddfreq = INT_MAX;                            // odd frequency ka minimum

    // Step 2: Har character frequency check karo aur even/odd ke hisaab se update karo
    for (auto it : mp)
    {
        if (it.second % 2 != 0)                          // odd frequency case
        {
            minoddfreq = min(minoddfreq, it.second);     // minimum odd frequency update karo
            maxoddfreq = max(maxoddfreq, it.second);     // maximum odd frequency update karo
        }
        else                                              // even frequency case
        {
            minevenfreq = min(minevenfreq, it.second);   // minimum even frequency update karo
            maxevenfreq = max(maxevenfreq, it.second);   // maximum even frequency update karo
        }
    }

    // Step 3: Maximum difference calculate karo between even-odd combinations
    maxfreq = max((minoddfreq - maxevenfreq), maxfreq);  // case 1: min odd - max even
    maxfreq = max((maxoddfreq - minevenfreq), maxfreq);  // case 2: max odd - min even

    // Output result
    cout << "Maximum difference between odd and even frequency: " << maxfreq << endl;
}

int main()
{
    brute();
    return 0;
}
