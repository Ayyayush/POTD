class Solution {
public:
    int maxPower(string s) {

      int   maxcount=1,count=1;
        for(int i=1;i<s.size();i++)
        {
            int j=i;
            count=1;
            while(j<s.size() && s[j]==s[j-1])
            {
                count++;  
                maxcount=max(count,maxcount);
                j++;
            }

        }

        return maxcount;
        
    }
};