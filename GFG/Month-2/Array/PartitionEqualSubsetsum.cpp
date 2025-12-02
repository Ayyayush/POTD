#include <bits/stdc++.h>
using namespace std;

void brute() {
    vector<int> arr = {1, 5, 11, 5}; // Input yahin se le rahe hain
    int n = arr.size();

    int totalSum = accumulate(arr.begin(), arr.end(), 0); // Poore array ka sum nikala

    if (totalSum % 2 != 0) { // Agar sum odd hai, toh equal partition possible nahi hai
        cout << "false\n";
        return;
    }

    int target = totalSum / 2; // Humein koi aisa subset dhoondhna hai jiska sum target ho

    int subsets = 1 << n; // Total 2^n subsets honge
    for (int mask = 0; mask < subsets; mask++) {
        int subsetSum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) { // Yeh check kar raha hai ki ith element subset me hai ya nahi
                subsetSum += arr[i];
            }
        }
        if (subsetSum == target) { // Agar subset ka sum target ke barabar aa gaya
            cout << "true\n";
            return;
        }
    }
    cout << "false\n";
}
int main() {
    brute();
    return 0;
}
