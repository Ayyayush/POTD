#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(N^2)                            // Har number ke liye linear search
    // Space Complexity: O(1)                             // Koi extra space nahi

    vector<int> arr;
    int num;
    while (cin >> num) {
        arr.push_back(num);  // Input directly into array
    }

    int n = arr.size();

    for (int i = 1; i <= n + 1; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << i << endl;
            return;
        }
    }
}

void better()
{
    // Time Complexity: O(N)                              // 2 passes
    // Space Complexity: O(N)                             // Unordered map used

    vector<int> arr;
    int num;
    while (cin >> num) {
        arr.push_back(num);  // Input directly into array
    }

    unordered_map<int, int> mp;

    for (int x : arr) mp[x]++;

    int maxVal = *max_element(arr.begin(), arr.end()) + 1;

    for (int i = 1; i <= maxVal; i++) {
        if (!mp.count(i)) {
            cout << i << endl;
            return;
        }
    }

    cout << -1 << endl;
}

void optimal()
{
    // Time Complexity: O(N)                              // 1 pass for marking + 1 for finding
    // Space Complexity: O(1)                             // Constant space (modify array in-place)

    vector<int> arr;
    int num;
    while (cin >> num) {
        arr.push_back(num);  // Input directly into array
    }

    int n = arr.size();

    // Step 1: Replace negatives & zeros with large value (n+2)
    for (int i = 0; i < n; i++) {
        if (arr[i] <= 0 || arr[i] > n) arr[i] = n + 2;
    }

    // Step 2: Use index marking
    for (int i = 0; i < n; i++) {
        int val = abs(arr[i]);
        if (val >= 1 && val <= n) {
            if (arr[val - 1] > 0)
                arr[val - 1] = -arr[val - 1];
        }
    }

    // Step 3: First index with positive value is missing number
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            cout << i + 1 << endl;
            return;
        }
    }

    cout << n + 1 << endl;
}



int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        // 👇👇 Uncomment jo version run karna ho 👇👇

        // brute();
        // better();
        // optimal();
        original();    // ← Tumhara original wala code
    }

    return 0;
}
