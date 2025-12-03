#include <bits/stdc++.h>
using namespace std;

// -------------------------------------
// 🐢 BRUTE FORCE APPROACH
// T.C. = O(9×10^n × n × m)         (every number checked digit-by-digit against m-size array)
// S.C. = O(1)                      (no extra space used)
// -------------------------------------
void brute()
{
    int n;                                               // number of digits in the numbers we need to check
    cin >> n;

    int size;                                            // size of input array
    cin >> size;

    vector<int> arr(size);
    for (int i = 0; i < size; i++) cin >> arr[i];

    int count = 0;

    for (int num = pow(10, n - 1); num < pow(10, n); num++) {
        int temp = num;
        bool valid = false;

        while (temp > 0) {
            int digit = temp % 10;                       // current digit extract karo
            temp /= 10;

            for (int i = 0; i < size; i++) {
                if (arr[i] == digit) {                   // agar digit array mein mil gaya
                    valid = true;
                    break;
                }
            }

            if (valid) break;                            // agar match mil gaya to number count karo
        }

        if (valid) count++;
    }

    cout << count << endl;                               // final answer print karo
}


// -------------------------------------
// 🧠 BETTER APPROACH (Using unordered_map)
// T.C. = O(9×10^n × n)               (each n-digit number converted to string, digits checked in map)
// S.C. = O(10)                       (unordered_map with max 10 digits)
// -------------------------------------
void better()
{
    int n;                                               // number of digits in the numbers we have to check
    cin >> n;

    int size;                                            // size of array
    cin >> size;

    vector<int> arr(size);
    for (int i = 0; i < size; i++) cin >> arr[i];

    unordered_map<int, int> mp;
    for (int i = 0; i < size; i++) {
        mp[arr[i]]++;                                    // digit frequency store kar rahe
    }

    int count = 0;

    for (int i = pow(10, n - 1); i < pow(10, n); i++) {
        string str = to_string(i);                       // number ko string mein convert kiya

        for (int j = 0; j < str.size(); j++) {
            int digit = str[j] - '0';                    // har digit nikaal rahe
            if (mp.count(digit)) {                       // agar wo digit map mein hai (i.e., allowed hai)
                count++;                                 // to count increment
                break;                                   // ek baar match mil gaya to next number pe jaao
            }
        }
    }

    cout << count << endl;                               // final answer print karo
}


// -------------------------------------
// 🚀 OPTIMAL APPROACH (Using bool array)
// T.C. = O(9×10^n × n)               (each digit checked in O(1))
// S.C. = O(10)                       (bool array of 10 for allowed digits)
// -------------------------------------
void optimal()
{
    int n;                                               // number of digits in the numbers we need to check
    cin >> n;

    int size;                                            // size of input array
    cin >> size;

    vector<int> arr(size);
    for (int i = 0; i < size; i++) cin >> arr[i];

    bool allowed[10] = {false};                          // digit 0 to 9 ke liye bool array

    for (int i = 0; i < size; i++) {
        allowed[arr[i]] = true;                          // jis digit ko allow karna hai usko true mark karo
    }

    int count = 0;

    for (int num = pow(10, n - 1); num < pow(10, n); num++) {
        int temp = num;
        bool valid = false;

        while (temp > 0) {
            int digit = temp % 10;
            temp /= 10;

            if (allowed[digit]) {                        // agar digit allowed hai
                valid = true;
                break;
            }
        }

        if (valid) count++;                              // agar koi digit allowed mila to count increment
    }

    cout << count << endl;
}


// -------------------------------------
// 🔰 MAIN FUNCTION
// -------------------------------------
int main()
{
    optimal();      // you can switch between brute(), better(), and optimal()
    return 0;
}
