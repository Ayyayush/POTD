class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        int sum1 = accumulate(apple.begin(), apple.end(), 0);   // fixed accumulate syntax

        sort(capacity.rbegin(), capacity.rend());               // fixed sort syntax

        int sum2 = 0, k = 0;

        for(int i = 0; i < capacity.size(); i++)
        {
            sum2 += capacity[i];
            k++;

            if(sum2 >= sum1)
                return k;
        }

        return -1;
    }
};
