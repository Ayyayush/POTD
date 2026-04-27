/****************************************************************** C++ ******************************************************************
 * Problem: 1391. Check if There is a Valid Path in a Grid
 * 
 * Approach: DFS with Direction Compatibility Check
 * 
 * Intuition:
 * - Har cell kuch specific directions me move allow karta hai
 * - Move tabhi valid hoga jab next cell reverse direction support kare
 * 
 * T.C : O(m * n)
 *        Har cell maximum ek baar visit hota hai
 * 
 * S.C : O(m * n)
 *        visited array + recursion stack (worst case)
 ******************************************************************/

class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> directions;

    void DFS(int r, int c, vector<vector<int>>& grid,
             vector<vector<bool>>& visited) {
        
        int m = grid.size();
        int n = grid[0].size();

        if (r < 0 || c < 0 || r >= m || c >= n || visited[r][c])
            return;

        visited[r][c] = true;

        for (auto dir : directions[grid[r][c]]) {
            int newrow = r + dir.first;
            int newcol = c + dir.second;

            // boundary check
            if (newrow < 0 || newcol < 0 || newrow >= m || newcol >= n)
                continue;

            // reverse connection check
            bool valid = false;

            for (auto back : directions[grid[newrow][newcol]]) {
                int br = newrow + back.first;
                int bc = newcol + back.second;

                if (br == r && bc == c) {
                    valid = true;
                    break;
                }
            }

            if (valid) {
                DFS(newrow, newcol, grid, visited);
            }
        }
    }

    bool hasValidPath(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // direction mapping
        directions[1] = {{0, -1}, {0, 1}};
        directions[2] = {{-1, 0}, {1, 0}};
        directions[3] = {{0, -1}, {1, 0}};
        directions[4] = {{0, 1}, {1, 0}};
        directions[5] = {{0, -1}, {-1, 0}};
        directions[6] = {{0, 1}, {-1, 0}};

        DFS(0, 0, grid, visited);

        return visited[m - 1][n - 1];
    }
};






/****************************************************************** C++ ******************************************************************
 * Problem: 1391. Check if There is a Valid Path in a Grid
 * 
 * Approach: BFS with Direction Compatibility Check
 * 
 * Intuition:
 * - Level-wise traversal using queue
 * - Har move ke liye reverse connection validate karna zaroori hai
 * 
 * T.C : O(m * n)
 *        Har cell ek baar queue me aata hai
 * 
 * S.C : O(m * n)
 *        visited array + queue space
 ******************************************************************/

class Solution {
public:
    unordered_map<int, vector<pair<int,int>>> directions;

    bool hasValidPath(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // direction mapping
        directions[1] = {{0,-1}, {0,1}};
        directions[2] = {{-1,0}, {1,0}};
        directions[3] = {{0,-1}, {1,0}};
        directions[4] = {{0,1}, {1,0}};
        directions[5] = {{0,-1}, {-1,0}};
        directions[6] = {{0,1}, {-1,0}};

        queue<pair<int,int>> q;

        // start from (0,0)
        q.push({0,0});
        visited[0][0] = true;

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            // reached destination
            if(r == m-1 && c == n-1)
                return true;

            for(auto dir : directions[grid[r][c]])
            {
                int newrow = r + dir.first;
                int newcol = c + dir.second;

                // boundary check
                if(newrow < 0 || newcol < 0 || newrow >= m || newcol >= n)
                    continue;

                if(visited[newrow][newcol]) continue;

                // reverse connection check
                bool valid = false;

                for(auto back : directions[grid[newrow][newcol]])
                {
                    int br = newrow + back.first;
                    int bc = newcol + back.second;

                    if(br == r && bc == c)
                    {
                        valid = true;
                        break;
                    }
                }

                if(valid)
                {
                    visited[newrow][newcol] = true;
                    q.push({newrow, newcol});
                }
            }
        }

        return false;
    }
};


/****************************************************************** C++ ******************************************************************
 * Problem: 1391. Check if There is a Valid Path in a Grid
 * 
 * Approach: DFS with Direction Compatibility Check
 * 
 * Fix:
 * - Next cell must support reverse direction
 * 
 * T.C : O(m * n)
 * S.C : O(m * n)
 ******************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
     * Direction vectors
     */
    vector<pair<int,int>> dir = {
        {-1,0}, {1,0}, {0,-1}, {0,1}
    };

    /*
     * Opposite direction mapping
     */
    vector<int> opposite = {1,0,3,2};

    /*
     * Street type → allowed directions
     */
    unordered_map<int, vector<int>> mp = {
        {1, {2,3}},     // left, right
        {2, {0,1}},     // up, down
        {3, {2,1}},     // left, down
        {4, {3,1}},     // right, down
        {5, {2,0}},     // left, up
        {6, {3,0}}      // right, up
    };

    void DFS(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited)
    {
        int m = grid.size();
        int n = grid[0].size();

        visited[r][c] = true;

        int type = grid[r][c];

        /*
         * Try all valid directions
         */
        for(int d : mp[type])
        {
            int nr = r + dir[d].first;
            int nc = c + dir[d].second;

            if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if(visited[nr][nc]) continue;

            int nextType = grid[nr][nc];

            /*
             * Check reverse connection
             */
            for(int nd : mp[nextType])
            {
                if(nd == opposite[d])
                {
                    DFS(nr, nc, grid, visited);
                    break;
                }
            }
        }
    }

    bool hasValidPath(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        DFS(0, 0, grid, visited);

        return visited[m-1][n-1];
    }
};