#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(n)         // ek loop me poora array check kar rahe hain
    // Space Complexity: O(1)        // koi extra space use nahi ho raha

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // input array
    }

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0) // agar current element odd hai
        {
            // check karo next 2 elements bhi odd hain kya
            if (i + 1 < n && i + 2 < n && arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0)
            {
                found = true;
                break;
            }
        }
    }

    if (found)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

int main()
{
    brute();
    return 0;
}
