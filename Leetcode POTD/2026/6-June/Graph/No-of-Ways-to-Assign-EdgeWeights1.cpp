/**
 * Leetcode 3558
 *
 * undirected tree diya h
 * initially har edge ka weight 0 h
 * hume 1 ya 2 weight assign krna h
 * count nikalna h
 *
 * select any one node at maximum depth
 * return no. of ways to assign weights in the path
 * modulo karna h
 *
 * ignore all nodes not in the path 1 -> x
 *
 * eg:
 * 1 --> 2
 * ek hi edge h
 * ans = 1
 *
 * Tree Structure
 *
 *          1
 *         / \
 *        2   3
 *           / \
 *          4   5
 *
 * 1 se 5 jaane mein 3 bhi h
 *
 * (1,2) kar sakte h
 * (2,1) kar sakte h
 *
 * ans = 2
 *
 * Constraints dekho:
 * edges represent a valid tree
 *
 * pehle maximum depth wala node find karo
 *
 * DFS use kar sakte h
 *
 * ye binary tree nahi h
 * ek node ke multiple child ho sakte h
 *
 * binary tree mein depth nikalna aata h
 *
 * int depth(root)
 * {
 *     if(root == NULL)
 *         return 0;
 *
 *     int leftDepth  = depth(root->left);
 *     int rightDepth = depth(root->right);
 *
 *     return max(leftDepth,rightDepth) + 1;
 * }
 *
 * yaha graph/tree undirected h
 * aur ek node ke multiple neighbours ho sakte h
 *
 * let's see graph mein depth kaise nikale
 *
 * Tree Structure
 *
 *          1
 *        / | \
 *       /  |  \
 *      2   |   6
 *           \
 *            3
 *           / \
 *          4   5
 *
 * edges = [
 *   [1,2],
 *   [1,3],
 *   [1,6],
 *   [3,4],
 *   [3,5]
 * ]
 *
 * Adjacency List
 *
 * 1 -> {2,3,6}
 * 2 -> {1}
 * 3 -> {1,4,5}
 * 4 -> {3}
 * 5 -> {3}
 * 6 -> {1}
 *
 * int getMaxDepth(adj,node)
 * {
 *     int maxDepth = 0;
 *
 *     for(int neighbor : adj[node])
 *     {
 *         maxDepth =
 *         max(maxDepth,getMaxDepth(adj,neighbor)+1);
 *     }
 *
 *     return maxDepth;
 * }
 *
 * Problem:
 * graph undirected h
 *
 * 1 -> 2
 * fir 2 -> 1 bhi dikhega
 *
 * infinite recursion lag jayegi
 *
 * so parent maintain karenge
 *
 * recursion call karte time parent pe
 * dobara nahi jayenge
 *
 * if(neighbor == parent)
 *     continue;
 *
 * ab graph/tree ki maximum depth mil gayi
 *
 * --------------------------------------------------
 * Ab weight assignment samjhte h
 * --------------------------------------------------
 *
 * edge1   edge2   sum
 * -------------------
 *   1       1      2   ❌
 *   1       2      3   ✅
 *   2       1      3   ✅
 *   2       2      4   ❌
 *
 * Observation:
 * Sum odd hona chahiye
 *
 * --------------------------------------------------
 *
 * edge1   edge2   sum
 * -------------------
 *   1       1      2 (even) ❌
 *
 *   2       1      3 (odd)  ✅
 *
 *   1       2      3 (odd)  ✅
 *
 *   2       2      4 (even) ❌
 *
 * Observation:
 *
 * Sum odd tabhi banega jab
 * ek edge odd ho
 * aur doosri edge even ho
 *
 * Valid pairs:
 * (1,2)
 * (2,1)
 *
 * Invalid pairs:
 * (1,1)
 * (2,2)
 *
 * maan lo (1,1) h
 *
 * kisi ek ko flip kar do
 * (2,1) ya (1,2)
 *
 * odd ban jayega
 *
 * similarly (2,2) mein bhi
 * ek ko flip kar do
 *
 * odd ban jayega
 *
 * iska matlab:
 *
 * total possibilities ka exactly half
 * odd sum degi
 *
 * agar path mein d edges hain:
 *
 * total possibilities = 2^d
 *
 * odd possibilities = 2^(d-1)
 *
 * --------------------------------------------------
 * Story to Code
 * --------------------------------------------------
 *
 * 1. Find maximum depth
 * 2. Let depth = d
 * 3. Answer = 2^(d-1)
 * 4. Modulo lagao
 */



// Approach: DFS to find max depth + Fast Exponentiation
// T.C : O(n) for DFS + O(log n) for power
// S.C : O(n) for adjacency list + O(n) recursion stack

class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    long long power(long long base, long long exponent) {
        if (exponent == 0)
            return 1;

        long long half = power(base, exponent / 2);

        long long result = (half * half) % MOD;

        if (exponent % 2 == 1)
            result = (result * base) % MOD;

        return result;
    }

    int getMaxDepth(unordered_map<int, vector<int>>& adj,
                    int node,
                    int parent) {

        int depth = 0;

        for (int neighbor : adj[node]) {

            if (neighbor == parent)
                continue;

            depth = max(depth,
                        getMaxDepth(adj, neighbor, node) + 1);
        }

        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;

        for (auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxDepth = getMaxDepth(adj, 1, 0);

        return power(2, maxDepth - 1);
    }
};