class Solution {
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        
        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; i++) parent[i] = i;
        
        function<int(int)> findp = [&](int x) {
            if (parent[x] == x) return x;
            return parent[x] = findp(parent[x]);
        };
        
        auto unite = [&](int a, int b) {
            a = findp(a);
            b = findp(b);
            if (a == b) return 0;     // already connected → extra edge
            if (rank[a] < rank[b]) parent[a] = b;
            else if (rank[b] < rank[a]) parent[b] = a;
            else {
                parent[b] = a;
                rank[a]++;
            }
            return 1; // merged successfully
        };
        
        int extra = 0;
        
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            if (!unite(u, v)) extra++;   // this edge is redundant
        }
        
        // count connected components
        int components = 0;
        for (int i = 0; i < V; i++) {
            if (findp(i) == i) components++;
        }
        
        int needed = components - 1;
        
        if (extra >= needed) return needed;
        return -1;
    }
};
