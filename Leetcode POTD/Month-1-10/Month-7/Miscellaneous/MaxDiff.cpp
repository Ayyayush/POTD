#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // T.C. = O(N)      // Har digit ko ek baar hi check kar rahe hain
    // S.C. = O(N)      // String storage ke liye

    int num; 
    cin >> num;     // Input le liya

    string strnum = to_string(num);    // Number ko string mein convert kiya
    string a = strnum, b = strnum;     // Max aur Min version banane ke liye alag alag copy

    char nonnine, nonmin;

    // ✅ Max banane ke liye pehla non-9 digit dhoondo
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != '9') {
            nonnine = a[i];
            break;
        }
    }

    // Saare wohi digit ko 9 bana do
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == nonnine) {
            a[i] = '9';
        }
    }

    // ✅ Min banane ke liye:
    if (b[0] != '1') {
        // Agar pehla digit 1 nahi hai toh pehla digit ko 1 bana do
        nonmin = b[0];
        for (int i = 0; i < b.size(); i++) {
            if (b[i] == nonmin) {
                b[i] = '1';
            }
        }
    } else {
        // Agar pehla digit 1 hai toh pehla non-zero non-one digit dhoondo
        for (int i = 1; i < b.size(); i++) {
            if (b[i] != '0' && b[i] != '1') {
                nonmin = b[i];
                break;
            }
        }
        for (int i = 0; i < b.size(); i++) {
            if (b[i] == nonmin) {
                b[i] = '0';
            }
        }
    }

    long long p = stoll(a);    // Max version ko integer banaya
    long long q = stoll(b);    // Min version ko integer banaya

    cout << p - q << endl;     // Difference print kiya
}

int main()
{
    brute();
    return 0;
}
