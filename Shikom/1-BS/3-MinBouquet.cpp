class Solution {
public:
int bouquet(vector<int>&bloomDay,int mid,int k)
{
    int countconsecutive=0,bouquet=0;
    for(int i=0;i<bloomDay.size();i++)
    {
      if(bloomDay[i]<=mid)
      {
        countconsecutive++;
      }
      else
      {
        countconsecutive=0;
      }
      if(countconsecutive==k)
      {
        countconsecutive=0;
        bouquet++;
      }
    }
    return bouquet;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int l=0;
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        int mindays=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(bouquet(bloomDay,mid,k)>=m)
            {
                r=mid-1;
                mindays=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return mindays;
    }
};