#include <bits/stdc++.h>
using namespace std;

void better()
{
    // Approach: Preprocessing + Binary Search
    // Step 1: Har character ke liye uske indices store karo in t
    // Step 2: For each char in s, uske liye t me agla valid index binary search se nikal lo
    //
    // T.C. -> O(m + n*log(m))  (m = size of t, n = size of s)
    // S.C. -> O(m)             (storing indices)

    string s, t;
    cin >> s >> t;

    // har character ke liye indices ka map
    unordered_map<char, vector<int>> pos;
    for (int i = 0; i < t.size(); i++)
    {
        pos[t[i]].push_back(i);
    }

    int prevIndex = -1;   // pehle match ke liye -1 se start
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        if (pos.find(c) == pos.end())   // agar char t me hai hi nahi
        {
            cout << "false\n";
            return;
        }

        // binary search in positions of char c
        auto it = upper_bound(pos[c].begin(), pos[c].end(), prevIndex);

        if (it == pos[c].end())         // agar koi valid index nahi mila
        {
            cout << "false\n";
            return;
        }

        prevIndex = *it;                // index update karo
    }

    cout << "true\n";   // sabhi chars mil gaye
}

void optimal()
{
    // Approach: Two Pointers
    // T.C. -> O(n + m)   (n = s.size(), m = t.size())
    // S.C. -> O(1)

    string s, t;
    cin >> s >> t;                          // input strings

    int k = 0;                              // pointer on t
    int count = 0;                          // matched characters count

    for (int i = 0; i < s.size(); i++)      
    {
        char c = s[i];                      // current char from s

        while (k < t.size() && t[k] != c)   // move k until match mil jaye ya t end ho jaye
        {
            k++;
        }

        if (k == t.size())                  // agar t poora traverse ho gaya but char nahi mila
        {
            cout << "false\n";
            return;
        }

        count++;                            // match mila toh count++
        k++;                                // next search t ke next char se start hogi
    }

    cout << (count == s.size() ? "true\n" : "false\n");  
}

int main()
{
    better();
    // optimal();
    return 0;
}
