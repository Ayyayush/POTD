class Solution {
public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {

        vector<vector<pair<int,int>>> adj(V);   // u → (v, w1) straight edges
        vector<vector<pair<int,int>>> curved(V); // u → (v, w2) curved edges

        for(auto &e : edges) {
            int x = e[0], y = e[1];
            int w1 = e[2], w2 = e[3];

            adj[x].push_back({y, w1}); adj[y].push_back({x, w1});            // straight
            curved[x].push_back({y, w2}); curved[y].push_back({x, w2});      // curved
        }

        const int INF = 1e18;

        vector<long long> dist0(V, INF);   // no curved edge used yet
        vector<long long> dist1(V, INF);   // curved edge already used

        priority_queue<
            pair<long long, pair<int,int>>,
            vector<pair<long long, pair<int,int>>>,
            greater<pair<long long, pair<int,int>>>
        > pq;

        dist0[a] = 0;
        pq.push({0, {a, 0}}); // (dist, node, usedCurved?)

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            long long d = it.first;
            int u = it.second.first;
            int used = it.second.second;

            if(used == 0 && d > dist0[u]) continue;
            if(used == 1 && d > dist1[u]) continue;

            // ---- Take straight edges ----
            for(auto &p : adj[u]) {
                int v = p.first;
                long long w = p.second;

                if(used == 0) {
                    if(dist0[v] > d + w) {
                        dist0[v] = d + w;
                        pq.push({dist0[v], {v, 0}});
                    }
                } else {
                    if(dist1[v] > d + w) {
                        dist1[v] = d + w;
                        pq.push({dist1[v], {v, 1}});
                    }
                }
            }

            // ---- Take curved edges (only if used == 0) ----
            if(used == 0) {
                for(auto &p : curved[u]) {
                    int v = p.first;
                    long long w = p.second;

                    if(dist1[v] > d + w) {
                        dist1[v] = d + w;
                        pq.push({dist1[v], {v, 1}});
                    }
                }
            }
        }

        long long ans = min(dist0[b], dist1[b]);
        return (ans >= INF ? -1 : (int)ans);
    }
};
