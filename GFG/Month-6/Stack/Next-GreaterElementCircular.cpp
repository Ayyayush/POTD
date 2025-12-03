#include <bits/stdc++.h>
using namespace std;

// Approach: Brute Force - Check circularly next N-1 elements for each index
// T.C : O(n^2)                  (for each element, check all n-1 elements)
// S.C : O(n)                    (to store the result)
void brute()
{
    vector<int> arr = {1, 2, 1};               // Example input
    int n = arr.size();
    vector<int> res;                           // Output vector to store result

    for (int i = 0; i < n; i++)                // For each element
    {
        bool found = false;                   // Reset flag for current element

        for (int j = 1; j < n; j++)           // Check next (n-1) elements circularly
        {
            int nextIndex = (i + j) % n;      // Wrap around using modulo
            if (arr[nextIndex] > arr[i])      // Found next greater
            {
                res.push_back(arr[nextIndex]);
                found = true;
                break;
            }
        }

        if (!found) res.push_back(-1);        // If no greater element found
    }

    // Print result
    cout << "Next Greater Elements (Circular): ";
    for (int val : res)
        cout << val << " ";
    cout << endl;
}

/**
 * OPTIMIZED APPROACH
 * we will use aisa data structure jo apna piche wala elements ka dhyaan rakhe
 * humlog kya karenge kik element ko store nhi karenge balki usse index ko
 * hum log 2 paas chaleyenge array pe 2 times circular ke liye 
 * idx =i%arr.size()  aise krke exact index lenge 
 * resultant array le lo initialized with -1 
 */




 // Approach 2: O(n) monotonic stack – traverse twice, using a stack of indices to assign next bigger elements as they arrive.
// Time Complexity: O(n) – each index is pushed and popped at most once.
// Space Complexity: O(n) – auxiliary stack for indices.
class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int   n = arr.size();             // Size of the array
        vector<int> result(n, -1);              // Result initialized to -1s
        stack<int>  st;                         // Stack to store indices of waiting elements

        for (int i = 0; i < 2 * n; i++) {       // Traverse twice for circularity
            int idx = i % n;                    // Actual index in arr
            int num = arr[idx];                 // Current number

            // While current num is bigger than arr at the top index
            while (!st.empty() && num > arr[st.top()]) {
                result[st.top()] = num;         // Assign it as the next greater
                st.pop();                       // Remove that index
            }

            if (i < n) {                        // Only push original indices on first pass
                st.push(idx);                   // Add index to stack
            }
        }
        return result;                          // Return filled results
    }
};

/*
 *
 * Dry Run
 *
 * Input: arr = [2, 7, 3, 5, 1], n = 5
 * result initialized to [-1, -1, -1, -1, -1]
 * st = []
 *
 * i = 0: idx=0, num=2
 *  st empty → push 0 → st=[0]
 *
 * i = 1: idx=1, num=7
 *  7 > arr[0]=2 → result[0]=7; pop → st=[]
 *  push 1 → st=[1]; result=[7,-1,-1,-1,-1]
 *
 * i = 2: idx=2, num=3
 *  3 ≤ arr[1]=7 → push 2 → st=[1,2]
 *
 * i = 3: idx=3, num=5
 *  5 > arr[2]=3 → result[2]=5; pop → st=[1]
 *  5 ≤ arr[1]=7 → stop; push 3 → st=[1,3]; result=[7,-1,5,-1,-1]
 *
 * i = 4: idx=4, num=1
 *  1 ≤ arr[3]=5 → push 4 → st=[1,3,4]
 *
 * i = 5: idx=0, num=2
 *  2 > arr[4]=1 → result[4]=2; pop → st=[1,3]
 *  2 ≤ arr[3]=5 → stop
 *
 * i = 6: idx=1, num=7
 *  7 > arr[3]=5 → result[3]=7; pop → st=[1]
 *  7 ≤ arr[1]=7 → stop
 *
 * i = 7: idx=2, num=3
 *  3 ≤ arr[1]=7 → nothing
 *
 * i = 8: idx=3, num=5
 *  5 ≤ arr[1]=7 → nothing
 *
 * i = 9: idx=4, num=1
 *  1 ≤ arr[1]=7 → nothing
 *
 * End: st=[1] → result[1] stays -1
 * Final Output: [7, -1, 5, 7, 2]
 */

int main()
{
    brute();
    return 0;
}
