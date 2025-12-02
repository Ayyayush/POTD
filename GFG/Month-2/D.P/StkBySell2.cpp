#include <bits/stdc++.h>
using namespace std;

void brute() {
    /* Time Complexity: O(N)  
       Space Complexity: O(1)  
       - N: Array ki size  
       - O(1): Kyunki sirf constant variables use ho rahe hain  
    */

    vector<int> prices = {3,3,5,0,0,3,1,4}; // Stock prices ka input

    if (prices.size() == 0) {
        cout << 0 << endl; // Agar koi price nahi hai to profit 0 hoga
        return;
    }

    int fb = INT_MIN, sb = INT_MIN; // First aur second buy track karne ke liye
    int fs = 0, ss = 0; // First aur second sell track karne ke liye

    for (int i = 0; i < prices.size(); i++) {
        fb = max(fb, -prices[i]);     // Pehla buy karne ka best time
        fs = max(fs, fb + prices[i]); // Pehla sell karne ka max profit
        sb = max(sb, fs - prices[i]); // Dusra buy karne ka best time
        ss = max(ss, sb + prices[i]); // Dusra sell karne ka max profit
    }

    cout << ss << endl; // Maximum profit output
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
