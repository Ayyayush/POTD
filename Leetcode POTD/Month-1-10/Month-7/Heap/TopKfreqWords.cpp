#include <bits/stdc++.h>
using namespace std;

void better()
{
    // ✅ Sample Input:
    // 8 2
    // i love leetcode i love coding i leetcode

    int n, k;
    cin >> n >> k;                                  // Input size of array and value of k

    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];                            // Input array of words

    unordered_map<string, int> mp;                  // Step 1: Frequency map to count each word

    for (auto &word : words)
    {
        mp[word]++;                                 // Count frequency of each word
    }

    // ✅ Step 2: Priority Queue (Max Heap)
    // Store pair: {frequency, word}
    // Custom comparator:
    //   → Higher frequency comes first
    //   → If frequency is same, lexicographically smaller word comes first

    auto cmp = [](pair<int, string> &a, pair<int, string> &b)
    {
        if (a.first == b.first)
            return a.second > b.second;             // If frequency equal, word with smaller lex order first
        return a.first < b.first;                   // Higher frequency first
    };

    // Declare priority_queue with above comparator
    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);

    // ✅ Step 3: Push all word-frequency pairs into priority queue
    for (auto &it : mp)
    {
        pq.push({it.second, it.first});             // {frequency, word}
    }

    // ✅ Step 4: Extract top k frequent words
    vector<string> res;

    while (k-- && !pq.empty())
    {
        res.push_back(pq.top().second);             // Push word to result
        pq.pop();                                   // Remove from heap
    }

    // ✅ Step 5: Output result
    for (auto &word : res)
    {
        cout << word << " ";
    }
    cout << endl;
}

int main()
{
    better();
    return 0;
}