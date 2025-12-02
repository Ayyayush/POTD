#include <bits/stdc++.h>
using namespace std;



//////////////////////////////////////////////////////////////////////////////////////////////////
// ✅ Approach: Brute Force
// ➤ Har element `a[i]` ke liye `b[]` ke har element ko check karte hain
// ➤ Count karte hain kitne elements `b[j]` less than or equal to `a[i]` hain
//
// ⏱️ Time Complexity: O(n * m) → where n = size of a[], m = size of b[]
// 🧠 Space Complexity: O(n) → output array ka size
//////////////////////////////////////////////////////////////////////////////////////////////////

void brute()
{
    int n, m;
    cin >> n >> m;                                        // Size of a[] and b[]

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];               // Input array a[]
    for(int i = 0; i < m; i++) cin >> b[i];               // Input array b[]

    vector<int> res;

    for(int i = 0; i < n; i++)
    {
        int count = 0;
        for(int j = 0; j < m; j++)
        {
            if(b[j] <= a[i])                              // Agar b[j] <= a[i] hai toh count++
                count++;
        }
        res.push_back(count);                             // Final count store karo
    }

    for(int x : res) cout << x << " ";                    // Output result
    cout << endl;
}



//////////////////////////////////////////////////////////////////////////////////////////////////
// ✅ Approach: Binary Search after Sorting (Better than Brute Force)
// ➤ Pehle array `b[]` ko sort kar lete hain
// ➤ Har element `a[i]` ke liye, `b[]` mein binary search se find karte hain ki
//    kitne elements `<= a[i]` hain
//
// ⏱️ Time Complexity: O(n * log m) → where n = a.size(), m = b.size()
// 🧠 Space Complexity: O(1) → Except result vector
//////////////////////////////////////////////////////////////////////////////////////////////////

void better()
{
    int n, m;
    cin >> n >> m;                            // Input size of array a and b

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];   // Input array a[]
    for(int i = 0; i < m; i++) cin >> b[i];   // Input array b[]

    sort(b.begin(), b.end());                // Sort b[] for binary search

    vector<int> res;

    for (int i = 0; i < n; i++) {
        int l = 0, r = m - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (b[mid] <= a[i]) {
                ans = mid;                    // Found valid element
                l = mid + 1;                  // Try to find a bigger valid one
            } else {
                r = mid - 1;
            }
        }

        res.push_back(ans + 1);               // Final count is (index + 1)
    }

    for (int x : res) cout << x << " ";       // Output result
    cout << endl;
}




//////////////////////////////////////////////////////////////////////////////////////////////////
// ✅ Approach: Using STL upper_bound() → Optimized Binary Search
// ➤ `upper_bound(b.begin(), b.end(), a[i])` returns iterator to first element > a[i]
// ➤ So distance from begin gives count of elements ≤ a[i]
//
// ⏱️ Time Complexity: O(n * log m) → for each a[i], binary search in b[]
// 🧠 Space Complexity: O(1) → Result array excluded
//////////////////////////////////////////////////////////////////////////////////////////////////

void optimal()
{
    int n, m;
    cin >> n >> m;                              // Input size of a[] and b[]

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];     // Input array a[]
    for(int i = 0; i < m; i++) cin >> b[i];     // Input array b[]

    sort(b.begin(), b.end());                   // Sort b[] for upper_bound

    vector<int> res;

    for(int i = 0; i < n; i++) {
        int count = upper_bound(b.begin(), b.end(), a[i]) - b.begin();  // Count of ≤ a[i]
        res.push_back(count);
    }

    for(int x : res) cout << x << " ";          // Output result
    cout << endl;
}





int main()
{
    better();
    return 0;
}
