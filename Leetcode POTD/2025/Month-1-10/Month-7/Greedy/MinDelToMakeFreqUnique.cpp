#include <bits/stdc++.h>
using namespace std;

void naive()
{
    /*
    💡 Naive Approach: Try every freq as base and simulate
    ------------------------------------------------------
    T.C. = O(N + M^2)
        - O(N) for frequency map
        - O(M^2) for simulating every base freq (M ≤ 26)
    S.C. = O(M)
        - map + vector + set
    ------------------------------------------------------
    */

    string s = "aaabbbcc";    // 🔸 Hardcoded input

    unordered_map<char, int> mp;
    for (char c : s)
        mp[c]++;                        // Frequency count

    vector<int> freq;
    for (auto it : mp)
        freq.push_back(it.second);

    sort(freq.begin(), freq.end());    // Sort ascending

    int mindeletions = INT_MAX;

    for (int i = 0; i < freq.size(); i++)
    {
        int deletions = 0;
        vector<int> temp = freq;
        unordered_set<int> used;

        for (int j = 0; j < temp.size(); j++)
        {
            while (temp[j] > 0 && used.count(temp[j]))
            {
                temp[j]--;
                deletions++;
            }
            if (temp[j] > 0)
                used.insert(temp[j]);
        }

        mindeletions = min(mindeletions, deletions);
    }

    cout << "Naive: " << mindeletions << endl;
}

void brute()
{
    /*
    💡 Brute Approach: Sort descending + used set
    ------------------------------------------------------
    T.C. = O(N + M log M)
        - O(N) for frequency map
        - O(M log M) for sorting
    S.C. = O(M)
        - vector + set
    ------------------------------------------------------
    */

    string s = "aaabbbcc";   // 🔸 Hardcoded input

    unordered_map<char, int> mp;
    for (char c : s)
        mp[c]++;

    vector<int> freq;
    for (auto it : mp)
        freq.push_back(it.second);

    sort(freq.begin(), freq.end(), greater<int>());

    int deletions = 0;
    unordered_set<int> used;

    for (int f : freq)
    {
        while (f > 0 && used.count(f))
        {
            f--;
            deletions++;
        }
        if (f > 0)
            used.insert(f);
    }

    cout << "Brute: " << deletions << endl;
}

void optimal()
{
    /*
    💡 Optimal Approach: Sort descending and adjust forward
    ------------------------------------------------------
    T.C. = O(N + M log M)
        - O(N) for frequency map
        - O(M log M) for sorting
    S.C. = O(M)
        - frequency vector only
    ------------------------------------------------------
    */

    string s = "aaabbbcc";    // 🔸 Hardcoded input

    unordered_map<char, int> mp;
    for (char c : s)
        mp[c]++;

    vector<int> freq;
    for (auto it : mp)
        freq.push_back(it.second);

    sort(freq.begin(), freq.end(), greater<int>());  // descending sort

    int deletions = 0;
    for (int i = 1; i < freq.size(); i++)
    {
        while (freq[i] >= freq[i - 1] && freq[i] > 0)
        {
            freq[i]--;
            deletions++;
        }
    }

    cout << "Optimal: " << deletions << endl;
}

void better()
{
    /*
    💡 Better Approach: Greedy + unordered_set (No sorting)
    ------------------------------------------------------
    T.C. = O(N + M)
        - O(N) to count frequencies
        - O(M) to handle unique chars (≤ 26)
    S.C. = O(M)
        - unordered_map + set
    ------------------------------------------------------
    */

    string s = "aaabbbcc";   // 🔸 Hardcoded input

    unordered_map<char, int> freq;
    for (char c : s)
        freq[c]++;

    unordered_set<int> used;
    int deletions = 0;

    for (auto [ch, count] : freq)
    {
        while (count > 0 && used.count(count))
        {
            count--;
            deletions++;
        }
        if (count > 0)
            used.insert(count);
    }

    cout << "Better: " << deletions << endl;
}

int main()
{
    naive();
    brute();
    optimal();
    better();
    return 0;
}
