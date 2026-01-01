#include <bits/stdc++.h>
using namespace std;

void naive()
{
    // Time Complexity: O(N)                    // kyunki har element ek ek karke check ho raha hai
    // Space Complexity: O(1)                    // extra space bilkul nahi lag raha

    int n;                                      // array ka size
    cin >> n;                                   // size input lo

    vector<int> nums(n);                        // vector bana lo

    for (int i = 0; i < n; i++)                 // array input ke liye loop
    {
        cin >> nums[i];                         // element input karo
    }

    int target;                                 // target element
    cin >> target;                              // target input karo

    int index = -1;                             // agar nahi mila toh -1

    for (int i = 0; i < n; i++)                 // har element par loop
    {
        if (nums[i] == target)                  // agar target mil gaya
        {
            index = i;                          // index store karo
            break;                              // break kar do
        }
    }

    cout << index << endl;                      // index print karo (nahi mila toh -1)
}


void intuitive()
{
    // Time Complexity: O(N)                    // kyunki find() bhi linear hi chalti hai
    // Space Complexity: O(1)                    // extra space nahi lagta

    int n;                                      // array ka size
    cin >> n;                                   // size input lo

    vector<int> nums(n);                        // vector bana lo

    for (int i = 0; i < n; i++)                 // array input ke liye loop
    {
        cin >> nums[i];                         // element input karo
    }

    int target;                                 // target element
    cin >> target;                              // target input karo

    auto it = find(nums.begin(), nums.end(), target);     // find() se target dhoondho

    if (it != nums.end())                                  // agar mila toh
    {
        cout << it - nums.begin() << endl;                 // index print karo
    }
    else
    {
        cout << -1 << endl;                                // nahi mila toh -1 print karo
    }
}


 // it is only valid when soritng is allowed 
void brute()
{
   
    // Time Complexity: O(log N)                  // kyunki lower_bound binary search karta hai
    // Space Complexity: O(1)                      // koi extra space nahi

    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int target; cin >> target;

    auto it = lower_bound(nums.begin(), nums.end(), target);   // lower_bound se binary search

    if(it != nums.end() && *it == target)                      // agar target mila toh
        cout << it - nums.begin() << endl;                     // index print karo
    else
        cout << -1 << endl;                                     // nahi mila toh -1
}


void optimal()
{
    // Time Complexity: O(log N)             // pivot finder + 2 binary search
    // Space Complexity: O(1)                // koi extra space nahi

    int n; cin >> n;                        // array ka size
    vector<int> nums(n);                    // rotated sorted array
    for (int i = 0; i < n; i++) cin >> nums[i];

    int target; cin >> target;              // target element to find

    // Pivot finder: minimum element ka index
    auto findPivot = [&](vector<int>& nums, int n) {
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        return l;                           // pivot index return karo
    };

    // Binary Search: sorted part mein target dhoondho
    auto binarySearch = [&](int l, int r, vector<int>& nums, int target) {
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;   // target mil gaya
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;                         // nahi mila toh -1
    };

    // Step 1: pivot nikalo
    int pivot_index = findPivot(nums, n);

    // Step 2: pivot ke left sorted part mein search karo
    int idx = binarySearch(0, pivot_index - 1, nums, target);

    // Step 3: agar left mein nahi mila toh right sorted part mein dhoondho
    if (idx == -1) idx = binarySearch(pivot_index, n - 1, nums, target);

    cout << idx << endl;                   // final answer print karo
}

int main()
{
    optimal();
    return 0;
}
