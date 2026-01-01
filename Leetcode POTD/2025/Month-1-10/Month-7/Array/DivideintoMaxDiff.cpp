#include <bits/stdc++.h>
using namespace std;

void better()
{
    // Time Complexity: O(N log N)             // kyunki sort + linear traversal
    // Space Complexity: O(N)                  // kyunki result vector ban raha hai

    int n; cin >> n;                          // array size input lo
    int k; cin >> k;                          // k input lo
    vector<int> nums(n);                      // input array
    for (int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());           // pehle array ko sort karo

    vector<vector<int>> result;               // final answer vector of vectors

    for (int i = 0; i < n; i += 3)            // har 3 elements ke liye loop
    {
        vector<int> arr;                      // ek group banane ke liye temp array

        arr.push_back(nums[i]);               // pehla element
        arr.push_back(nums[i + 1]);           // doosra element
        arr.push_back(nums[i + 2]);           // teesra element

        // check karo ki difference k se kam ya equal hai ya nahi
        if (abs(arr[0] - arr[1]) <= k && abs(arr[1] - arr[2]) <= k && abs(arr[0] - arr[2]) <= k)
        {
            result.push_back(arr);            // agar valid group hai toh result mein daalo
        }
        else
        {
            cout << "[]";                     // agar koi bhi group fail ho gaya toh empty print karo
            return;
        }
    }

    // agar sab valid groups ban gaye toh print karo
    for (auto group : result)
    {
        cout << "[ ";
        for (auto num : group) cout << num << " ";
        cout << "]";
    }
    cout << endl;
}

int main()
{
    better();
    return 0;
}
