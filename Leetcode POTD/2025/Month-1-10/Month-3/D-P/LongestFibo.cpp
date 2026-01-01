#include <bits/stdc++.h>
using namespace std;

void brute() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<int, int> mp;
    vector<vector<int>> t(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) mp[arr[i]] = i; // Mapping value to index for quick lookup

    int max_length = 0;
    for (int j = 1; j < n; j++) {  // Iterate for second element in subsequence
        for (int k = j + 1; k < n; k++) { // Iterate for third element in subsequence
            int length = solve(j, k, arr, mp, t); // Find length of Fibonacci sequence ending at (j, k)
            if (length >= 3) max_length = max(max_length, length); // Update max_length if valid sequence found
        }
    }
    cout << (max_length >= 3 ? max_length : 0) << endl; // If no valid sequence found, return 0
}

int solve(int j, int k, const vector<int>& arr, const unordered_map<int, int>& mp, vector<vector<int>>& t) {
    if (t[j][k] != -1) return t[j][k]; // Memoization: If already computed, return stored result

    int target = arr[k] - arr[j]; // Find previous Fibonacci-like number
    if (mp.count(target) && mp.at(target) < j) { // Check if it exists before index j
        int i = mp.at(target);
        t[j][k] = solve(i, j, arr, mp, t) + 1; // Recursive call to build sequence
        return t[j][k];
    }

    return t[j][k] = 2; // Default case: Minimum length for Fibonacci sequence is 2
}

void better() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<int, int> mp;
    vector<vector<int>> t(n, vector<int>(n, 2)); // Initialize DP table with base case (length 2)

    for (int i = 0; i < n; i++) mp[arr[i]] = i; // Store indices of elements

    int max_length = 0;
    for (int j = 1; j < n; j++) { // Iterate for second element in subsequence
        for (int k = j + 1; k < n; k++) { // Iterate for third element in subsequence
            int target = arr[k] - arr[j]; // Find previous number in Fibonacci-like sequence
            if (mp.count(target) && mp[target] < j) { // If exists in array before index j
                int i = mp[target];
                t[j][k] = t[i][j] + 1; // Update sequence length
            }
            max_length = max(max_length, t[j][k]); // Track maximum sequence length
        }
    }
    cout << (max_length >= 3 ? max_length : 0) << endl; // If no valid sequence found, return 0
}

void optimal() {
    // No optimal approach exists better than O(n^2)
}

int main() {
    return 0;
}
