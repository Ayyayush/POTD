#include <bits/stdc++.h>
using namespace std;

/**
 * Approach - Brute Force
 * -----------------------------------
 * Har character ka frequency map banate hain.
 * Consecutive repeated characters detect karte hain.
 * Agar repetition milta hai toh extra combinations count karte hain.
 * 
 * Time Complexity: O(N)          // N = length of string
 * Space Complexity: O(1)         // Max 26 characters, so constant space
 */

void brute()
{
    string word;
    cin >> word;

    unordered_map<char, int> mp;
    bool repeated = false;

    for (int i = 0; i < word.size(); i++)
    {
        if (i != 0 && word[i] == word[i - 1])
            repeated = true;

        if (i != 0 && word[i] != word[i - 1] && mp.count(word[i]))
            mp[word[i]]--;

        mp[word[i]]++;
    }

    int ans = 1;
    if (repeated)
    {
        for (auto it : mp)
        {
            if (it.second > 1)
            {
                ans += (it.second - 1);
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    brute();
    return 0;
}
