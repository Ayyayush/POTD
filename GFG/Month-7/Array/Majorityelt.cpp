#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Brute Force Approach
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i]) count++;
        }

        if (count > n / 3)
        {
            // Check if already added
            bool alreadyAdded = false;
            for (int k = 0; k < ans.size(); k++)
            {
                if (ans[k] == arr[i])
                {
                    alreadyAdded = true;
                    break;
                }
            }
            if (!alreadyAdded) ans.push_back(arr[i]);
        }
    }

    for (auto x : ans) cout << x << " ";
    cout << endl;
}

void better()
{
    // Better Approach using HashMap
    // Time Complexity: O(n)
    // Space Complexity: O(n)

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<int, int> mp;
    vector<int> vec;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (auto it : mp)
    {
        if (it.second > n / 3)
            vec.push_back(it.first);
    }

    for (auto x : vec) cout << x << " ";
    cout << endl;
}

int main()
{
    brute();       // Test brute here
    better();      // Test better here
    return 0;
}
