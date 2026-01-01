/**
 * ⚠️ You're generating all subsets recursively, which is exponential (O(2^n)), and you're trying to use memoization, but memoization tab kaam karta hai jab:
Subproblems repeat multiple times (i.e., overlapping subproblems).

You can define your recursion in terms of state.

Subset generation mein har subset unique hota hai (based on inclusion/exclusion), so direct memoization is not very effective — kyunki repeated state waise nahi aata.


 */

class Solution
{
public:
    int maxcount = 0;

    void findSubsets(vector<int> &nums, vector<int> &subset, int index)
    {
        if (index == nums.size())
        {
            if (!subset.empty())
            {
                vector<int> temp = subset;
                sort(temp.begin(), temp.end());
                if (temp.back() - temp[0] == 1)
                {
                    maxcount = max(maxcount, (int)temp.size());
                }
            }
            return;
        }

        subset.push_back(nums[index]);
        findSubsets(nums, subset, index + 1);

        subset.pop_back();
        findSubsets(nums, subset, index + 1);
    }

    int findLHS(vector<int> &nums)
    {
        vector<int> subset;
        findSubsets(nums, subset, 0);
        return maxcount;
    }
};
