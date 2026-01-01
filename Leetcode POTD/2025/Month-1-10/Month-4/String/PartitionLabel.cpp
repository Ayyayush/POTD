#include <bits/stdc++.h>
using namespace std;

void brute()
{
    string s;
    cin >> s;
    int n = s.length();

    vector<int> result;
    vector<int> mp(26, -1); // Har character ka last occurrence track karne ke liye

    // Step 1: Last occurrence store kar lo
    for (int i = 0; i < n; i++)
    {
        mp[s[i] - 'a'] = i;
    }

    int i = 0;
    while (i < n)
    {
        int end = mp[s[i] - 'a']; // Current partition ka last index
        int j = i;

        while (j < end) // Jab tak partition expand ho raha ho
        {
            end = max(end, mp[s[j] - 'a']);
            j++;
        }

        result.push_back(j - i + 1); // Partition size store karo
        i = j + 1;                   // Naya partition start hoga
    }

    for (int num : result)
        cout << num << " ";
    cout << endl;
}

void optimal()
{
    string s;
    cin >> s;
    int n = s.length();

    vector<int> result;
    vector<int> mp(26, -1); // Har character ka last occurrence track karne ke liye

    // Step 1: Last occurrence store kar lo
    for (int i = 0; i < n; i++)
    {
        mp[s[i] - 'a'] = i;
    }

    int i = 0, start = 0, end = 0;

    // Step 2: Partitions find karna
    while (i < n)
    {
        end = max(end, mp[s[i] - 'a']); // Max last index tak extend karo
        if (i == end)                   // Agar partition end reach ho gaya
        {
            result.push_back(end - start + 1);
            start = end + 1;
        }
        i++;
    }

    for (int num : result)
        cout << num << " ";
    cout << endl;
}

int main()
{
    brute();
    optimal();
    return 0;
}
