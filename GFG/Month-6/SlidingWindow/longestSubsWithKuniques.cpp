#include <bits/stdc++.h>
using namespace std;

// Approach: Sliding Window + HashMap (for character frequency tracking)
// T.C. = O(N), S.C. = O(K)     where N = s.size()
// We try to maintain a window [i..j] with at most K distinct characters.

void better()
{
    string s;
    int k;
    cin >> s >> k;                      // input string and value of k

    int i = 0, j = 0;
    unordered_map<char, int> mp;       // character frequency map
    int maxcount = -1;

    while (j < s.size())
    {
        mp[s[j]]++;                    // current character ka count badha diya

        // agar distinct characters zyada ho gaye toh window chhoti karo
        while (mp.size() > k && i < s.size())
        {
            mp[s[i]]--;                // left character ka count kam karo
            if (mp[s[i]] == 0)
                mp.erase(s[i]);        // agar frequency 0 ho gayi toh hata do
            i++;                       // window left se chhoti kar do
        }

        // agar exactly K distinct characters hai, answer update karo
        if (mp.size() == k)
        {
            maxcount = max(maxcount, j - i + 1);   // current window length check karo
        }

        j++;                           // window right se badhao
    }

    cout << maxcount << endl;          // final answer print karo
}

int main()
{
    better();
    return 0;
}
