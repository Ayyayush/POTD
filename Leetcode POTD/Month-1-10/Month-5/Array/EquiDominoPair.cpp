#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(n^2)         // har pair ka comparison ho raha hai
    // Space Complexity: O(n)          // dominoes vector le rahe hai input ke liye

    int n, count = 0;
    cin >> n;
    vector<vector<int>> dominoes(n, vector<int>(2)); // 2D vector to store all domino pairs

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> dominoes[i][j]; // har domino ka 2 part input
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) // next dominoes se compare karna
        {
            if ((dominoes[j][0] == dominoes[i][0] && dominoes[j][1] == dominoes[i][1]) ||
                (dominoes[j][1] == dominoes[i][0] && dominoes[j][0] == dominoes[i][1]))
            {
                cout << dominoes[i][0] << " " << dominoes[i][1] << endl; // duplicate pair print
                count++;
            }
        }
    }

    cout << count << endl; // total duplicate pairs
}

void good()
{
    // using map<string,int>mp;
}

void better()
{
    // Time Complexity: O(n) + O(k)        // pehle loop O(n) for counting, dusra O(k) for combinations (k = unique pairs <= n)
    // Space Complexity: O(n)             // map me n dominoes ja rahe hain

    int n, count = 0;
    cin >> n;
    vector<vector<int>> dominoes(n, vector<int>(2)); // input ke liye dominoes vector

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> dominoes[i][j];
        }
    }

    map<pair<int, int>, int> mp; // map to count pairs (sorted so that [a,b] and [b,a] are treated same)

    for (int i = 0; i < n; i++)
    {
        int a = dominoes[i][0];
        int b = dominoes[i][1];
        if (a > b)
            swap(a, b); // smaller value pehle rakho for uniformity
        mp[{a, b}]++;   // us pair ka count badhao
    }

    for (auto it : mp)
    {
        int freq = it.second;
        if (freq > 1)
        {
            // calculating combination of 2 pairs
            // valC2 == (val*val-1) /2
            count += (freq * (freq - 1)) / 2; // combination of 2 from freq -> nC2
        }
    }

    cout << count << endl; // total duplicate unordered pairs
}

void optimal()
{
    // using  constant size vector == S.C==O(1)
    //     1<=dominoes[i][j]<=9
    // max value on 10*i+j ==99
    // so vector size ==99

    // Time Complexity: O(n)            // ek hi loop me saara kaam ho raha hai
    // Space Complexity: O(1)           // constant space vector of size 100

    int n, count = 0;
    cin >> n;
    vector<vector<int>> dominoes(n, vector<int>(2)); // input ke liye dominoes vector
    vector<int> value(100);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> dominoes[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int a = dominoes[i][0];
        int b = dominoes[i][1];
        if (a > b)
            swap(a, b);

        int val = a * 10 + b; // Use swapped values here
        count += value[val];
        value[val]++;
    }

    cout << count << endl;
}

int main()
{
    // brute();
    // better(); // aap chaaho toh better function ko bhi test kar sakte ho
    optimal();
    return 0;
}
