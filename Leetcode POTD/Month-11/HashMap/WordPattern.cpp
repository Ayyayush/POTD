#include <bits/stdc++.h>
using namespace std;

/*
----------------------------------------
🧠 PROBLEM: Word Pattern (LeetCode 290)
----------------------------------------
Given a pattern string and a sentence s,
check if s follows the same pattern.

Example:
pattern = "abba"
s = "dog cat cat dog" → ✅ true
pattern = "abba"
s = "dog cat cat fish" → ❌ false
----------------------------------------
*/

//------------------------------------------------
// 🧩 BRUTE APPROACH
// Approach: Generate all mappings and check each manually
// T.C. = O(n^2)        (string splitting + repeated checking)
// S.C. = O(n)
//------------------------------------------------
void brute() {
    string pattern = "abba";
    string s = "dog cat cat dog";

    vector<string> words;            // sentence ko words me todhna
    stringstream ss(s);
    string word;
    while (ss >> word) words.push_back(word);

    if (pattern.size() != words.size()) {
        cout << "false";
        return;
    }

    // check all pairs manually (inefficient)
    for (int i = 0; i < pattern.size(); i++) {
        for (int j = i + 1; j < pattern.size(); j++) {
            if ((pattern[i] == pattern[j] && words[i] != words[j]) ||
                (pattern[i] != pattern[j] && words[i] == words[j])) {
                cout << "false";
                return;
            }
        }
    }

    cout << "true";
}

//------------------------------------------------
// ⚙️ BETTER APPROACH
// Approach: Use a single hashmap (char → word) mapping
// But not bidirectional, so limited consistency check
// T.C. = O(n)
// S.C. = O(n)
//------------------------------------------------
void better() {
    string pattern = "abba";
    string s = "dog cat cat dog";

    vector<string> words;
    stringstream ss(s);
    string word;
    while (ss >> word) words.push_back(word);

    if (pattern.size() != words.size()) {
        cout << "false";
        return;
    }

    unordered_map<char, string> mp;

    for (int i = 0; i < pattern.size(); i++) {
        char c = pattern[i];
        if (mp.find(c) == mp.end()) {
            mp[c] = words[i];                     // new mapping
        } else if (mp[c] != words[i]) {           // mismatch mila
            cout << "false";
            return;
        }
    }

    cout << "true";                               // partial correctness
}

//------------------------------------------------
// 🚀 OPTIMAL APPROACH (One-to-One Mapping)
// Approach: Use TWO hashmaps for both sides
// 1️⃣ pattern → word
// 2️⃣ word → pattern
// ensures bijective (1-1) mapping
// T.C. = O(n)
// S.C. = O(n)
//------------------------------------------------
void optimal() {
    string pattern = "abcbc";
    string s = "dog cat bag dog bag";

    vector<string> words;
    stringstream ss(s);
    string word;
    while (ss >> word) words.push_back(word);       // split words

    if (pattern.size() != words.size()) {
        cout << "false";
        return;
    }

    unordered_map<char, string> mp1;                // pattern → word
    unordered_map<string, char> mp2;                // word → pattern

    for (int i = 0; i < pattern.size(); i++) {
        char c = pattern[i];
        string w = words[i];

        // agar char already map hai lekin different word mila
        if (mp1.find(c) != mp1.end() && mp1[c] != w) {
            cout << "false";
            return;
        }

        // agar word already map hai lekin different char mila
        if (mp2.find(w) != mp2.end() && mp2[w] != c) {
            cout << "false";
            return;
        }

        mp1[c] = w;                                 // mapping create karo
        mp2[w] = c;
    }

    cout << "true";                                 // pattern matched successfully ✅
}

int main() {
    cout << "Brute → "; brute();
    cout << "\nBetter → "; better();
    cout << "\nOptimal → "; optimal();
    return 0;
}
