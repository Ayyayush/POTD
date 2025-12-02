#include <bits/stdc++.h>
using namespace std;

void wordFrequency()
{
    // ✅ Max Heap based on frequency
    // ✅ T.C. = O(n log n), S.C. = O(n)

    vector<string> words = {"apple", "banana", "apple", "cherry", "banana", "apple"};

    unordered_map<string, int> mp;

    for (auto word : words)
    {
        mp[word]++;
    }

    // Max heap based on frequency
    priority_queue<pair<int, string>> pq;

    for (auto it : mp)
    {
        pq.push({it.second, it.first});  // {frequency, word}
    }

    // Output the word frequency list
    while (!pq.empty())
    {
        cout << pq.top().second << " : " << pq.top().first << endl;
        pq.pop();
    }
}
