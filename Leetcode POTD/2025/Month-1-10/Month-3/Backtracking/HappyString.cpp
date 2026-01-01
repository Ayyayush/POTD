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



/*
1.>
generate(1, "", ans)
    ├── generate(1, "a", ans) → "a"
    ├── generate(1, "b", ans) → "b"
    ├── generate(1, "c", ans) → "c"


 2.>
generate(3, "", ans)
    ├── generate(3, "a", ans)
    │    ├── generate(3, "ab", ans)
    │    │    ├── generate(3, "aba", ans) → "aba"
    │    │    ├── generate(3, "abc", ans) → "abc"
    │    ├── generate(3, "ac", ans)
    │         ├── generate(3, "aca", ans) → "aca"
    │         ├── generate(3, "acb", ans) → "acb"
    ├── generate(3, "b", ans)
    │    ├── generate(3, "ba", ans)
    │    │    ├── generate(3, "bab", ans) → "bab"
    │    │    ├── generate(3, "bac", ans) → "bac"
    │    ├── generate(3, "bc", ans)
    │         ├── generate(3, "bca", ans) → "bca"
    │         ├── generate(3, "bcb", ans) → "bcb"
    ├── generate(3, "c", ans)
         ├── generate(3, "ca", ans)
         │    ├── generate(3, "cab", ans) → "cab"
         │    ├── generate(3, "cac", ans) → "cac"
         ├── generate(3, "cb", ans)
              ├── generate(3, "cba", ans) → "cba"
              ├── generate(3, "cbc", ans) → "cbc"
              
*/