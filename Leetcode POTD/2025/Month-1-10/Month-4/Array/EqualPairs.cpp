#include <bits/stdc++.h>
using namespace std;

void better() {
    vector<int> nums = {3, 3, 2, 2, 2, 2}; // Sample input
    map<int, int> mp; // Har number ki frequency store karne ke liye map
    
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++; // Frequency count kar rahe hain
    }
    
    for (auto it : mp) {
        if (it.second % 2 != 0) { // Agar koi frequency odd hai to false
            cout << "false" << endl;
            return;
        }
    }
    
    cout << "true" << endl; // Agar sab even frequency wale hain to true
}

/*
Time Complexity: O(N log N)  
 - Map insertion O(log N) leta hai, aur N elements insert ho rahe hain -> O(N log N)  
 - Looping through the map O(N) hai, lekin dominating factor O(N log N) hai.  

Space Complexity: O(N)  
 - Map worst case mein N distinct elements store karega.
*/

void optimal() {
    vector<int> nums = {3, 3, 2, 2, 2, 2}; // Sample input
    int freq[501] = {0}; // Frequency array
    
    for (int num : nums) {
        freq[num]++;
    }
    
    for (int i = 1; i <= 500; i++) {
        if (freq[i] % 2 != 0) { // Agar koi frequency odd hai to false
            cout << "false" << endl;
            return;
        }
    }
    
    cout << "true" << endl; // Agar sab even frequency wale hain to true
}

/*
Time Complexity: O(N)  
 - Sirf ek hi loop hai jo N elements traverse karta hai, aur ek fixed size ka loop (O(500) ≈ O(1)).  
 - Isliye overall O(N).

Space Complexity: O(1)  
 - Fixed size array (501 size ka), jo constant space consider hota hai.
*/

int main() {
    better();
    optimal();
    return 0;
}
