class Solution {
public:
    int countTriples(int n) {
        int count=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    int s1=i*i;
                    int s2=j*j;
                    int s3=k*k;
                    if(s1+s2==s3)
                    count++;
                }
            }
        }

        return count;
        
    }
};

