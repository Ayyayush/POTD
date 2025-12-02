#include <bits/stdc++.h>
using namespace std;

/*
Helper function: Yeh function count karta hai
'at most k distinct characters' wali substrings kitni hain
Sliding window technique + hashmap ka use kiya gaya hai
*/
int atMostK(string &s, int k)
{
    int i = 0, j = 0, count = 0;
    unordered_map<char, int> mp;

    while (j < s.size())
    {
        mp[s[j]]++; // current character ko window mein daal rahe hain

        // Jab distinct characters > k ho jaye, toh window chhoti karo
        while (mp.size() > k)
        {
            mp[s[i]]--; // left se character hatao
            if (mp[s[i]] == 0)
                mp.erase(s[i]); // agar count 0 ho gaya toh map se hata do
            i++;                // left pointer badhao
        }

        // Har window ke liye (j - i + 1) substrings banengi
        count += (j - i + 1);

        j++; // right pointer badhao
    }

    return count;
}

int atMostKBetter(string &s, int k)
{
    if (k == 0)
        return 0;

    vector<int> freq(26, 0); // 26 lowercase letters ka frequency array
    int i = 0, count = 0, distinct = 0;

    for (int j = 0; j < s.size(); j++)
    {
        if (freq[s[j] - 'a'] == 0) // naye character mila
            distinct++;
        freq[s[j] - 'a']++;

        while (distinct > k)
        {
            freq[s[i] - 'a']--; // left se remove karo
            if (freq[s[i] - 'a'] == 0)
                distinct--; // ek character hat gaya
            i++;
        }

        count += (j - i + 1); // har window ka contribution
    }

    return count;
}

/*
Better approach:
Exactly k distinct characters wali substrings =
    atMostK(s, k) - atMostK(s, k-1)
*/
void better()
{
    string s;
    int k;
    cin >> s >> k;

    int exactlyK = atMostK(s, k) - atMostK(s, k - 1); // helper function ka use
    cout << exactlyK << endl;
}

/*
Optimal version: Galat thi pehle, ab correct kar rahe hain.
Yeh bhi same kaam karega lekin bina atMostK helper function ke
*/
void optimal()
{
    string s;
    int k;
    cin >> s >> k;

    auto countAtMostK = [&](int K) -> int
    {
        int i = 0, j = 0, res = 0;
        unordered_map<char, int> mp;

        while (j < s.size())
        {
            mp[s[j]]++;

            while (mp.size() > K)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }

            res += (j - i + 1); // window mein jitni substrings banengi
            j++;
        }
        return res;
    };

    int ans = countAtMostK(k) - countAtMostK(k - 1); // Exactly k = atMostK(k) - atMostK(k-1)
    cout << ans << endl;
}

int main()
{
    // better();   // Agar better test karna ho toh isey run karo
    optimal(); // Optimal test karna ho toh isey run karo
    return 0;
}
