class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size());
        int value = 0;

        for(int i = 0; i < nums.size(); i++) {
            value = (value * 2 + nums[i]) % 5;
            ans[i] = (value == 0);
        }

        return ans;
    }
};
