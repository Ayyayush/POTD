#include <bits/stdc++.h>
using namespace std;

/*
Brute force approach
APPROACH: Brute-force (Enumerate all subarrays and compute XOR)
TIME COMPLEXITY: O(n^2)  -> there are O(n^2) subarrays; computing running xor per subarray can be O(1) if accumulated, overall O(n^2)
SPACE COMPLEXITY: O(1)
*/
int brute(vector<int>& arr) {
    int n = arr.size();
    int result = 0; // will hold XOR of XORs of all subarrays
    for (int i = 0; i < n; ++i) {
        int curXor = 0;
        for (int j = i; j < n; ++j) {
            curXor ^= arr[j]; // accumulate XOR of subarray arr[i..j]
            result ^= curXor; // include this subarray's value into final result
        }
    }
    return result;
}

/*
Better approach (prefix xor used) - still O(n^2) but clearer
APPROACH: Prefix XOR and enumerate subarray endpoints
TIME COMPLEXITY: O(n^2)
SPACE COMPLEXITY: O(n) for prefix array
*/
int better(vector<int>& arr) {
    int n = arr.size();
    vector<int> pref(n+1, 0);
    for (int i = 0; i < n; ++i) pref[i+1] = pref[i] ^ arr[i]; // prefix xor: pref[k] = xor of arr[0..k-1]

    int result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int subXor = pref[j+1] ^ pref[i]; // xor of arr[i..j]
            result ^= subXor; // include this subarray's xor into final result
        }
    }
    return result;
}

/*
Optimal approach (used in subarrayXor)
OBSERVATION:
 - For element arr[i], number of subarrays that include arr[i] = (i+1) * (n-i).
 - If that count is odd, arr[i] contributes to final XOR (because XORing a value odd times = value, even times = 0).
 - So result = XOR of all arr[i] for which (i+1)*(n-i) is odd.
APPROACH: Count parity of occurrences per index
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
*/
int subarrayXor(vector<int>& arr) { // GfG expected function
    int n = arr.size();
    int result = 0;
    for (int i = 0; i < n; ++i) {
        long long count = 1LL * (i + 1) * (n - i); // number of subarrays including arr[i]
        // if count is odd, include arr[i] in result
        if (count & 1LL) result ^= arr[i]; // complex but simple: parity check via bitwise AND
    }
    return result;
}

/* 
Driver - read input and print output.
Input format (example):
n
a1 a2 a3 ... an

Example:
3
1 2 3

This will print the result of subarrayXor(arr).
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0; // no input

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    // You can test any implementation:
    // cout << brute(arr) << "\n";
    // cout << better(arr) << "\n";
    cout << subarrayXor(arr) << "\n"; // optimal

    return 0;
}
