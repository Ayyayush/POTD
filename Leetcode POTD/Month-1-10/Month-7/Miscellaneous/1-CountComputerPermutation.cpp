#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

void brute() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    // ✅ Step 1: Check if all elements after the first one are greater than nums[0]
    for (int i = 1; i < n; i++) {
        if (nums[i] <= nums[0]) {
            cout << 0 << endl;           // Agar koi bhi element nums[0] se chhota ya barabar mila, return 0
            return;
        }
    }

    // ✅ Step 2: Calculate factorial of (n - 1)
    int ans = 1;
    for (int i = 1; i < n; i++) {
        ans = (ans * i) % MOD;          // Factorial modulo mein nikal rahe hain
    }

    cout << ans << endl;                // Final answer print kar diya
}
 
int main() {
    brute();
    return 0;
}
