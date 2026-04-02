class Solution {
public:

    const int inf = 1e9+7;

    int func(int i, int j, int rem, vector <vector<int>> &arr, vector <vector <vector <int>>> &dp) {
    int n = arr.size();
    int m = arr[0].size();
    if(dp[i][j][rem] != -inf) return dp[i][j][rem];
    if (i == n-1 && j == m-1) {
        if(arr[i][j] >= 0) {
            return arr[i][j];
        }
        else {
            if(rem > 0) {
                return 0;
            }
            else {
                return arr[i][j];
            }
        }
    }
    int ans = INT_MIN;
    if(arr[i][j] < 0) {
        if(rem-1 >=0) {
            if(i+1 < n) ans = max(ans,func(i+1,j,rem-1,arr,dp));
            if(j+1 < m) ans = max(ans,func(i,j+1,rem-1,arr,dp));
        }
        if(i+1 < n) ans = max(ans,arr[i][j]+func(i+1,j,rem,arr,dp));
        if(j+1 < m) ans = max(ans,arr[i][j]+func(i,j+1,rem,arr,dp));
    }
    else {
        if(i+1 < n) ans = max(ans,arr[i][j]+func(i+1,j,rem,arr,dp));
        if(j+1 < m) ans = max(ans,arr[i][j]+func(i,j+1,rem,arr,dp));
    }
    return dp[i][j][rem] = ans;
}
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3,-inf)));
        return func(0,0,2,coins,dp);
    }
};