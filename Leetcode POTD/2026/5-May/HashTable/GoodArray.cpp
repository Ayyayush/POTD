class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        int maxelt = INT_MIN;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            maxelt = max(maxelt, nums[i]);
            mp[nums[i]]++;
        }

        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == maxelt)
                count++;
        }

        return maxelt == nums.size() - 1 && count == 2 &&
               mp.size() == nums.size() - 1;
    }
};