#include <bits/stdc++.h>
using namespace std;

// 💡 Brute Force Approach
// T.C: O(n^3), S.C: O(n)
void brute(vector<int>& digits) {
    unordered_set<int> st;
    int n = digits.size();

    // Teen nested loop se sab 3-digit combinations bana rahe hai
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(i == j || j == k || i == k) continue; // same index baar-baar use mat karo

                int num = digits[i]*100 + digits[j]*10 + digits[k];

                if(num >= 100 && num % 2 == 0) {
                    st.insert(num); // valid even 3-digit number
                }
            }
        }
    }

    vector<int> result(st.begin(), st.end());
    sort(result.begin(), result.end());

    // Output print karo
    cout << "Brute Output: ";
    for(int num : result) cout << num << " ";
    cout << endl;
}

// 💡 Better / Optimized Approach
// T.C: O(1), S.C: O(1)
void better(vector<int>& digits) {
    vector<int> result;
    vector<int> mp(10, 0); // digit frequency store kar rahe hai

    for(int &digit : digits) {
        mp[digit]++;
    }

    // i -> hundreds, j -> tens, k -> units (even hone chahiye)
    for(int i = 1; i <= 9; i++) {
        if(mp[i] == 0) continue;
        mp[i]--;
        for(int j = 0; j <= 9; j++) {
            if(mp[j] == 0) continue;
            mp[j]--;
            for(int k = 0; k <= 8; k += 2) { // only even digits for last
                if(mp[k] == 0) continue;
                mp[k]--;

                int num = i*100 + j*10 + k;
                result.push_back(num);

                mp[k]++;
            }
            mp[j]++;
        }
        mp[i]++;
    }

    sort(result.begin(), result.end());

    // Output print karo
    cout << "Better Output: ";
    for(int num : result) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> digits = {2, 1, 3, 0}; // sample input

    brute(digits);
    better(digits);

    return 0;
}
