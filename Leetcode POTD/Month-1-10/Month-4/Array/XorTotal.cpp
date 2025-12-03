#include <bits/stdc++.h>
using namespace std;

void findSubsets(vector<int> &nums, vector<int> &subset, int index,int &totalsum) {
    // Base Case: If index reaches the end of nums array, print the subset
    if (index == nums.size()) 
    {
        long long ans=0;
        for (auto it : subset) {
            cout << it << " "; // Print the subset
            ans^=it;
        }
        totalsum+=ans;
        cout << endl;
        return;
    }

    // Recursive Case 1: Include the current element
    subset.push_back(nums[index]);  // Add element to subset
    findSubsets(nums, subset, index + 1,totalsum); // Recur with next index


      // Recursive Case 2: Exclude the current element
    subset.pop_back(); // Backtrack: Remove last element                                               
    findSubsets(nums, subset, index + 1,totalsum); // Recur without adding element
}

void helper() {
    int n;
    cin >> n; // Input size of array
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // Input elements
    }

    vector<int> subset; // Temporary subset storage
    int totalsum=0;
    findSubsets(nums, subset, 0,totalsum); // Start recursion
    cout<<totalsum<<endl;
}

int main() {
    helper();
    return 0;
}
 