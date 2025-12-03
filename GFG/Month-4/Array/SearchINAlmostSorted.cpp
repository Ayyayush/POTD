#include <bits/stdc++.h>
using namespace std;

void brute()
{
    vector<int> arr = {1, 3, 5, 7, 9}; // example input
    int target = 7;                    // example target

    for (int i = 0; i < arr.size(); i++) // har element ko check karenge
    {
        if (arr[i] == target) // agar target mil gaya
        {
            cout << i << endl; // toh index print karo
            return;
        }
    }

    cout << -1 << endl; // agar nahi mila toh -1 print karo
}


void better()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) // har element ko check karenge
    {
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());
    int target;
    cin >> target;
    int l = 0, r = arr.size() - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
        {
            cout << "Found " << endl;
            return;
        }
        else if (arr[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }


    cout<<"-1"<<endl;
}

int main()
{
    better();
    return 0;
}
