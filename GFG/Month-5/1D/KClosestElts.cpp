#include <bits/stdc++.h>
using namespace std;

void better()
{
    // Time Complexity: O(N log N)                 // Sorting ke liye O(N log N) + O(K) for pushing into res
    // Space Complexity: O(K)                      // K elements hi store kar rahe hain

    vector<int> arr = {10, 15, 7, 3, 4};           // Sample input array
    int k = 3;                                     // K closest elements chahiye
    int x = 8;                                     // Reference element

    vector<int> res;                               // Result vector
    int index = -1;                                // x ya usse bada element ka index

    sort(arr.begin(), arr.end());                 // Array ko sort kar diya

    // x ya usse bada pehla element dhoondho
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x) {
            index = i;
            break;
        } else if (arr[i] > x) {
            index = i;
            break;
        }
    }

    // Agar x sabse bada element hai
    if (index == -1) index = arr.size();

    // Left side ke elements uthao
    for (int i = index - 1; i >= max(index - k, 0); i--) {
        res.push_back(arr[i]);
    }

    // Agar k elements ho gaye to return
    if (res.size() == k) {
        for (auto it : res) cout << it << " ";
        cout << endl;
        return;
    }

    // Nahi hue to right side se uthao
    for (int i = index; i < arr.size(); i++) {
        res.push_back(arr[i]);
        if (res.size() == k)
            break;
    }

    // Output print karo
    for (auto it : res) cout << it << " ";
    cout << endl;
}

int main()
{
    better();
    return 0;
}
