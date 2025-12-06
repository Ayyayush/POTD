class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        int n = (int)nums.size();
        
        int P[n + 1];
        multiset<int> S;
        for(int r = 1, l = 1; r <= n; r ++){
            S.insert(nums[r - 1]);
            while(*prev(S.end()) - *S.begin() > k){
                S.erase(S.find(nums[l - 1]));
                l += 1;
            }
            P[r] = l;
            //current window [l, r]
        }

        int dp[n + 1];
        dp[0] = 1;
        for(int r = 1; r <= n; r ++){
            dp[r] = 0;
            int max_el = nums[r - 1];
            int min_el = nums[r - 1];
            for(int l = r; l >= P[r]; l --){
                max_el = max(max_el, nums[l - 1]);
                min_el = min(min_el, nums[l - 1]);
                if(max_el - min_el <= k){
                    dp[r] += dp[l - 1];
                    dp[r] %= mod;
                }
            }
        }
        return dp[n];
    }
};



class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        int n = (int)nums.size();
        int P[n];
        multiset<int> S;
        for(int r = 0, l = 0; r < n; r ++){
            S.insert(nums[r]);
            while(*prev(S.end()) - *S.begin() > k){
                S.erase(S.find(nums[l]));
                l += 1;
            }
            P[r] = l;
        }

        int dp[n + 1];
        int psum[n + 1];
        
        dp[0]   = 1;
        psum[0] = 1;
        for(int r = 0; r < n; r ++){
            int l = P[r];
            int rangedp = psum[r];
            if(l > 0) rangedp -= psum[l - 1];
            rangedp %= mod;
            if(rangedp < 0) rangedp += mod;
            dp[r + 1]   = rangedp;
            psum[r + 1] = (psum[r] + dp[r + 1]) % mod;
        }
        return dp[n];
    }
};







class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        int n = (int)nums.size();

        int dp[n + 1];
        int psum[n + 1];
        
        dp[0]   = 1;
        psum[0] = 1;

        //increasing
        deque<int> inc;
        //decreasing
        deque<int> dec;

        for(int r = 0, l = 0; r < n; r ++){
            while(!inc.empty() && nums[inc.back()] >= nums[r]){
                inc.pop_back();
            }
            inc.push_back(r);
            while(!dec.empty() && nums[dec.back()] <= nums[r]){
                dec.pop_back();
            }
            dec.push_back(r);
            while(!inc.empty() && !dec.empty()){
                if(nums[dec.front()] - nums[inc.front()] > k){
                    if(inc.front() == l) inc.pop_front();
                    if(dec.front() == l) dec.pop_front();
                    l += 1;
                }
                else{
                    break;
                }
            }
            int rangedp = psum[r];
            if(l > 0) rangedp -= psum[l - 1];
            rangedp %= mod;
            if(rangedp < 0) rangedp += mod;

            dp[r + 1]   = rangedp;
            psum[r + 1] = (psum[r] + dp[r + 1]) % mod;
        }
        return dp[n];
    }
};