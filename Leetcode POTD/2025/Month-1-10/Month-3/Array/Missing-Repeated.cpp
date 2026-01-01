#include <bits/stdc++.h>
using namespace std;

void brute() {
    // Time Complexity: O(n^2)  ----->  2 nested loops traverse a matrix of size n x n.
    // Space Complexity: O(n^2) ----->  Map and vector store at most n^2 elements.
    
    int n;
    cin >> n;  // Matrix ka size input lena
    
    vector<vector<int>> nums(n, vector<int>(n));  // n x n matrix initialize karna
    map<int, int> mp;  // Elements ki frequency track karne ke liye map
    vector<int> vec;  // Missing ya duplicate elements store karne ke liye vector
    
    // Matrix ke elements input lena
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }
    
    // Duplicate elements find karna aur unhe vector me store karna
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mp.find(nums[i][j]) == mp.end()) {
                mp[nums[i][j]]++;  // Pehli baar aane wale element ko map me store karna
            } else {
                vec.push_back(nums[i][j]);  // Agar element pehle se hai, to wo duplicate hai
            }
        }
    }
    
    // Missing elements find karna
    for (int i = 1; i <= (n * n); i++) {
        if (mp.find(i) == mp.end()) {
            vec.push_back(i);  // Jo number missing hai, use vector me store karna
        }
    }
    
    // Output print karna
    for (auto x : vec) {
        cout << x << " ";
    }
}

void better()
{
    
}

int main() {
    brute();
    return 0;
}
