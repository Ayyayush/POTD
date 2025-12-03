class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size();
        
        int OR = 0;
        for (int x : arr) {
            OR |= x;
        }
        
        long long mul = 1LL << (n - 1);   // 2^(n-1)
        long long ans = mul * OR;
        
        return (int)ans;                  // guaranteed to fit in 32-bit as per problem
    }
};
