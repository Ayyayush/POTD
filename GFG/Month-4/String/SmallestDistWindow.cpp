#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(N^2) in worst case, because for each character we might check full substring
    // Space Complexity: O(K) where K is the number of unique characters in string

    string s;
    cin >> s;

    unordered_map<char, int> st1;
    for (char ch : s)
        st1[ch]++; // O(N)        // Map bana rahe hain characters ka count ke saath

    unordered_map<char, int> st2; // O(K) space
    string minStr = s;            // Final result
    string res;                   // Current window string
    int i = 0, j = 0;

    while (j < s.size()) // Outer loop runs O(N) times
    {
        st2[s[j]]++; // O(1) avg
        res += s[j]; // O(1) amortized

        while (st2.size() == st1.size()) // Inner loop runs at most O(N) in total across all outer loops
        {
            if (res.size() < minStr.size()) // O(1)
            {
                minStr = res; // O(1)
            }

            st2[s[i]]--; // Shrinking window from left
            if (st2[s[i]] == 0)
                st2.erase(s[i]); // O(1) avg

            res.erase(0, 1); // O(N) in worst case (bad in long string case)
            i++;
        }

        j++;
    }

    cout << minStr << endl;
}

void better()
{
    // Time Complexity: O(N)
    // Space Complexity: O(K), where K = number of distinct characters in string

    string s;
    cin >> s;

    unordered_set<char> uniqueChars(s.begin(), s.end()); // O(N)
    int totalUnique = uniqueChars.size();

    unordered_map<char, int> freqMap;
    int i = 0, minLen = INT_MAX, startIdx = 0, count = 0;

    for (int j = 0; j < s.size(); j++)
    {
        freqMap[s[j]]++;
        if (freqMap[s[j]] == 1)
            count++; // New unique char in window

        while (count == totalUnique) // Valid window
        {
            if (j - i + 1 < minLen)
            {
                minLen = j - i + 1;
                startIdx = i;
            }

            freqMap[s[i]]--;
            if (freqMap[s[i]] == 0)
                count--; // Unique character removed
            i++;
        }
    }

    cout << s.substr(startIdx, minLen) << endl;
}

int main()
{
    brute();
    return 0;
}
