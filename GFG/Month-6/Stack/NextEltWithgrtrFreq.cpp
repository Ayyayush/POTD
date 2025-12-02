#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // T.C. = O(n^2), S.C. = O(1)
    // Approach: Nested loops to check for next greater frequency manually

    vector<int> arr = {1, 2, 1, 3, 2};              // Example input
    vector<int> res;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int freq_i = 0;
        for (int k = 0; k < n; k++)                 // Frequency of arr[i]
        {
            if (arr[k] == arr[i]) freq_i++;
        }

        int ans = -1;
        for (int j = i + 1; j < n; j++)             // Next greater freq
        {
            int freq_j = 0;
            for (int k = 0; k < n; k++)             // Frequency of arr[j]
            {
                if (arr[k] == arr[j]) freq_j++;
            }

            if (freq_j > freq_i)
            {
                ans = arr[j];
                break;
            }
        }

        res.push_back(ans);
    }

    for (int val : res) cout << val << " ";        // Output
    cout << endl;
}


void better()
{
    // T.C. = O(n^2), S.C. = O(n)
    // Approach: Pre-compute frequency map first, then nested loop to check next element with higher freq

    vector<int> arr = {1, 2, 1, 3, 2};              // Example input
    unordered_map<int, int> freq;
    vector<int> res;
    int n = arr.size();

    for (int i = 0; i < n; i++) freq[arr[i]]++;     // Frequency of all elements

    for (int i = 0; i < n; i++)
    {
        int ans = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (freq[arr[j]] > freq[arr[i]])        // Compare precomputed frequencies
            {
                ans = arr[j];
                break;
            }
        }
        res.push_back(ans);
    }

    for (int val : res) cout << val << " ";         // Output
    cout << endl;
}



void optimal()
{
    // T.C. = O(n), S.C. = O(n)
    // Approach: Traverse from right to left, use stack to track elements with higher frequency

    vector<int> arr = {1, 2, 1, 3, 2};                 // Example input
    unordered_map<int, int> freq;                     // Frequency map
    vector<int> res(arr.size());                      // Result vector

    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;                               // Count frequency of each element
    }

    stack<int> st;

    for (int i = arr.size() - 1; i >= 0; i--)          // Traverse from right to left
    {
        while (!st.empty() && freq[st.top()] <= freq[arr[i]])
        {
            st.pop();                                 // Remove elements with freq <= current
        }

        if (st.empty()) res[i] = -1;                  // No higher freq element to the right
        else res[i] = st.top();                       // Top of stack is next greater freq element

        st.push(arr[i]);                              // Push current element onto stack
    }

    for (int val : res) cout << val << " ";           // Output result
    cout << endl;
}



int main()
{
    brute();
    better();
    return 0;
}
