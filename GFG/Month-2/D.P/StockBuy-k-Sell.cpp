#include <bits/stdc++.h>
using namespace std;

void brute() {
    /* Time Complexity: O(N)  
       Space Complexity: O(1)  
       - N: Array ki size  
       - O(1): Kyunki sirf ek variable use ho raha hai  
    */

    vector<int> prices = {7,1,5,3,6,4}; // Stock prices ka input

    int profit = 0; // Maximum profit track karne ke liye

    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) { // Agar aaj ka price kal se zyada hai to profit add karo
            profit += prices[i] - prices[i - 1];
        }
    }

    cout << profit << endl; // Maximum profit output
}

void better() {
    brute();
}

void optimal() {
    brute();
}

int main() {
    brute();
    return 0;
}
