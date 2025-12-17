class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
         int n = nums.size();
    int totalSubsets = (1 << n); // 2^n subsets
    vector<vector<int>>ans;

    for (int mask = 0; mask < totalSubsets; mask++)
    { // O(2^n) loop
        vector<int> subset;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            { // Agar ith bit set hai toh element include karo
                subset.push_back(nums[i]);
            }
        }
        ans.push_back(subset);
    }
return ans;
    }
};