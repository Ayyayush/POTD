#include <bits/stdc++.h>
using namespace std;

// ✅ Approach: Recursion to generate all subsequences
// T.C. = O(2^n * m)       (n = length of s, m = total words)
// S.C. = O(2^n)

void generateAllSubsequences(string &str, string currSubseq, int idx, unordered_map<string, int> &subseqFreq)
{
    if (idx >= str.size())
    {
        subseqFreq[currSubseq]++;                    // current subsequence ko count karo
        return;
    }

    // Include current character
    currSubseq += str[idx];
    generateAllSubsequences(str, currSubseq, idx + 1, subseqFreq);

    // Exclude current character (backtrack)
    currSubseq.pop_back();
    generateAllSubsequences(str, currSubseq, idx + 1, subseqFreq);
}

void brute()
{
    string s;
    int n;
    cin >> s >> n;                                    // Input string and number of words

    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];                              // Input words

    unordered_map<string, int> subseqFreq;            // Store all subsequences of s
    generateAllSubsequences(s, "", 0, subseqFreq);    // Generate all subsequences

    int count = 0;
    for (string word : words)
    {
        if (subseqFreq.count(word))                   // Agar word s ka subsequence hai
            count++;                                  // Count badhao
    }

    cout << count << endl;                            // Final output
}



// ✅ Approach: Two Pointer Check for Each Word
// T.C. = O(N * L) → N = number of words, L = avg length of word
// S.C. = O(1)

void better()
{
    string s;
    int n;
    cin >> s >> n;                               // Input string and number of words

    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];                         // Input all words

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        string word = words[i];
        int j = 0, k = 0;                        // j -> s string pointer, k -> word pointer

        while (j < s.size() && k < word.size())
        {
            if (s[j] == word[k])
                k++;                             // If match, move in word
            j++;                                 // Always move in s
        }

        if (k == word.size())                    // If full word matched
            count++;
    }

    cout << count << endl;                       // Final output
}





// ✅ Approach: Memoization + Two Pointer Subsequence Check
// T.C. = O(N * L), where N = number of words, L = avg length of each word
// S.C. = O(N) for storing memoization map

void optimal()
{
    string s;
    int n;
    cin >> s >> n;                                 // Input string and number of words

    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];                           // Input all words

    int count = 0;
    unordered_map<string, int> mp;                 // Memoization map to avoid duplicate work

    for (int i = 0; i < n; i++)
    {
        string word = words[i];

        if (mp.count(word))                        // If already matched before
        {
            count++;
            continue;
        }

        int j = 0, k = 0;                          // j -> s pointer, k -> word pointer

        while (j < s.size() && k < word.size())
        {
            if (s[j] == word[k])
                k++;                               // Move word pointer if match
            j++;                                   // Always move in s
        }

        if (k == word.size())                      // If full word matched
        {
            mp[word]++;                            // Memoize the match
            count++;
        }
    }

    cout << count << endl;                         // Final result
}



int main()
{
    better();
    return 0;
}
