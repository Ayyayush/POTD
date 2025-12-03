#include <bits/stdc++.h>
using namespace std;
void brute()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (is_sorted(arr.begin(), arr.end()))
    {
        cout << arr[arr.size() - 1];
        return;
    }
    else if (is_sorted(arr.rbegin(), arr.rend()))
    {
        cout << arr[0];
        return;
    }
    else
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (i + 1 < arr.size() && i - 1 >= 0 && (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]))
            {
                cout << arr[i] << endl;
            }
        }
    }
}
int main()
{
    brute();
    return 0;
}