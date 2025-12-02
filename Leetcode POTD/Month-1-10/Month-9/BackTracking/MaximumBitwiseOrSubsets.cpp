#include <bits/stdc++.h>
using namespace std;

// Global variables for result tracking
int maxbitwise = INT_MIN;         // sabse bada OR store karega
int count = 0;                    // us max OR ke equal kitne subsets mile, unka count

// Recursive function to generate all subsets and calculate bitwise OR
void bitsubsets(vector<int>& nums, vector<int>& subset, int idx)
{
    // Base case: jab index pura array traverse kar le
    if (idx >= nums.size())
    {
        int result = 0;

        // Current subset ka bitwise OR calculate karo
        for (int i = 0; i < subset.size(); i++)
        {
            result |= subset[i];                 // bitwise OR operation
        }

        // Agar naya result max se bada hai
        if (result > maxbitwise)
        {
            maxbitwise = result;                 // naya max set karo
            count = 1;                           // count reset karo (new max mila)
        }
        else if (result == maxbitwise)
        {
            count++;                             // same max mila, to count badhao
        }

        return;                                   // backtrack
    }

    // Option 1: Include current element in subset
    subset.push_back(nums[idx]);                  // add element
    bitsubsets(nums, subset, idx + 1);            // next index ke liye call

    // Option 2: Exclude current element from subset
    subset.pop_back();                            // element hatao (backtrack)
    bitsubsets(nums, subset, idx + 1);            // next index ke liye call
}

void brute()
{
    // Time Complexity: O(2^n)
    // Space Complexity: O(n) for recursion + subset storage

    vector<int> nums = {3, 1};                   // Input array

    vector<int> subset;                          // Subset container
    bitsubsets(nums, subset, 0);                 // Start recursion from index 0

    // Final Output
    cout << "Maximum Bitwise OR: " << maxbitwise << endl;
    cout << "Count of subsets with max OR: " << count << endl;
}

int main()
{
    brute();
    return 0;
}
