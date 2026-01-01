#include <bits/stdc++.h>
using namespace std;

void better()
{
    vector<string> words = {"lc", "cl", "gg"};    /* Example input */

    unordered_map<string, int> mp;                /* Frequency map to count words */
    int result = 0;                                /* Final result to store max palindrome length */

    // Step 1: Pair the word with its reverse
    for (string &word : words)
    {
        string reverseWord = word;                /* Copy the word */
        swap(reverseWord[0], reverseWord[1]);     /* Reverse the two letters */

        if (mp[reverseWord] > 0)                  /* If reverse pair already exists */
        {
            result += 4;                          /* It contributes 4 to the palindrome (2+2) */
            mp[reverseWord]--;                    /* Decrement the count of reverse pair */
        }
        else
        {
            mp[word]++;                           /* Otherwise, store this word for future pairing */
        }
    }

    // Step 2: Check if any word like "aa", "bb", etc. can be placed in the center
    for (auto &it : mp)
    {
        string word = it.first;
        int count = it.second;

        if (word[0] == word[1] && count > 0)      /* If both characters are same and count > 0 */
        {
            result += 2;                          /* We can place this in the center of palindrome */
            break;                                /* Only one such word can be used */
        }
    }

    cout << result << endl;                       /* Final output */
}



signed main()
{
    ios::sync_with_stdio(false); // Fast input/output ke liye syncing disable kar rahe hain
    cin.tie(NULL);               // cin ko cout se untie kar rahe hain taaki input/output aur fast ho jaye
    brute();

    return 0; // Program successful terminate ho raha hai
}
