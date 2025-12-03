#include <bits/stdc++.h>
using namespace std;

void better() {
    int n, k;
    cin >> n;  // Array ka size input lo
    vector<int> weights(n);
    for(int i = 0; i < n; i++) cin >> weights[i];  // Weights array input lo
    cin >> k;  // k ka input lo

    vector<int> pairSum(n - 1, 0);
    for(int i = 0; i < n - 1; i++) {
        pairSum[i] = weights[i] + weights[i + 1]; // Adjacent pair sum calculate karo
    }
    
    sort(begin(pairSum), end(pairSum)); // Pair sum ko sort karo
    long maxSum = 0, minSum = 0;
    
    for(int i = 0; i < k - 1; i++) {
        minSum += pairSum[i]; // Sabse chhoti k-1 pair sums ka sum
        maxSum += pairSum[n - i - 2]; // Sabse badi k-1 pair sums ka sum
    }
    
    cout << maxSum - minSum << endl; // Difference print karo
}

int main() {
    better();
    return 0;
}
