class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        sort(nums.rbegin(), nums.rend());

        int max = nums[0];
        __int128  sum = 0;
        int min=nums[nums.size()-1];
        sum+=1L *(k)*(max-min);
        
        return sum;
    }
};


//Approach (Linear Scan - find max and min)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxEl = INT_MIN;
        int minEl = INT_MAX;

        for(int &num : nums) {
            maxEl = max(maxEl, num);
            minEl = min(minEl, num);
        }

        return 1LL*(maxEl - minEl)*k;
    }
};

