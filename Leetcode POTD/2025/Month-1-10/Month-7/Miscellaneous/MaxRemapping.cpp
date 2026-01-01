#include <bits/stdc++.h>
using namespace std;

void brute() {
    // Time Complexity: O(N)                    // Ek hi baar poore number ke digits mein loop lagta hai
    // Space Complexity: O(N)                    // String mein conversion aur replacement ke liye

    int num = 11891;                            // Example number, tu input bhi le sakta hai
    string strnum = to_string(num);             // Number ko string mein convert kara

    string a = strnum, b = strnum;              // Do copies bana li value change karne ke liye

    char nonnine, nonzero;

    // 'a' mein pehla non-nine digit dhoondh ke use 9 se replace karenge
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != '9') {
            nonnine = a[i];
            break;
        }
    }

    // 'b' mein pehla non-zero digit dhoondh ke use 0 se replace karenge
    for (int i = 0; i < b.size(); i++) {
        if (b[i] != '0') {
            nonzero = b[i];
            break;
        }
    }

    // Ab 'a' mein har jagah us non-nine digit ko 9 se replace kar do
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == nonnine) {
            a[i] = '9';
        }
    }

    // Ab 'b' mein har jagah us non-zero digit ko 0 se replace kar do
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == nonzero) {
            b[i] = '0';
        }
    }

    // String ko wapas number mein convert kar ke difference nikalo
    long long p = stoll(a);
    long long q = stoll(b);

    cout << "Maximum number: " << p << endl;
    cout << "Minimum number: " << q << endl;
    cout << "Difference (p - q): " << p - q << endl;
}

int main() {
    brute();
    return 0;
}
