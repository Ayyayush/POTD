#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach: Custom Comparator (Greedy)                                                
    // T.C: O(n log n * k)   → n log n for sorting, k = average string length
    // S.C: O(n)             → extra space for storing string representation of numbers
    string largestNumber(vector<int>& nums) {
        // Step 1: Convert sab numbers ko string me
        vector<string> arr;                                                              
        for (int num : nums) arr.push_back(to_string(num));                              

        // Step 2: Custom comparator for sorting (Greedy logic)
        sort(arr.begin(), arr.end(), [](string &a, string &b) {                          
            return a + b > b + a;                                                         
        });

        // Step 3: Agar first element "0" hai to iska matlab sab 0 hi hain
        if (arr[0] == "0") return "0";                                                    

        // Step 4: Final string build karo
        string result = "";                                                               
        for (string &s : arr) result += s;                                                

        return result;                                                                    
    }
};
