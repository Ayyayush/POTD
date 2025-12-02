#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{1, 1}, {-1, 1}, {0, 1}};   // 3 directions: down-right, up-right, right
int maxsum = 0;                                               // Global max sum

void dfs(vector<vector<int>> &mat, int i, int j, int m, int n, int sum)
{
    if (i < 0 || j < 0 || i >= m || j >= n || mat[i][j] == -1000)
        return;

    int temp = mat[i][j];
    sum += temp;
    maxsum = max(maxsum, sum);

    mat[i][j] = -1000;   // Mark visited

    for (auto dir : directions)
    {
        int ni = i + dir[0];
        int nj = j + dir[1];
        dfs(mat, ni, nj, m, n, sum);
    }

    mat[i][j] = temp;    // Unmark (Backtrack)
}

void brute()
{
    // 🔴 Brute Force (DFS) Approach
    // T.C. = O(3^(m*n))     (exponential)
    // S.C. = O(m*n)         (recursion stack depth)

    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        dfs(mat, i, 0, m, n, 0);    // DFS from each row in 1st column
    }

    cout << maxsum << endl;
}






vector<vector<int>> directions = {{1, 1}, {-1, 1}, {0, 1}};     // 3 directions
int m, n;                                                       // Matrix dimensions

int dfs(vector<vector<int>> &mat, vector<vector<int>> &dp, int i, int j)
{
    // ✅ Boundary check
    if (i < 0 || i >= m || j < 0 || j >= n)
        return 0;

    // ✅ Memoization check
    if (dp[i][j] != -1)
        return dp[i][j];

    int maxGoldFromHere = 0;

    for (auto dir : directions)
    {
        int ni = i + dir[0];
        int nj = j + dir[1];

        maxGoldFromHere = max(maxGoldFromHere, dfs(mat, dp, ni, nj));
    }

    return dp[i][j] = mat[i][j] + maxGoldFromHere;   // Store and return answer
}

void better()
{
    // 🟡 Memoized DFS Approach
    // T.C. = O(m * n)
    // S.C. = O(m * n) + O(m + n) recursion stack

    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    vector<vector<int>> dp(m, vector<int>(n, -1));   // Memoization table

    int maxGoldCollected = 0;

    for (int i = 0; i < m; i++)
    {
        maxGoldCollected = max(maxGoldCollected, dfs(mat, dp, i, 0));   // Start from each row of column 0
    }

    cout << maxGoldCollected << endl;
}

int main()
{
    better();    // Call memoized version
    return 0;
}
