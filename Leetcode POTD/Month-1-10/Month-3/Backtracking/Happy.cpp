#include <bits/stdc++.h>
using namespace std;

void generate(int n, string s, vector<string> &ans) {
    if (s.size() == n) {  
        ans.push_back(s); // ✅ Jab string ka length `n` ho jaye, store karenge
        return;
    }

    for (char ch : {'a', 'b', 'c'}) {  
        if (s.empty() || s.back() != ch) { // ✅ Consecutive same character avoid kar rahe hain
            generate(n, s + ch, ans);
        }
    }
}

void brute() {
    int n, k;
    cin >> n >> k; // ✅ Input le rahe hain

    vector<string> ans;
    generate(n, "", ans); // ✅ Recursion start kar rahe hain

    if (k > ans.size())  
        cout << "" << endl; // ✅ Agar k > total strings, toh empty return karenge
    else
        cout << ans[k - 1] << endl; // ✅ k-th lexicographical happy string print karenge
}

int main() {
    brute();
    return 0;
}
