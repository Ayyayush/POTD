#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int n, maximum, minimum, k = 1; // 'k' is the window size
    cin >> n;                       // Input the size of the array
    vector<int> arr(n);
    vector<int> vec; // Stores max of minimums for each window size

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input array elements
    }

    while (k <= arr.size())
    {                                                            // Iterate for each window size from 1 to n
        maximum = INT_MIN; 

        for (int i = 0; i <= (arr.size() - k); i++)
        {                                         // Ensure valid window bounds
            minimum = INT_MAX;                       // Reset min for each subarray

            for (int j = i; j < i + k; j++)
            {                                    // Iterate over window elements
                minimum = min(minimum, arr[j]); // Find min in the current window
            }

            maximum = max(maximum, minimum); // Track max of minimums
        }

        vec.push_back(maximum); // Store the result for this window size
        k++;                    // Increase window size
    }

    for (auto x : vec)
        cout << x << " "; // Print results for all window sizes
    cout << endl;
}


void better()
{   
    void better() {
        int n;
        cin >> n;  // Array size input
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];  // Input array elements
        }
    
        vector<int> res(n), len(n);
        stack<int> s;
    
        for (int i = 0; i <= n; i++) {  // Finding window lengths
            while (!s.empty() && (i == n || arr[s.top()] >= arr[i])) {
                int j = s.top();
                s.pop();
                len[j] = s.empty() ? i : i - s.top() - 1;  // Compute window length
            }
            if (i < n) s.push(i);
        }
    
        for (int i = 0; i < n; i++) 
            res[len[i] - 1] = max(res[len[i] - 1], arr[i]);  // Update max of min for each window size
    
        for (int i = n - 2; i >= 0; i--) 
            res[i] = max(res[i], res[i + 1]);  // Ensure max values are non-decreasing
    
        for (int x : res) cout << x << " ";  // Output result
        cout << endl;
    }
     
}
int main()
{
    brute();
    return 0;
}
