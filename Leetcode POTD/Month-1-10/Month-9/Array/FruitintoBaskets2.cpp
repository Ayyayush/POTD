class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        bool got;
        int count=0;
        for(int i=0;i<fruits.size();i++)
        {
            got =false;
            for(int j=0;j<baskets.size();j++)
            {
                if(fruits[i]<=baskets[j])
                {
                    got=true;
                    baskets[j]=-1234;
                    break;
                }
            }
            if(got==false)
            count++;
        }

        return count;
    }
};