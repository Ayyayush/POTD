class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>&nums) {
        sort(nums.begin(), nums.end());
        int mindiff = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            mindiff = min(mindiff, (nums[i] - nums[i - 1]));
        }

        vector<vector<int>>ans;
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] - nums[i - 1]) == mindiff) {
                ans.push_back({nums[i-1], nums[i]});
            }
        }

        return ans;
    }
};