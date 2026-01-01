#include <bits/stdc++.h>
using namespace std;

// Approach: Brute Force - Check every possible peak
// T.C. = O(n^2)      S.C. = O(1)
void brute() {
    vector<int> arr = {2, 1, 4, 7, 3, 2, 5};     // example input
    int n = arr.size();
    int ans = 0;

    for (int i = 1; i < n - 1; i++) {
        // Check if current is a peak
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            int right = i + 1;

            // Expand to the left
            while (left > 0 && arr[left - 1] < arr[left]) left--;

            // Expand to the right
            while (right < n - 1 && arr[right] > arr[right + 1]) right++;

            int len = right - left + 1;
            ans = max(ans, len);
        }
    }

    cout << ans << endl;     // Output: 5
}

// Approach: Prefix & Suffix Arrays (2-pass approach)
// T.C. = O(n)        S.C. = O(n)
void better() {
    vector<int> arr = {2, 1, 4, 7, 3, 2, 5};      // example input
    int n = arr.size();

    vector<int> up(n, 0);     // increasing streak
    vector<int> down(n, 0);   // decreasing streak

    // Fill up[] → strictly increasing from left
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1])
            up[i] = up[i - 1] + 1;
    }

    // Fill down[] → strictly decreasing from right
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1])
            down[i] = down[i + 1] + 1;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (up[i] > 0 && down[i] > 0) {
            int len = up[i] + down[i] + 1;
            ans = max(ans, len);
        }
    }

    cout << ans << endl;     // Output: 5
}

// Approach: Expand around peaks
// T.C. = O(n)       S.C. = O(1)
void optimal() {
    vector<int> arr = {2, 1, 4, 7, 3, 2, 5};     // example input
    int n = arr.size();
    int ans = 0;

    for (int i = 1; i < n - 1; i++) {
        // Check if it's a peak
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            int right = i + 1;

            // Expand left
            while (left > 0 && arr[left - 1] < arr[left])
                left--;

            // Expand right
            while (right < n - 1 && arr[right] > arr[right + 1])
                right++;

            ans = max(ans, right - left + 1);
            i = right; // jump ahead to avoid re-checking inside mountain
        }
    }

    cout << ans << endl;     // Output: 5
}

int main() {
    brute();     // O(n^2)
    better();    // O(n)
    optimal();   // O(n)
    return 0;
}
