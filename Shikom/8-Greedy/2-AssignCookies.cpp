#include <bits/stdc++.h>
using namespace std;

/* ===================== BRUTE FORCE ===================== */
void brute()
{
    // APPROACH: Brute Force (Nested Loops)
    // For each child, we scan all cookies to find the first valid one

    // TIME COMPLEXITY: O(N log N + M log M + N*M)
    // SPACE COMPLEXITY: O(1)

    vector<int> g = {1, 2, 3};          // greed factor of children
    vector<int> s = {1, 1};             // size of cookies

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int count = 0;

    for (int i = 0; i < g.size(); i++)
    {
        int curr = g[i];

        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] >= curr)
            {
                s[j] = 0;               // cookie consumed
                count++;
                break;
            }
        }
    }

    cout << count;
}

/* ===================== BETTER ===================== */
void better()
{
    // APPROACH: Improved Brute Force (Single Cookie Pointer)
    // We avoid restarting cookie scan for every child

    // TIME COMPLEXITY: O(N log N + M log M + N + M)
    // SPACE COMPLEXITY: O(1)

    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int count = 0;
    int j = 0;                          // cookie pointer

    for (int i = 0; i < g.size(); i++)
    {
        int curr = g[i];

        while (j < s.size())
        {
            if (s[j] >= curr)
            {
                s[j] = 0;               // cookie used
                count++;
                j++;
                break;
            }
            j++;
        }
    }

    cout << count;
}

/* ===================== OPTIMAL ===================== */
void optimal()
{
    // APPROACH: Greedy + Two Pointers
    // Assign the smallest possible cookie to the smallest greed child

    // TIME COMPLEXITY: O(N log N + M log M)
    // SPACE COMPLEXITY: O(1)

    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int l = 0;                          // child pointer
    int r = 0;                          // cookie pointer
    int count = 0;

    while (l < g.size() && r < s.size())
    {
        if (s[r] >= g[l])               // cookie satisfies child
        {
            count++;
            l++;                        // move to next child
        }
        r++;                            // always move cookie pointer
    }

    cout << count;
}

int main()
{
    brute();
    cout << "\n";
    better();
    cout << "\n";
    optimal();
    return 0;
}
