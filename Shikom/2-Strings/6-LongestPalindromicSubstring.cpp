#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////
// BRUTE FORCE
// ----------------------------------------------------------
// Approach: Check all possible substrings and verify if
// each substring is a palindrome.
// T.C = O(n^3)
// S.C = O(1)
//////////////////////////////////////////////////////////////
void brute() 
{
    string s;
    cin >> s;

    int n = s.size();
    string longest = "";

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            string temp = s.substr(i, j - i + 1);   // extract substring
            string rev = temp;
            reverse(rev.begin(), rev.end());       // reverse to check palindrome

            if (temp == rev && temp.size() > longest.size())
                longest = temp;
        }
    }

    cout << longest << endl;
}

//////////////////////////////////////////////////////////////
// BETTER APPROACH (Dynamic Programming)
// ----------------------------------------------------------
// DP[i][j] = true if substring from i to j is palindrome
// T.C = O(n^2)
// S.C = O(n^2)
//////////////////////////////////////////////////////////////
void better()
{
    string s;
    cin >> s;

    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    string longest = "";

    // Single letters are palindromes
    for (int i = 0; i < n; i++) dp[i][i] = true;

    // Check substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            longest = s.substr(i, 2);
        }
    }

    // Check substrings of length >= 3
    for (int len = 3; len <= n; len++) {

        for (int i = 0; i + len - 1 < n; i++) {

            int j = i + len - 1;

            if (s[i] == s[j] && dp[i + 1][j - 1])   // inner substring must be palindrome  
            {
                dp[i][j] = true;
                longest = s.substr(i, len);
            }
        }
    }

    if (longest == "") longest = s.substr(0,1);  
    cout << longest << endl;
}

//////////////////////////////////////////////////////////////
// OPTIMAL APPROACH (Expand Around Center)
// ----------------------------------------------------------
// For each index, expand in both directions for:
// 1. Odd-length palindromes
// 2. Even-length palindromes
//
// T.C = O(n^2)
// S.C = O(1)
//////////////////////////////////////////////////////////////
string expand(string &s, int L, int R)
{
    while (L >= 0 && R < s.size() && s[L] == s[R]) {
        L--;
        R++;
    }
    return s.substr(L + 1, R - L - 1);      // final palindrome after expansion
}



void optimal()
{
    string s;
    cin >> s;

    int n = s.size();
    string longest = "";

    for (int i = 0; i < n; i++) {

        // Odd-length palindrome expansion
        string p1 = expand(s, i, i);

        // Even-length palindrome expansion
        string p2 = expand(s, i, i + 1);

        // Track longest result
        if (p1.size() > longest.size()) longest = p1;
        if (p2.size() > longest.size()) longest = p2;
    }

    cout << longest << endl;
}

//////////////////////////////////////////////////////////////
int main()
{
    optimal();     // choose approach
    return 0;
}
