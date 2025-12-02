class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int i=0,j=0,maxcount=0;
        unordered_map<int,int>mp;
        while(j<nums.size())
        {
            mp[nums[j]]++;
            while(mp.size()>2)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                mp.erase(nums[i]);
                i++;
            }

            maxcount=max(maxcount,j-i+1);
         j++;
        }
        
        return maxcount;
    }
};