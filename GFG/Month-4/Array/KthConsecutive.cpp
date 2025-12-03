#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity:
-> Outer loop runs O(n^2) for all subarrays.
-> Each insertion in set is O(1) avg, so total O(n^2) insertions.
-> Copying set to vector: O(n^2)
-> Sorting: O(n^2 * log n^2) => O(n^2 log n)

Total: O(n^2 log n) time and O(n^2) space

Note: We are storing only unique subarray sums.
*/

void brute()
{
    vector<int> arr = {1, 2, 3}; // Sample input array
    int k = 2;                      // Example: find 2nd largest subarray sum

    unordered_set<int> st; 
    vector<int> nums;

    // Har subarray ka sum calculate karo
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j]; // subarray sum
            st.insert(sum); // unique sums insert karo set mein
        }
    }

    // Set se vector mein copy karo
    for (auto it : st)
    {
        nums.push_back(it);
    }

    // Sort karo descending order mein
    sort(nums.begin(), nums.end(), greater<int>());

    // Kth largest subarray sum print karo
    cout << k << "th largest unique subarray sum: " << nums[k - 1] << endl;
}



void better()
{
    
}
int main()
{
    brute();
    return 0;
}
