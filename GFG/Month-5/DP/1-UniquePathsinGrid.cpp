#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// Recursive function without memoization
int recurSolve(vector<vector<int>> &nums, int i, int j, int r, int c)
{
    if (i >= r || j >= c || nums[i][j] == 1)
        return 0;

    if (i == r - 1 && j == c - 1)
        return 1;

    return recurSolve(nums, i + 1, j, r, c) + recurSolve(nums, i, j + 1, r, c);
}

// Recursive function with memoization
int recurMemo(vector<vector<int>> &nums, int i, int j, int r, int c, vector<vector<int>> &dp)
{
    if (i >= r || j >= c || nums[i][j] == 1)
        return 0;

    if (i == r - 1 && j == c - 1)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = recurMemo(nums, i + 1, j, r, c, dp) + recurMemo(nums, i, j + 1, r, c, dp);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r = 3, c = 7;
    vector<vector<int>> grid(r, vector<int>(c, 0)); // 0 means no obstacle

    // Recursive call
    cout << "Recursive (No Memo): " << recurSolve(grid, 0, 0, r, c) << endl;

    // Memoized call
    vector<vector<int>> dp(r, vector<int>(c, -1));
    cout << "Recursive + Memoization: " << recurMemo(grid, 0, 0, r, c, dp) << endl;

    return 0;
}
