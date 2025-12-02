#include <bits/stdc++.h>
using namespace std;

/*
Brute force approach:
Time Complexity: O(n^2) - Do nested loops array ke pairs check karne ke liye
Space Complexity: O(1) - Extra space sirf 1 vector (max size 2), output ke liye
*/
void brute() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> vec;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                vec.push_back(min(i + 1, j + 1));
                vec.push_back(max(i + 1, j + 1));
                break;
            }
        }
        if (!vec.empty()) break;
    }

    if (vec.empty()) {
        cout << -1 << " " << -1 << endl;
    }
    else {
        cout << vec[0] << " " << vec[1] << endl;
    }
}




/*
better approach using Hash Map:
Time Complexity: O(n)       // Har element bas ek baar process hota hai
Space Complexity: O(n)      // Map mein sab elements store ho sakte hain
*/
void better() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<int, int> mp;  // value -> index (0-based)

    vector<int> vec;

    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        if (mp.find(complement) != mp.end()) {
            // Complement mila, answer found
            vec.push_back(min(i + 1, mp[complement] + 1));  // 1-based indexing
            vec.push_back(max(i + 1, mp[complement] + 1));
            break;
        }
        mp[arr[i]] = i;  // current value ka index store karo
    }

    if (vec.empty()) {
        cout << -1 << " " << -1 << endl;
    }
    else {
        cout << vec[0] << " " << vec[1] << endl;
    }
}

/*
optimal approach (Two Pointer):
Time Complexity: O(n) - Single pass with two pointers
Space Complexity: O(1) - Extra space sirf 1 vector (max size 2), output ke liye

Note: Array should be sorted for two-pointer approach to work correctly
*/
void better() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> vec;
    int i = 0, j = n - 1;

    while (i < j) {
        if (arr[i] + arr[j] == target) {
            vec.push_back(min(i + 1, j + 1));
            vec.push_back(max(i + 1, j + 1));
            break;
        }
        else if (arr[i] + arr[j] < target) {
            i++;
        }
        else {
            j--;
        }
    }

    if (vec.empty()) {
        cout << -1 << " " << -1 << endl;
    }
    else {
        cout << vec[0] << " " << vec[1] << endl;
    }
}

int main() {
    // Uncomment jis function ko run karna ho:

    // brute();
    // better();

    return 0;
}
