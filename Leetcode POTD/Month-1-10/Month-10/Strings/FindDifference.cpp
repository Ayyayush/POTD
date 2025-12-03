#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Approach: Frequency Map (Hashing) 
    // T.C. -> O(n)   (n = size of s or t)
    // S.C. -> O(26) ≈ O(1)   (kyunki sirf lowercase letters hote hain)

    string s, t;
    cin >> s >> t;                           // input strings

    unordered_map<char, int> mp;             // frequency map for characters
    
    for (int i = 0; i < s.size(); i++)      
    {
        mp[s[i]]++;                          // s ke chars ko count karo
    }

    for (int i = 0; i < t.size(); i++)      
    {
        mp[t[i]]--;                          // t ke chars ko reduce karo
        if (mp[t[i]] == 0)                   
        {
            mp.erase(t[i]);                  // agar count 0 ho jaye toh remove
        }
    }

    char c;
    for (auto it : mp)                      
    {
        c = it.first;                        // jo character bacha wahi extra h
    }

    cout << c << endl;                       // output extra character
}

int main()
{
    brute();
    return 0;
}
