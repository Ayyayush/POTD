#include <bits/stdc++.h>
using namespace std;

void brute()
{
    vector<int> arr = {2, 4, 8, 10, 12, 14}; // Example input

    int diff = abs(arr[0] - arr[1]);
    for (int i = 0; i < arr.size(); i++)
    {
        if (abs(arr[i] - arr[i + 1]) != diff)
        {
            cout << (arr[i + 1] + arr[i]) / 2 << endl;
            return;
        }
    }

    cout << -1 << endl;
}

void better()
{
    vector<int> arr = {1, 6, 11, 16, 21, 31}; // Example input
    int n = arr.size();

    int d1 = arr[1] - arr[0];
    int d2 = arr[n - 1] - arr[n - 2];
    int d3 = (arr[n - 1] - arr[0]) / n;

    int d = (d1 == d2 || d1 == d3) ? d1 : d2;
    if (d == 0)
    {
        cout << arr[0] << endl;
        return;
    }

    int lo = 0, hi = n - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        if ((arr[mid] - arr[0]) / d == mid)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    cout << arr[0] + lo * d << endl;
}

int main()
{
    brute();
    return 0;
}
