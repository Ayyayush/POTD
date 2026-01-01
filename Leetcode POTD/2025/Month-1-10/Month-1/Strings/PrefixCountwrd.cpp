#include <bits/stdc++.h>
using namespace std;

void brute() {
    // Time Complexity: O(s * n), where s = number of words, n = average word length.
    // - `words[i].find(pref)` takes O(n) for each word.
    // - Overall complexity is O(s * n).

    int s, count = 0, i;
    cin >> s;
    cin.ignore();
    vector<string> words(s);
    for (i = 0; i < s; i++) {
        getline(cin, words[i]);
    }
    string pref;
    getline(cin, pref);

    for (i = 0; i < words.size(); i++) {
        if (pref[0] == words[i][0]) {
            if (words[i].find(pref) != string::npos)
                count++;
        }
    }

    cout << count << endl;
}

void brute_mismatch() {
    // Time Complexity: O(s * min(n, p)), where:
    // - s = number of words
    // - n = average word length
    // - p = length of the prefix.
    // `std::mismatch` compares characters until the prefix ends or a mismatch occurs.

    int s, count = 0, i;
    cin >> s;
    cin.ignore();
    vector<string> words(s);
    for (i = 0; i < s; i++) {
        getline(cin, words[i]);
    }
    string pref;
    getline(cin, pref);

    for (i = 0; i < words.size(); i++) {
        if (std::mismatch(pref.begin(), pref.end(), words[i].begin()).first == pref.end()) {
            count++;
        }
    }

    cout << count << endl;
}

void brute_rfind() {
    // Time Complexity: O(s * p), where:
    // - s = number of words
    // - p = length of the prefix.
    // `rfind` with position 0 checks the prefix in constant time for each word.

    int s, count = 0, i;
    cin >> s;
    cin.ignore();
    vector<string> words(s);
    for (i = 0; i < s; i++) {
        getline(cin, words[i]);
    }
    string pref;
    getline(cin, pref);

    for (i = 0; i < words.size(); i++) {
        if (words[i].rfind(pref, 0) == 0) { // Check if prefix starts at index 0
            count++;
        }
    }

    cout << count << endl;
}

void brute_compare() {
    // Time Complexity: O(s * p), where:
    // - s = number of words
    // - p = length of the prefix.
    // `compare` only checks up to the length of the prefix.

    int s, count = 0, i;
    cin >> s;
    cin.ignore();
    vector<string> words(s);
    for (i = 0; i < s; i++) {
        getline(cin, words[i]);
    }
    string pref;
    getline(cin, pref);

    for (i = 0; i < words.size(); i++) {
        if (words[i].compare(0, pref.size(), pref) == 0) { // Compare prefix with starting part of word
            count++;
        }
    }

    cout << count << endl;
}

void better() {
    // Placeholder for an optimized implementation if needed.
    // Potential optimization could use a Trie or a hash table for faster prefix matching.
}

int main() {
    brute_mismatch();
    return 0;
}
