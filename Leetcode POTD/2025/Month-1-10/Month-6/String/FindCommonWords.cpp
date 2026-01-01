#include <bits/stdc++.h>
using namespace std;

bool matching(string &str, string &chars)
{
    unordered_map<char, int> mp; // har char ka frequency store kar rahe hain

    for (int i = 0; i < chars.length(); i++)
    {
        mp[chars[i]]++; // chars ke har character ka count badha rahe hain
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (mp.find(str[i]) == mp.end())
            return false; // agar char available hi nahi hai to false
        mp[str[i]]--;     // frequency reduce karo
        if (mp[str[i]] == 0)
            mp.erase(str[i]); // agar frequency zero ho gayi to remove
    }

    return true; // agar poora word ban gaya to true
}

void brute()
{
    vector<string> words = {"cat", "bt", "hat", "tree"}; // input example
    string chars = "atach";                              // input example

    int count = 0;
    for (int i = 0; i < words.size(); i++)
    {
        string str = words[i];

        if (str.size() <= chars.length())
        {                             // agar word ka size zyada ho chars se to skip
            if (matching(str, chars)) // agar matching function true return kare
                count += str.size();  // tab uska size count mein jod do
        }
    }

    cout << count << endl; // final result print
}

int main()
{
    brute();
    return 0;
}