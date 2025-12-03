#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int m;
    cin >> m;
    vector<vector<int>> queries(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int l = queries[i][0];
        int r = queries[i][1];
        for (int j = l; j <= r; j++)
        {
            if (nums[j] > 0)
                nums[j] -= 1;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            cout << "False" << endl;
            return;
        }
    }
    cout << "True" << endl;
}

void better()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int m;
    cin >> m;
    vector<vector<int>> queries(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<int> diff(n + 1, 0);         // n+1 size ki difference array

    for (int i = 0; i < m; i++)
    {
        int l = queries[i][0];
        int r = queries[i][1];
        diff[l] += 1;
        if (r + 1 < n)
        {
            diff[r + 1] -= 1;
        }
    }

    vector<int> result(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += diff[i];
        result[i] = sum;
    }

    for (int i = 0; i < n; i++)
    {
        if (result[i] < nums[i])
        {
            cout << "False" << endl;
            return;
        }
    }

    cout << "True" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    better();       // ✅ ab ye call karega better version ko

    return 0;
}
