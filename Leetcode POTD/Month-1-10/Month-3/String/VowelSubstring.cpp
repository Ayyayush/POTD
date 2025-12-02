#include <bits/stdc++.h>
using namespace std;
void brute() // 0(n*k)
{
    string word;
    getline(cin, word);

    int k, countk, countv, flag = 0;
    cin >> k;
    for (int i = 0; i < word.size(); i++) // O(N)
    {
        string subs = "";
        map<char, int> mp;
        countk = 0, countv = 0;
        for (int j = i; j < word.size(); j++) // O(k)
        {

            char ch = word[j];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                if (mp.find(ch) == mp.end())
                {
                    mp[ch]++;
                    countv++;
                }
            }
            else
            {
                countk++;
            }

            if (countv >= 5 && countk == k)
            {
                flag++;
            }
        }
    }

    cout << flag << endl;
}

void optimal()
{
    // 🔹 Time Complexity: O(N)  (Sliding Window Approach)
    // 🔹 Space Complexity: O(N)  (Next consonant array ke liye)

    string word;
    int k;
    getline(cin, word);
    cin >> k;

    int n = word.length();
    unordered_map<char, int> mp; // 🔹 Current window me vowels ka count store karega
    vector<int> nextCons(n);     // 🔹 Har index ka next consonant track karega
    int lastConsIdx = n;

    // 🔹 Preprocessing to find next consonant index for each position
    for (int i = n - 1; i >= 0; i--)
    {
        nextCons[i] = lastConsIdx;
        if (word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u')
        {
            lastConsIdx = i; // 🔹 Update last consonant index
        }
    }

    int i = 0, j = 0, cons = 0;
    long long count = 0;

    // 🔹 Sliding Window (Two Pointer Approach)
    while (j < n)
    {
        char ch = word[j];

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            mp[ch]++; // 🔹 Vowel ka count update karna
        }
        else
        {
            cons++; // 🔹 Consonant count update karna
        }

        // 🔹 Adjust window jab consonants zyada ho jaaye
        while (cons > k)
        {
            char ch = word[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                mp[ch]--;
                if (mp[ch] == 0)
                {
                    mp.erase(ch);
                }
            }
            else
            {
                cons--;
            }
            i++;
        }

        // 🔹 Valid window check aur counting
        while (i < n && mp.size() == 5 && cons == k)
        {
            count += nextCons[j] - j;
            char ch = word[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                mp[ch]--;
                if (mp[ch] == 0)
                {
                    mp.erase(ch);
                }
            }
            else
            {
                cons--;
            }
            i++;
        }

        j++;
    }

    cout << "Total valid substrings: " << count << endl;
}

int main()
{
    optimal();
    return 0;
}
