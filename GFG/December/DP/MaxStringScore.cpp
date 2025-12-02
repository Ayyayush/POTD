#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Approach: Brute force check all i->j jumps (O(n^2)) - will TLE for n up to 2e5.
    // Use only for tiny tests / verification.
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
}

void better()
{
    // Approach: Some pruning using prefix sums but still could be O(n * alphabet) or worse.
    // This is a sketch placeholder. Implementing intermediate (better) solutions is optional.
    // Time Complexity: depends on approach
    // Space Complexity: depends on approach
}

void optimal()
{
    // Approach: Dynamic Programming + prefix sums + best-per-destination-character bookkeeping.
    // Time Complexity: O( A * n + jumps.size() ) where A = alphabet size (26 here) -> effectively O(26*n).
    // Space Complexity: O(A * n) for prefix sums per character + O(A) for best array.
    // Reason: iterate indices j from right-to-left; maintain for each destination character 'c'
    //         best[c] = max over k>j of (prefTotal[k] - prefChar[c][k] + dp[k]).
    //         For index j and each allowed destination char c2, dp[j] = max(dp[j], best[c2] - (prefTotal[j] - prefChar[c2][j])).
    //         After computing dp[j], update best[s[j]] using dp[j].
    //
    // Note: This implementation assumes lowercase English letters ('a' - 'z') as in problem examples.
    //       If other characters appear, extend alphabet mapping accordingly.

    int n;
    string s;
    int m; // number of jump pairs

    // ---------- Input reading (custom input format for testing) ----------
    // The GeeksforGeeks stub expects function args; below is a small test harness.
    // For actual submission on GfG, move logic into the expected function signature.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(!(cin >> s)) return;               // read string s
    if(!(cin >> m)) {                      // if number of jumps not provided, assume 0
        m = 0;
    }

    vector<vector<char>> jumps;           // read m lines of two chars
    jumps.reserve(m);
    for(int i = 0; i < m; ++i)
    {
        char a, b;
        cin >> a >> b;
        jumps.push_back({a, b});
    }
    n = (int)s.size();

    const long long NEG_INF = LLONG_MIN / 4;

    // alphabet size and mapping: assume lowercase 'a'..'z'
    const int A = 26;

    // adjacency: for each source char idx, list of allowed destination char indices
    vector<array<bool, A>> allowed(A);
    for(int i = 0; i < A; ++i)
        for(int j = 0; j < A; ++j)
            allowed[i][j] = false;

    for(auto &p : jumps)
    {
        char a = p[0];
        char b = p[1];
        if(a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z')   // validate
        {
            allowed[a - 'a'][b - 'a'] = true;    // allowed jump from a -> b
        }
    }

    // also allow jumping to same character (rule): we will treat it explicitly below
    // build prefix sums:
    // prefTotal[i] = sum ascii of s[0..i-1]  (size n+1)
    vector<long long> prefTotal(n+1, 0LL);
    vector<vector<long long>> prefChar(A, vector<long long>(n+1, 0LL)); // prefChar[c][i] = sum ascii of char c in s[0..i-1]

    for(int i = 0; i < n; ++i)
    {
        int ch = s[i] - 'a';
        long long asciiVal = (long long)(unsigned char)s[i];
        prefTotal[i+1] = prefTotal[i] + asciiVal;
        for(int c = 0; c < A; ++c)
        {
            prefChar[c][i+1] = prefChar[c][i];
        }
        if(ch >= 0 && ch < A)
            prefChar[ch][i+1] += asciiVal;
    }

    // best[c] will store max over indices k already processed (k > current j in iteration)
    // of (prefTotal[k] - prefChar[c][k] + dp[k])
    vector<long long> best(A, NEG_INF);

    // dp[i] = maximum score achievable starting from index i
    vector<long long> dp(n, 0LL);

    // iterate j from n-1 down to 0
    for(int j = n - 1; j >= 0; --j)
    {
        int src = s[j] - 'a';
        long long bestVal = 0;   // if no valid jump, dp[j] stays 0 (no jump)
        bool any = false;

        // consider all possible destination characters c2:
        for(int c2 = 0; c2 < A; ++c2)
        {
            // a jump from src to c2 is allowed if either it's declared or same char jump (src==c2)
            if( (src >=0 && src < A && c2 >=0 && c2 < A) && (allowed[src][c2] || src == c2) )
            {
                if(best[c2] == NEG_INF) continue; // no k>j with char c2 processed yet
                long long key_j = prefTotal[j] - prefChar[c2][j];
                long long cand = best[c2] - key_j;   // candidate dp[j]
                if(!any || cand > bestVal)
                {
                    bestVal = cand;
                    any = true;
                }
            }
        }

        if(any)
            dp[j] = max(0LL, bestVal);   // score can't be negative; choose 0 if no positive gain
        else
            dp[j] = 0LL;

        // update best for destination char = s[j]
        int dest = src;
        long long valueForBest = (prefTotal[j] - prefChar[dest][j]) + dp[j];  // = prefTotal[k] - prefChar[dest][k] + dp[k] for k=j
        if(best[dest] == NEG_INF || valueForBest > best[dest])
            best[dest] = valueForBest;
    }

    // final answer: dp[0]
    cout << dp[0] << "\n";
}

int main()
{
    // Run optimal as the implemented solution.  You can adapt input format as needed.
    optimal();
    return 0;
}
