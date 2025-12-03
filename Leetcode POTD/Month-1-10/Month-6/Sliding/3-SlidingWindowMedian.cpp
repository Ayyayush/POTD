#include <bits/stdc++.h>
using namespace std;

void better()
{
    int n, k;
    cin >> n >> k;                      // Input length of array and window size
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];                 // Input the array elements

    multiset<int> window;               // multiset keeps window elements sorted automatically
    vector<double> result;              // stores medians of each sliding window

    int i = 0, j = 0;                  // i = left pointer, j = right pointer of sliding window

    while (j < n)                      // iterate over array with right pointer
    {
        window.insert(nums[j]);        // insert current element in window

        if (j - i + 1 < k)             // window size smaller than k, just expand window
        {
            j++;                      
        }
        else if (j - i + 1 == k)       // window size exactly k, calculate median
        {
            // mid1 points to (k-1)/2th element (0-based)
            // mid2 points to k/2th element (0-based)
            auto mid1 = next(window.begin(), (k - 1) / 2);
            auto mid2 = next(window.begin(), k / 2);

            if (k % 2 == 0)
                // Even size: median = average of two middle elements
                result.push_back(((double)(*mid1) + *mid2) / 2.0);
            else
                // Odd size: median = middle element
                result.push_back((double)(*mid2));

            // Slide window by removing the leftmost element
            window.erase(window.find(nums[i]));

            i++;     // move left pointer forward
            j++;     // move right pointer forward
        }
    }

    // Print all medians
    for (double median : result)
        cout << median << " ";
    cout << "\n";
}

/*
Time Complexity (T.C.): 
- Inserting an element in multiset: O(log k)
- Removing an element from multiset: O(log k)
- For each of the n elements, we do insert and remove once => O(n log k)
- Accessing median via iterator: O(k) in worst case, but generally O(log k) due to balanced tree traversal
=> Overall T.C. ≈ O(n log k)

Space Complexity (S.C.):
- multiset stores k elements at any time => O(k)
- result vector stores approx n-k+1 medians => O(n)
=> Overall S.C. ≈ O(n)
*/

int main()
{
    better();      // run the sliding window median function
    return 0;
}
