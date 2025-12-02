#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Using nested loops
    // Time Complexity: O(n * k)       // Har subarray ke liye manually max nikal rahe
    // Space Complexity: O(1)          // Sirf variables use ho rahe
}

void good()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example input
    int k;
    cin >> k; // Window size input

    int i = 0, j = 0; 
    vector<int> result;

    while (j < nums.size())
    {
        if (j - i + 1 == k)
        {
            int maximum = *max_element(nums.begin() + i, nums.begin() + j + 1); // Window ka max dhoond rahe
            result.push_back(maximum);                                          // Result store kar rahe
            i++;                                                                // Window slide kar rahe
        }

        j++;
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    // Time Complexity: O(n * k)       // Har window mein O(k) lagta hai max_element ko
    // Space Complexity: O(n - k + 1)  // Result vector mein max elements store ho rahe
}

void better()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example input
    int k;
    cin >> k; // Window size input

    int i = 0, j = 0;
    vector<int> result;
    multiset<int> st;                                   // Corrected: <set> -> multiset (because we'll keep duplicates)

    while (j < nums.size())
    {
        st.insert(nums[j]);                             // Window mein current element daal rahe

        if (j - i + 1 == k)
        {
            result.push_back(*st.rbegin());             // Multiset ka last element max hota hai
            st.erase(st.find(nums[i]));                 // i-th element remove karna (not clear())
            i++;                                        // Window slide kar rahe
        }

        j++;
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    // Time Complexity: O(n * log k)     // Multiset mein insert/erase log k time leta hai
    // Space Complexity: O(k)            // Multiset mein max k elements honge
}


void optimal()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};      // Example input
    int k;
    cin >> k;                                                // Window size input

    deque<int> dq;                                           // Indices store karenge
    vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        // Remove out-of-bound elements
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove smaller elements from back
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    for (int x : result) cout << x << " ";
    cout << endl;

    // Time Complexity: O(n)
    // Space Complexity: O(k)
}


int main()
{
    better();  // Change this to optimal() if you want to test that
    return 0;
}
