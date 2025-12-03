class Solution {
public:
    struct DSU {
        vector<int> parent, size;
        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for(int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int x) {
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        bool unite(int a, int b) {
            a = find(a);
            b = find(b);
            if(a == b) return false;
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
    };

    int secondMST(int V, vector<vector<int>> &edges) {
        vector<array<int,3>> e;
        for(auto &x : edges) e.push_back({x[0], x[1], x[2]});

        sort(e.begin(), e.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });

        DSU dsu(V);

        int mstWeight = 0;
        vector<bool> used(e.size(), false);

        // Build MST using Kruskal
        for(int i = 0; i < e.size(); i++){
            int u = e[i][0], v = e[i][1], w = e[i][2];
            if(dsu.unite(u, v)){
                mstWeight += w;
                used[i] = true;
            }
        }

        // Try removing each MST edge and recompute another MST
        int secondBest = 1e9;

        for(int i = 0; i < e.size(); i++){
            if(!used[i]) continue;

            DSU temp(V);
            int weight = 0, cnt = 0;

            for(int j = 0; j < e.size(); j++){
                if(i == j) continue;
                int u = e[j][0], v = e[j][1], w = e[j][2];
                if(temp.unite(u, v)){
                    weight += w;
                    cnt++;
                }
            }

            if(cnt == V - 1 && weight > mstWeight)
                secondBest = min(secondBest, weight);
        }

        if(secondBest == 1e9) return -1;
        return secondBest;
    }
};
