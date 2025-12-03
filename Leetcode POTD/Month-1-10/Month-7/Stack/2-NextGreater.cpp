#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Approach: Brute Force (2 nested loops + circular traversal)
    // T.C. = O(N^2)             💻 N elements * N comparisons max
    // S.C. = O(N)               🧠 output array result[N]

    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];                   // Input array
    }

    vector<int> result(n, -1);            // Initialize result array with -1

    for(int i = 0; i < n; i++) {
        bool found = false;              // Flag to check if greater element is found

        // Step 1: Traverse from i+1 to end
        for(int j = i + 1; j < n; j++) {
            if(nums[j] > nums[i]) {
                result[i] = nums[j];     // Found next greater
                found = true;
                break;
            }
        }

        // Step 2: If not found, traverse from 0 to i-1 (circular array)
        if(!found) {
            for(int j = 0; j < i; j++) {
                if(nums[j] > nums[i]) {
                    result[i] = nums[j]; // Found next greater in circular fashion
                    break;
                }
            }
        }
    }

    // Output the result
    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}



void optimal()
{
    // Approach: Monotonic Stack + Circular Traversal
    // T.C. = O(2N) ≈ O(N)           // Har element ek baar push aur ek baar pop hota hai
    // S.C. = O(N)                   // Stack + Result array of size N

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<int> result(n, -1);           // Default: -1 means no greater found
    stack<int> st;                       // Stack to store indexes

      for(int i=(nums.size()*2)-1;i>=0;i--)
        {

            int idx=i%nums.size();
            while(!st.empty() && st.top()<=nums[idx])
            {
                st.pop();
            }

            if(!st.empty())
            {
                res[idx]=st.top();
            }

            st.push(nums[idx]);
        }
        

    // Output result
    for(int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << endl;
}



int main()
{
    brute();
    return 0;
}
