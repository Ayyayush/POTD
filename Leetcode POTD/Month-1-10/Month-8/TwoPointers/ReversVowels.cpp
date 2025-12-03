#include <bits/stdc++.h>
using namespace std;

void brute() {
    // Approach: Store vowels and replace in second pass
    // T.C. = O(n), S.C. = O(n)

    string s = "leetcode";                    // example input
    string res;

    // First pass: store vowels in reverse
    for (int i = s.size() - 1; i >= 0; i--) {
        char c = tolower(s[i]);               // lowercase check
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            res.push_back(s[i]);              // store vowel
        }
    }

    // Second pass: replace vowels
    int idx = 0;
    for (int i = 0; i < s.size() && idx < res.size(); i++) {
        char c = tolower(s[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            s[i] = res[idx++];                // replace with reversed vowel
        }
    }

    cout << s << endl;                        // output: leotcede
}

void better() {
    // Approach: Two-pointer optimal swap method
    // T.C. = O(n), S.C. = O(1)

    string s = "leetcode";                    // example input

    int i = 0, j = s.size() - 1;

    auto isVowel = [](char c) {
        c = tolower(c);                       // lowercase check
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };

    while (i < j) {
        while (i < j && !isVowel(s[i])) i++;  // move i to next vowel
        while (i < j && !isVowel(s[j])) j--;  // move j to previous vowel

        if (i < j) {
            swap(s[i], s[j]);                 // swap the vowels
            i++;
            j--;
        }
    }

    cout << s << endl;                        // output: leotcede
}

int main() {
    brute();
    better();
    return 0;
}
