class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>mp;
        mp[0]++;
        int count=0,currsum=0;
        for(int i=0;i<arr.size();i++)
        {
            currsum+=arr[i];
            int required=currsum-k;
            if(mp.count(required)!=0)
            {
                count+=mp[required];
            }
            mp[currsum]++;
            
        }
        return count;
    }
};