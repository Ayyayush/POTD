#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int n;
    cin >> n;

    vector<vector<int>> nums1(n, vector<int>(2)); // 2D vector to store key-value pairs
    vector<vector<int>> nums2(n, vector<int>(2)); // 2D vector to store key-value pairs
    vector<vector<int>> nums3;                    // Empty vector to store final key-value pairs
    map<int, int> mp;                             // Map to store the sum of values for each key

    // Input for nums1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> nums1[i][j]; // Taking input for each key-value pair
        }
    }

    // Input for nums2
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> nums2[i][j]; // Taking input for each key-value pair
        }
    }

    // Storing sums from nums1 into the map
    for (int i = 0; i < n; i++)
    {
        mp[nums1[i][0]] += nums1[i][1]; // Summing up values for the same keys
    }

    // Storing sums from nums2 into the map
    for (int i = 0; i < n; i++)
    {
        mp[nums2[i][0]] += nums2[i][1]; // Adding nums2 values to existing keys
    }

    // Storing the final key-value pairs in nums3
    for (auto it : mp)
    {
        nums3.push_back({it.first, it.second}); // Adding key-value pairs to nums3
    }

    // Output the final key-value pairs
    for (int i = 0; i < nums3.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << nums3[i][j] << " "; // Printing key-value pairs
        }
        cout << endl;
    }
}

/*
    Time Complexity Analysis:
    - Taking input for nums1: O(n)
    - Taking input for nums2: O(n)
    - Storing elements in the map (insertion/update): O(n log n) (map operations take log n)
    - Storing elements in nums3: O(n)
    - Printing output: O(n)
    - Total: **O(n log n)** (due to map operations)

    Space Complexity Analysis:
    - nums1: O(n)
    - nums2: O(n)
    - nums3: O(n)
    - map storage: O(n)
    - Total: **O(n)**
*/

void better()
{
    int n;
    cin >> n;

    vector<pair<int, int>> nums1(n), nums2(n); // 2D vector ki jagah pair use kiya
    map<int, int> mp;                          // Map to store sum of values for each key

    // Input nums1
    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i].first >> nums1[i].second; // Pehla element key, doosra value hoga
    }

    // Input nums2
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i].first >> nums2[i].second;
    }

    // Map me nums1 ke values add karna
    for (int i = 0; i < n; i++)
    {
        mp[nums1[i].first] += nums1[i].second; // Key ke corresponding value add ho rahi hai
    }

    // Map me nums2 ke values bhi add karna
    for (int i = 0; i < n; i++)
    {
        mp[nums2[i].first] += nums2[i].second;
    }

    vector<pair<int, int>> nums3; // Empty vector to store final pairs

    // Map ke elements ko nums3 me daalna
    for (auto it : mp)
    {
        nums3.push_back({it.first, it.second}); // Key aur value dono copy karna
    }

    // Output nums3 (sorted by key automatically)
    for (int i = 0; i < nums3.size(); i++)
    {
        cout << nums3[i].first << " " << nums3[i].second << endl;
    }

    //   t.c === O(NLOGN)
}

int main()
{
    brute();
    return 0;
}
