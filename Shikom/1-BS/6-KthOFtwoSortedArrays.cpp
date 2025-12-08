#include <bits/stdc++.h>
using namespace std;

void brute() 
{
    // Time Complexity: O((n+m) log(n+m))
    // Space Complexity: O(n+m)

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> c = a;
    for (int x : b) c.push_back(x);

    sort(c.begin(), c.end());

    cout << c[k - 1];
}



void better() 
{
    // Time Complexity: O(n + m)
    // Space Complexity: O(1)

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int i = 0, j = 0, cnt = 0;

    while (i < n && j < m) 
    {
        int val;
        if (a[i] < b[j]) val = a[i++];
        else val = b[j++];
        
        cnt++;
        if (cnt == k) 
        {
            cout << val;
            return;
        }
    }

    while (i < n) 
    {
        cnt++;
        if (cnt == k) cout << a[i];
        i++;
    }

    while (j < m) 
    {
        cnt++;
        if (cnt == k) cout << b[j];
        j++;
    }
}



void optimal() 
{
    // -------------------------------------------------------------
    // Approach: Binary Search on Partitions (same as median problem)
    // Time Complexity: O(log(min(n, m)))
    // Space Complexity: O(1)
    // -------------------------------------------------------------

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    if (n > m) swap(a, b), swap(n, m);  
    // Always binary-search on smaller array

    int low = max(0, k - m);
    int high = min(k, n);

    while (low <= high) 
    {
        int cutA = (low + high) / 2;
        int cutB = k - cutA;

        int leftA  = (cutA == 0 ? INT_MIN : a[cutA - 1]);
        int leftB  = (cutB == 0 ? INT_MIN : b[cutB - 1]);
        int rightA = (cutA == n ? INT_MAX : a[cutA]);
        int rightB = (cutB == m ? INT_MAX : b[cutB]);

        // Partition correct if left parts ≤ right parts
        if (leftA <= rightB && leftB <= rightA) 
        {
            cout << max(leftA, leftB);
            return;
        }
        else if (leftA > rightB) 
        {
            high = cutA - 1;      // too many from a
        }
        else 
        {
            low = cutA + 1;       // too few from a
        }
    }
}



int main()
{
    optimal();
    return 0;
}
