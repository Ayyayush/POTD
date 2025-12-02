class Solution {
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) 
    {
        int n = s.size();

        // Graph cost initialization
        const int INF = 1e9;
        vector<vector<int>> dist(26, vector<int>(26, INF));

        // 0 cost to stay same
        for (int i = 0; i < 26; i++) 
            dist[i][i] = 0;

        // Fill given transformation costs
        for (int i = 0; i < transform.size(); i++) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);   // take minimum if duplicate
        }

        // Floyd–Warshall to compute all-pairs minimum transformation cost
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        long long totalCost = 0;

        // For each index, find best common character
        for (int i = 0; i < n; i++) {
            int c1 = s[i] - 'a';
            int c2 = t[i] - 'a';

            int best = INF;

            // Try making both equal to every possible char 'a' to 'z'
            for (int x = 0; x < 26; x++) {
                if (dist[c1][x] < INF && dist[c2][x] < INF) {
                    best = min(best, dist[c1][x] + dist[c2][x]);
                }
            }

            if (best == INF) 
                return -1;    // no valid common character

            totalCost += best;
        }

        return totalCost;
    }
};
