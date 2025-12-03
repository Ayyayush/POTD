// Disconnect repository — commands to run from repo root:
//
// Option A — remove remote (keeps local git history):
//   git remote remove origin
//   git remote -v
//
// Option B — remove git tracking entirely (destructive: deletes local git metadata):
//   Command Prompt:
//     rmdir /s /q .git
//   PowerShell:
//     Remove-Item -Recurse -Force .git
//   Git Bash / POSIX:
//     rm -rf .git
//
// Verify:
//   git status
//

class Solution {
  public:
    int n;                                            // number of cities
    vector<vector<int>> dp;                           // dp[mask][pos]
    vector<vector<int>> c;                            // cost matrix (copied)

    int solve(int mask, int pos) {
        // If all cities are visited (all bits set)
        if (mask == (1 << n) - 1) {
            return c[pos][0];                         // return cost to go back to city 0
        }

        if (dp[mask][pos] != -1) return dp[mask][pos];

        int ans = INT_MAX;

        // Try to go to every unvisited city
        for (int city = 0; city < n; city++) {
            if ((mask & (1 << city)) == 0) {          // if 'city' not yet visited
                int newMask = mask | (1 << city);     // mark 'city' as visited
                int nextCost = solve(newMask, city);  // cost from new state
                if (nextCost != INT_MAX && c[pos][city] != INT_MAX) {
                    ans = min(ans, c[pos][city] + nextCost);
                }
            }
        }

        return dp[mask][pos] = ans;
    }

    int tsp(vector<vector<int>>& cost) {
        c = cost;
        n = (int)c.size();

        // dp size: (2^n) x n, initialized with -1
        dp.assign(1 << n, vector<int>(n, -1));

        // Start from city 0, only city 0 is visited initially → mask = 1 (bit 0 set)
        int mask = 1;
        int startCity = 0;

        return solve(mask, startCity);
    }
};


// 