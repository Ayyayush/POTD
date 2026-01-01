#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(N^2 * 10) approx (since max 10 unique digits '0' to '4')
    // Space Complexity: O(1) (constant space since only 10 characters max)

    string s = "1122211";                   // Hardcoded string input
    int k = 3;                              // Minimum length of substring
    int maxdiff = INT_MIN;                 // Final answer

    for (int i = 0; i < s.size(); i++)
    {
        unordered_map<char, int> freq;     // Character frequency count

        for (int j = i; j < s.size(); j++)
        {
            freq[s[j]]++;                  // Current char frequency increase

            int len = j - i + 1;
            if (len >= k)                  // Only consider substrings of length at least k
            {
                int maxOdd = INT_MIN;
                int minEven = INT_MAX;
                for (auto it : freq)
                {
                    if (it.second % 2 == 1)               // Odd frequency
                        maxOdd = max(maxOdd, it.second);
                    else                                  // Even frequency
                        minEven = min(minEven, it.second);
                }

                // Only update answer if both odd and even freq exist
                if (maxOdd != INT_MIN && minEven != INT_MAX)
                    maxdiff = max(maxdiff, maxOdd - minEven);
            }
        }
    }

    // Edge case: agar kabhi dono freq nahi mile ek saath
    if (maxdiff == INT_MIN)
        cout << -1 << endl;
    else
        cout << maxdiff << endl;
}

int main()
{
    brute();
    return 0;
}
