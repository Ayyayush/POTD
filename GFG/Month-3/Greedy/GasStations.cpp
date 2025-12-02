#include <bits/stdc++.h>
using namespace std;

void brute() {
    int n;
    cin >> n;
    
    vector<int> gas(n), cost(n);
    for (int i = 0; i < n; i++) cin >> gas[i];
    for (int i = 0; i < n; i++) cin >> cost[i];

    long long tcost = 0, tgas = 0;
    for (int i = 0; i < n; i++) {
        tgas += gas[i]; // Total gas calculate kar rahe hain
        tcost += cost[i]; // Total cost calculate kar rahe hain
    }
    
    if (tgas < tcost) {
        cout << -1 << endl; // Agar total gas kam hai toh poora travel nahi ho sakta
        return;
    }

    long long currgas = 0, start = 0;
    for (int i = 0; i < n; i++) {
        currgas += gas[i] - cost[i]; // Current gas calculate kar rahe hain
        if (currgas < 0) { 
            currgas = 0; // Gas khatam ho gayi toh naya start lena padega
            start = i + 1; // Naya starting station set kar rahe hain
        }
    }
    
    cout << start << endl; // Final starting point print karna
}

int main() {
    brute();
    return 0;
}
