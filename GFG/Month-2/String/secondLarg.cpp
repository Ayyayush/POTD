#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    // Function returns the second largest element
    int getSecondLargest(vector<int> &arr) {
        // Initializing variables
        int maximum = INT_MIN, secondMaximum = INT_MIN;
        
        // Loop through the array to find the maximum and second maximum
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > maximum) {
                secondMaximum = maximum; // Update second maximum
                maximum = arr[i];        // Update maximum
            } 
            else if(arr[i] > secondMaximum && arr[i] != maximum) {
                secondMaximum = arr[i];  // Update second maximum if condition is met
            }
        }
        
        // Return second largest element
        return secondMaximum;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
