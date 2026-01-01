#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // T.C : O(Q * m * n)  - Har query ke liye pura grid traverse kar rahe hain BFS se
    // S.C : O(m * n)      - Visited array aur queue ke liye extra space use ho raha hai

    int m, n, Q;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    cin >> Q;
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)
        cin >> queries[i];

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    auto bfs = [&](int val)
    {
        queue<pair<int, int>> que;
        que.push({0, 0});

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;

        int points = 0;
        while (!que.empty())
        {
            int N = que.size();
            while (N--)
            {
                auto [i, j] = que.front();
                que.pop();

                if (grid[i][j] > val)
                    continue;

                points++;

                for (auto &dir : directions)
                {
                    int i_ = i + dir[0], j_ = j + dir[1];

                    if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_] && grid[i_][j_] < val)
                    {
                        que.push({i_, j_});
                        visited[i_][j_] = true;
                    }
                }
            }
        }
        return points;
    };

    vector<int> result(Q, 0);
    for (int i = 0; i < Q; i++)
    {
        result[i] = bfs(queries[i]);
    }

    for (int res : result)
        cout << res << " ";
    cout << endl;
}

void better()
{
    // T.C : O(Q * m * n)  - Har query ke liye pura grid traverse kar rahe hain DFS se
    // S.C : O(m * n)      - Visited array aur recursion stack ke liye extra space use ho raha hai

    int m, n, Q;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    cin >> Q;
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)
        cin >> queries[i];

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    function<int(int, int, int, vector<vector<bool>> &)> dfs = [&](int i, int j, int val, vector<vector<bool>> &visited)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] >= val)
            return 0;

        visited[i][j] = true;
        int points = 1;

        for (auto &dir : directions)
        {
            int i_ = i + dir[0], j_ = j + dir[1];
            points += dfs(i_, j_, val, visited);
        }

        return points;
    };

    vector<int> result(Q, 0);
    for (int i = 0; i < Q; i++)
    {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        result[i] = dfs(0, 0, queries[i], visited);
    }

    for (int res : result)
        cout << res << " ";
    cout << endl;
}

void optimal()
{
    // T.C : O(QlogQ + m*nlog(m*n))  - Sorting queries O(QlogQ) + Min-heap operations O(m*n log(m*n))
    // S.C : O(m * n)                - Visited array aur priority queue ke liye extra space use ho raha hai

    int m, n, Q;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    cin >> Q;
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)
        cin >> queries[i];

    vector<pair<int, int>> sortedQ;
    for (int i = 0; i < Q; i++)
        sortedQ.push_back({queries[i], i});
    sort(sortedQ.begin(), sortedQ.end());

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int points = 0;
    pq.push({grid[0][0], 0, 0});
    visited[0][0] = true;

    vector<int> result(Q, 0);
    for (int i = 0; i < Q; i++)
    {
        int queryValue = sortedQ[i].first, idx = sortedQ[i].second;
        while (!pq.empty() && pq.top()[0] < queryValue)
        {
            int i = pq.top()[1], j = pq.top()[2];
            pq.pop();
            points++;

            for (auto &dir : directions)
            {
                int i_ = i + dir[0], j_ = j + dir[1];
                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_])
                {
                    pq.push({grid[i_][j_], i_, j_});
                    visited[i_][j_] = true;
                }
            }
        }
        result[idx] = points;
    }

    for (int res : result)
        cout << res << " ";
    cout << endl;
}

int main()
{
    return 0;
}
