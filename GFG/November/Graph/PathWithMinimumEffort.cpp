class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Directions: up, down, left, right
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        // Distance array -> stores MINIMUM possible maximum difference to reach each cell
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

        // Min-heap → (current_cost, x, y)
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int cost = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if(x == n-1 && y == m-1) return cost;

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m) {

                    // Edge cost = abs difference of adjacent cells
                    int edge = abs(mat[x][y] - mat[nx][ny]);

                    // New cost = max(existing cost, edge difference)
                    int newCost = max(cost, edge);

                    if(newCost < dist[nx][ny]) {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};
