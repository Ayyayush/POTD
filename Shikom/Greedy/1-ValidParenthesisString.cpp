#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        // Approach: Greedy (Min-Max Open Brackets)
        // Time Complexity: O(n)
        // Space Complexity: O(1)

        int minOpen = 0;     // minimum possible '(' count
        int maxOpen = 0;     // maximum possible '(' count

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                minOpen++;                  // '(' must increase open count
                maxOpen++;
            }
            else if (s[i] == ')') {
                minOpen--;                  // ')' closes one '('
                maxOpen--;
            }
            else { // s[i] == '*'
                minOpen--;                  // '*' can act as ')'
                maxOpen++;                  // '*' can act as '('
            }

            if (maxOpen < 0)                // too many ')' → invalid prefix
                return false;

            if (minOpen < 0)                // we cannot have negative '('
                minOpen = 0;
        }

        return minOpen == 0;                 // all '(' must be closed
    }
};
