#include <bits/stdc++.h>
using namespace std;

void findSubsets(vector<int> &nums, vector<int> &subset, int index,int target,int& count)
{
    // Base Case: If index reaches the end of nums array, print the subset
    if (index == nums.size())
    {
        int sum=0;
        for (auto it : subset)
        {
           sum+=it;
        }
        cout<<endl;
        if(sum<=target)
        count++;
       
        return;
    }

    // Recursive Case 1: Include the current element
    subset.push_back(nums[index]);        // Add element to subset
    findSubsets(nums, subset, index + 1,target,count); // Recur with next index

    // Recursive Case 2: Exclude the current element
    subset.pop_back();                    // Backtrack: Remove last element
    findSubsets(nums, subset, index + 1,target,count); // Recur without adding element
}

int main()
{
    vector<int> nums{1,2,3};
    vector<int> subset; // Temporary subset storage
    int target,count=0;
    cin>>target;
   
    findSubsets(nums, subset, 0,target,count); // Start recursion

    cout<<count<<endl;

   
    return 0;
}
