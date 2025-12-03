#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Approach: Right to Left Traversal with Subtractive Handling (Brute Force)
    // T.C = O(n) where n = length of Roman numeral string
    // S.C = O(1) as only constant-sized map is used

    string s;
    cin >> s;     // Input Roman numeral string

    unordered_map<char, int> mp;                  
    mp['I'] = 1;                                  
    mp['V'] = 5;                                  
    mp['X'] = 10;                                 
    mp['L'] = 50;                                 
    mp['C'] = 100;                                
    mp['D'] = 500;                                
    mp['M'] = 1000;                               

    long long sum = 0;                             // Final decimal result

    for (int i = s.size() - 1; i >= 0; i--)        // Traverse from end to start
    {
        char ch = s[i];                            // Current character
        sum += mp[s[i]];                           // Add its value
        i--;                                       // Move to previous character to check for subtractive pair

        while (i >= 0 && mp[s[i]] < mp[ch])        // If smaller value exists before larger one
        {
            sum -= mp[s[i]];                       // Subtract its value
            i--;                                   // Keep moving left
        }

        i++;                                       // Compensate extra decrement from inner loop
    }

    cout << sum << endl;                           // Output final result
}


void better()
{
    // Approach: Left to Right with lookahead to detect subtractive pattern
    // T.C = O(n)
    // S.C = O(1)

    string s;
    cin >> s;

    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int n = s.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        // Check if next character exists and has greater value than current → Subtractive case
        if (i + 1 < n && mp[s[i]] < mp[s[i + 1]])
        {
            sum += mp[s[i + 1]] - mp[s[i]];      // Combine and add difference
            i++;                                 // Skip next character as it's already processed
        }
        else
        {
            sum += mp[s[i]];                     // Normal case
        }
    }

    cout << sum << endl;
}

int main()
{
    brute();
    return 0;
}
