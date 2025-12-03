#include <bits/stdc++.h>
using namespace std;
void brute()            // O(N^2)
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dep(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> dep[i];
    }
  

    int maxplatforms = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int currstart = arr[i];
        int currend = dep[i];
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] >= currstart && arr[j] <= currend)
            {
                count++;
            }
        }
        maxplatforms = max(count, maxplatforms);
    }

    cout << maxplatforms << endl;
}
int main()
{
    brute();
    return 0;
}