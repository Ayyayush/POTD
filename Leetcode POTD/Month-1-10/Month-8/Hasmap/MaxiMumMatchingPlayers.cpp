#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // 🔴 Brute Force Approach using map
    // T.C. = O(n * m * log m)   → n = players.size(), m = trainers.size()
    //        inner loop iterates over sorted map (log m erase)
    // S.C. = O(m)               → storing trainer counts in map

    int n, m;
    cin >> n >> m;

    vector<int> players(n);
    vector<int> trainers(m);

    for (int i = 0; i < n; i++) cin >> players[i];
    for (int i = 0; i < m; i++) cin >> trainers[i];

    map<int, int> mp;   // map keeps trainer strengths in sorted order

    for (int i = 0; i < m; i++) {
        mp[trainers[i]]++;     // count of each trainer strength
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (auto it : mp) {
            if (it.first >= players[i]) {
                count++;                   // found a valid trainer
                mp[it.first]--;           // use one trainer
                if (mp[it.first] == 0) {
                    mp.erase(it.first);   // erase if count reaches 0
                }
                break;                    // move to next player
            }
        }

        if (mp.size() == 0) break;        // no trainers left
    }

    cout << count << endl;   // output total matched pairs
}


void better()
{
    // 🟡 Two Pointer Approach
    // T.C. = O(n log n + m log m)
    // S.C. = O(1)

    int n, m;
    cin >> n >> m;

    vector<int> p(n), t(m);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < m; i++) cin >> t[i];

    sort(p.begin(), p.end());
    sort(t.begin(), t.end());

    int k = 0, count = 0;

    for (int i = 0; i < p.size(); i++)
    {
        while (k < t.size() && t[k] < p[i])
        {
            k++;
        }

        if (k >= t.size())
            break;

        if (t[k] >= p[i])
        {
            count++;
            k++;
        }
    }

    cout << count << endl;
}


int main()
{
    brute();    // Call brute force
    return 0;
}
