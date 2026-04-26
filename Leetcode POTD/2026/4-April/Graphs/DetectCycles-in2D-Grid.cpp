/****************************************************************** C++ ******************************************************************/

//Approach-1 (Using DFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;

    // 4-directional movement (down, up, left, right)
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    // DFS function to detect cycle
    bool cycleDetectDFS(int r, int c, int prev_r, int prev_c, 
                        vector<vector<char>>& grid, vector<vector<bool>>& visited ) {

        // if already visited → cycle found
        if(visited[r][c]) {
            return true;
        }

        // mark current cell visited
        visited[r][c] = true;

        // explore all 4 directions
        for(auto &dir : directions) {
            int new_r = r + dir[0]; 
            int new_c = c + dir[1];

            // check valid cell + same character
            if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n
                && grid[new_r][new_c] == grid[r][c]) {

                // skip the parent cell (important to avoid false cycle)
                if(new_r == prev_r && new_c == prev_c)
                    continue;
                
                // recursive DFS call
                if(cycleDetectDFS(new_r, new_c, r, c, grid, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // visited matrix
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // check every cell
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // start DFS if not visited
                if(!visited[i][j] && cycleDetectDFS(i, j, i, j, grid, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};



/****************************************************************** C++ ******************************************************************/

//Approach-2 (Using BFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;

    // 4-directional movement
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    bool cycleDetectBFS(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited) {

        // queue stores: current cell + parent cell
        queue<tuple<int, int, int, int>> que;

        que.push({r, c, -1, -1});
        visited[r][c] = true;

        while(!que.empty()) {
            auto [curr_r, curr_c, prev_r, prev_c] = que.front();
            que.pop();

            // explore neighbours
            for(auto &dir : directions) {
                int new_r = curr_r + dir[0];
                int new_c = curr_c + dir[1];

                // valid cell + same character
                if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n
                && grid[new_r][new_c] == grid[curr_r][curr_c]) {
                    
                    // skip parent
                    if(new_r == prev_r && new_c == prev_c)
                        continue;
                    
                    // already visited → cycle found
                    if(visited[new_r][new_c])
                        return true;
                    
                    // mark visited and push to queue
                    visited[new_r][new_c] = true;
                    que.push({new_r, new_c, curr_r, curr_c});
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // traverse all cells
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // start BFS if not visited
                if(!visited[i][j] && cycleDetectBFS(i, j, grid, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};