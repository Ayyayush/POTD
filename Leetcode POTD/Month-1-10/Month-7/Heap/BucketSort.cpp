#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // ✅ Approach: Min Heap (Priority Queue)
    // ✅ Time Complexity: O(n * log k)
    // ✅ Space Complexity: O(n)

    int n, k;
    cin >> n >> k; // Input: array size and k
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i]; // Input array

    unordered_map<int, int> freq; // Step 1: Count frequency of each number
    for (int num : nums)
        freq[num]++;

    // Step 2: Min heap to store {frequency, number}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto &it : freq)
    {
        pq.push({it.second, it.first}); // Push frequency and number
        if (pq.size() > k)
            pq.pop(); // Maintain only top k frequent elements
    }

    // Step 3: Extract results from heap
    vector<int> res;
    while (!pq.empty())
    {
        res.push_back(pq.top().second); // Only numbers needed
        pq.pop();
    }

    reverse(res.begin(), res.end()); // Highest freq first
    for (int num : res)
        cout << num << " ";
    cout << endl;
}




void better()
{
    // ✅ Approach: Bucket Sort
    // ✅ Time Complexity: O(n)
    // ✅ Space Complexity: O(n)

    int n, k;
    cin >> n >> k; // Input: array size and k
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i]; // Input array

    unordered_map<int, int> freq; // Step 1: Frequency map
    for (int num : nums)
        freq[num]++;

    vector<vector<int>> bucket(n + 1); // Step 2: Bucket by frequency index

    for (auto &it : freq)
        bucket[it.second].push_back(it.first); // Step 3: Place num in appropriate freq bucket

    vector<int> res;
    for (int i = n; i >= 0 && res.size() < k; --i)
    { // Step 4: Go from high to low frequency
        for (int num : bucket[i])
        {
            res.push_back(num); // Collect top k frequent elements
            if (res.size() == k)
                break;
        }
    }

    for (int num : res)
        cout << num << " ";
    cout << endl;
}

int main()
{
    // Example: Input
    // 6 2
    // 1 1 1 2 2 3
    // Output (either 1 2 OR 2 1 depending on approach)

    // brute();     // Min Heap Approach
    better(); // Bucket Sort Approach
    return 0;
}
