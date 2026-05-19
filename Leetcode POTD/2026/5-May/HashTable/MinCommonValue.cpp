class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // approach 1 nested 
        int m=nums1.size();
        int n=nums2.size();
        int minElt=INT_MAX;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(nums1[i]==nums2[j])
                {
                    minElt=min(minElt,nums1[i]);
                }
            }
        }

        return minElt;
        
    }
};


class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // approach 1 using hashmap; 
        int m=nums1.size();
        int n=nums2.size();
        int minElt=INT_MAX;
        unordered_map<int,int>mp;
        for(int i=0;i<m;i++)
        {
           mp[nums1[i]]++;
        }
         for(int j=0;j<n;j++)
            {
                if(mp.count(nums2[j]))
                {
                    minElt=min(minElt,nums2[j]);
                }
            }

        return minElt==INT_MAX?-1:minElt;
        
    }
};