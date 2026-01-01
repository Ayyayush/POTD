#include <bits/stdc++.h>
using namespace std;

void brute() {
    /*
        Approach: Permutation Check + Bitwise Power of 2 Check
        T.C. -> O(k! * k)       where k = number of digits in n
        S.C. -> O(k)            for storing string representation
    */

    int n;
    cin >> n;       // input number

    if (n <= 0) {
        cout << "false";
        return;
    }

    // Agar n already power of 2 hai
    if ((n & (n - 1)) == 0) {
        cout << "true";
        return;
    }

    string s = to_string(n);
    sort(s.begin(), s.end());   // sort so that next_permutation works correctly

    do {
        if (s[0] == '0') 
            continue;           // skip permutations starting with 0

        long long num = stoll(s);
        if ((num & (num - 1)) == 0) {    // power of 2 check
            cout << "true";
            return;
        }

    } while (next_permutation(s.begin(), s.end()));

    cout << "false";    // agar koi permutation power of 2 nahi nikla
}


#include <bits/stdc++.h>
using namespace std;

void better() {
    /*
        Approach: Compare Sorted Digit Strings of Powers of 2
        Idea: Agar hum input number ke digits ko sort karein aur usse
              har ek 2^p (p = 0 to 29) ke sorted digits se compare karein,
              to agar match mila matlab koi rearrangement power of 2 ban sakta hai.
        
        T.C. -> O(k log k + 30 * (k log k))    where k = number of digits in n
        S.C. -> O(k)                           for storing string
    */

    int n;
    cin >> n;   // input number

    // Convert input number to sorted string
    string s = to_string(n);
    sort(s.begin(), s.end());

    // Check all powers of 2 (up to 2^29 since 2^30 > 10^9)
    for (int p = 0; p <= 29; p++) {
        string powStr = to_string(1 << p);
        sort(powStr.begin(), powStr.end());
        if (s == powStr) {
            cout << "true";
            return;
        }
    }

    cout << "false";
}

int main() {
    better();
    return 0;
}

int main() {
    brute();
    return 0;
}
