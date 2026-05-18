class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size(),minElt=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<minElt)
            minElt=nums[i];
        }

        return minElt;
        
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size(),minElt=INT_MAX;
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            minElt=min(minElt,nums[mid]);
            if(nums[mid]>nums[r])
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }

        }
       

        return minElt;
        
    }
};