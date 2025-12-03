class Solution {
  public:
    /*
        APPROACH : Dijkstra + Ways Counting
        -----------------------------------
        - Weighted graph hai → Dijkstra best.
        - dist[] : har node tak shortest time.
        - ways[] : shortest time se us node tak pahunchne ke kitne tareeke.
        
        LOGIC:
        - Jab naya shorter distance mile → ways overwrite.
        - Jab equal shortest mile → ways add.

        TIME COMPLEXITY : O(E log V)
        SPACE COMPLEXITY : O(V + E)
    */

    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);             // adjacency list

        // graph build karna
        for(auto &it : roads) {
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<long long> dist(n, LLONG_MAX);             // shortest distance array
        vector<long long> ways(n, 0);                     // number of shortest paths array

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;  // min-heap

        dist[0] = 0;                                      // start from node 0
        ways[0] = 1;                                      // 0 se 0 jaane ka ek hi tareeka
        pq.push({0, 0});

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            long long currDist = top.first;
            int node = top.second;

            if(currDist > dist[node]) continue;           // stale entries skip

            for(auto &nbr : adj[node]) {
                int next = nbr.first;
                long long wt = nbr.second;

                long long newDist = currDist + wt;

                // Case 1: Better (shorter) distance mil gaya
                if(newDist < dist[next]) {
                    dist[next] = newDist;
                    ways[next] = ways[node];              // overwrite with parent ways
                    pq.push({newDist, next});
                }

                // Case 2: Same shortest distance → additional path
                else if(newDist == dist[next]) {
                    ways[next] = (ways[next] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;                           // answer = destination ke ways
    }
};
