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





from typing import List

class Solution:
    
    def bouquet(self, bloomDay: List[int], mid: int, k: int) -> int:
        count_consecutive = 0
        bouquet = 0

        for i in range(len(bloomDay)):
            if bloomDay[i] <= mid:
                count_consecutive += 1
            else:
                count_consecutive = 0

            if count_consecutive == k:
                bouquet += 1
                count_consecutive = 0

        return bouquet

    
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        n = len(bloomDay)

        # not enough flowers
        if m * k > n:
            return -1

        l = min(bloomDay)
        r = max(bloomDay)
        minday = -1

        while l <= r:
            mid = l + (r - l) // 2

            if self.bouquet(bloomDay, mid, k) >= m:
                minday = mid
                r = mid - 1
            else:
                l = mid + 1

        return minday
