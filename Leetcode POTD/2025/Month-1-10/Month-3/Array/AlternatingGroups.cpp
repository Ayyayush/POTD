#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int n, k;
    cin >> n >> k; // Input le rahe hain
    vector<int> colors(n);
    for (int i = 0; i < n; i++)
        cin >> colors[i]; // Colors array input le rahe hain

    for (int i = 0; i < k - 1; i++)
    {
        colors.push_back(colors[i]); // Circular array banane ke liye k-1 elements append kar rahe hain
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        bool isAlternating = true;
        for (int j = i; j < i + k - 1; j++)
        {
            if (colors[j] == colors[j + 1])
            {
                isAlternating = false;
                break;
            }
        }
        if (isAlternating)
        {
            result++;
        }
    }

    cout << result << endl; // Result print kar rahe hain
}

// T.C : O(n*k)  (Har ek index se k length ka subsequence check kar rahe hain)
// S.C : O(1)    (Ek extra vector create ho raha hai jo ideally O(k-1) space le raha hai)

void better()
{
    int n, k;
    cin >> n >> k;
    vector<int> colors(n);
    for (int i = 0; i < n; i++)
        cin >> colors[i];

    int N = n + (k - 1);
    for (int i = 0; i < k - 1; i++)
    {
        colors.push_back(colors[i]); // Circular array handle karne ke liye
    }

    int result = 0;
    int i = 0, j = 1; // Sliding window ke liye pointers
    while (j < N)
    {
        if (colors[j] == colors[j - 1])
        {
            i = j;
            j++;
            continue;
        }
        if (j - i + 1 == k)
        {
            result++;
            i++;
        }
        j++;
    }

    cout << result << endl;
}

// T.C : O(n + k)  (Sliding window se efficient traverse kar rahe hain)
// S.C : O(1)      (Bas extra k-1 elements store ho rahe hain, jo negligible hain)

void optimal()
{
    int n, k;
    cin >> n >> k;
    vector<int> colors(n);
    for (int i = 0; i < n; i++)
        cin >> colors[i];

    int result = 0;
    int length = 1, last = colors[0];

    // 1st pass
    for (int i = 1; i < n; i++)
    {
        if (colors[i] == last)
        {
            length = 1;
            last = colors[i];
            continue;
        }
        length++;
        if (length >= k)
            result++;
        last = colors[i];
    }

    // 2nd pass (starting ke k-1 elements check karne ke liye)
    for (int i = 0; i < k - 1; i++)
    {
        if (colors[i] == last)
        {
            length = 1;
            last = colors[i];
            break;
        }
        length++;
        if (length >= k)
            result++;
        last = colors[i];
    }

    cout << result << endl;
}

// T.C : O(n + k)  (2 pass me traverse kar rahe hain, jo efficient hai)
// S.C : O(1)      (Koi extra array store nahi ho raha)

int main()
{
    brute();
    // better();
    // optimal();
    return 0;
}
