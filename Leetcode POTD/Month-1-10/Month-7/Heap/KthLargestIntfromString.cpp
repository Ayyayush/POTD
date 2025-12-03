#include <bits/stdc++.h>
using namespace std;



struct Compare {
    // Custom comparator for min-heap based on numerical value of strings
    bool operator()(const string& a, const string& b) {
        if (a.size() != b.size()) return a.size() > b.size();    // Shorter string = smaller number
        return a > b;                                            // Lexicographically smaller
    }
};

void better()
{
    // ✅ Approach: Min Heap of size k (Better Approach)
    // ✅ Time Complexity: O(n * log k)                          // n elements pushed, heap size capped at k
    // ✅ Space Complexity: O(k)                                 // Heap stores only k elements at any time

    int n, k;
    cin >> n >> k;                                              // Input: array size and value of k

    vector<string> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];                                         // Input strings (numbers)

    priority_queue<string, vector<string>, Compare> pq;        // Min heap with custom comparator

    for (string& num : nums) {
        pq.push(num);                                           // Push current string into heap

        if (pq.size() > k)
            pq.pop();                                           // Heap size exceed kar gaya? pop smallest
    }

    cout << pq.top() << endl;                                   // kth largest element will be on top now
}

int main()
{
    better();
    return 0;
}
