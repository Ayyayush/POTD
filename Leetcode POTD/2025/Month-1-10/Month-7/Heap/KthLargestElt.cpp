#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // ✅ Approach: Sorting Based (Brute Force)
    // ✅ Time Complexity: O(n * log n)              // Sorting takes O(n log n)
    // ✅ Space Complexity: O(1)                     // No extra space used

    int n, k;
    cin >> n >> k;                                  // Array size aur K input lo
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];                             // Array elements input lo

    sort(nums.rbegin(), nums.rend());               // Array ko descending order mein sort karo

    cout << nums[k - 1] << endl;                    // Kth largest element ko print karo
}


void better()
{
    // ✅ Approach: Max Heap (Priority Queue) — Better Approach
    // ✅ Time Complexity: O(n + k*log n) ≈ O(n)             // n insertions into heap + k pops
    // ✅ Space Complexity: O(n)                            // Heap mein saare elements store ho rahe hain

    int n, k;
    cin >> n >> k;                                        // Input: array size aur k
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];                                   // Array input lo

    priority_queue<int> pq;                               // Max Heap banaya (by default max heap hoti hai)
    for (auto it : nums)
    {
        pq.push(it);                                      // Har element ko heap mein daala
    }

    k--;                                                  // k-1 baar top element ko hata do
    while (k--)
    {
        pq.pop();                                         // Largest elements hata rahe hain one by one
    }

    cout << pq.top() << endl;                             // Ab top pe kth largest element hoga
}

int main()
{
    better();
    return 0;
}
