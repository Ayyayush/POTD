class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        int count=1,maxsub=1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                count++;
                maxsub=max(count,maxsub);
            }
            else
            {
                count=1;
            }
        }

        return maxsub;
    }
};