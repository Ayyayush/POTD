#include <bits/stdc++.h>
using namespace std;

void brute()
{
    string word;
    cin >> word;                                                       // 📥 Input word

    // ✅ Condition 1: Length should be ≥ 3
    if (word.length() < 3) {
        cout << "false\n";
        return;
    }

    bool hasVowel = false;                                             // 🔍 Flag for vowels
    bool hasConsonant = false;                                         // 🔍 Flag for consonants

    for (char ch : word) {
        if (!isalnum(ch)) {                                            // ❌ If not a digit or letter
            cout << "false\n";                                         // ⇒ Invalid character
            return;
        }

        if (isalpha(ch)) {                                             // ✅ Check only alphabetic characters
            char lowerCh = tolower(ch);                                // 🔽 Convert to lowercase to simplify checks

            if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' ||
                lowerCh == 'o' || lowerCh == 'u') {
                hasVowel = true;                                       // ✅ It's a vowel
            } else {
                hasConsonant = true;                                   // ✅ It's a consonant
            }
        }
    }

    // ✅ Final condition: Must have both vowel and consonant
    if (hasVowel && hasConsonant)
        cout << "true\n";
    else
        cout << "false\n";
}
