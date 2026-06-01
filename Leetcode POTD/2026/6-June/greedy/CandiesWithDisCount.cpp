class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(),cost.rend());
        int n=cost.size();

        if(n==1)
        {
            return cost[0];
        }
        if(n==2)
        {
            return cost[0]+cost[1];
        }
        long long sum=0;

        for(int i=0;i<n;i+=3)
        {
            sum+=cost[i];
            if(i+1<n)
            sum+=cost[i+1];
        }

        return sum;
        
    }
};