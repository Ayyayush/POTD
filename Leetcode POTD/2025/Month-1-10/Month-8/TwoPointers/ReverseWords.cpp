#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // T.C = O(n), S.C = O(n)    // n = length of string

    string s;
    getline(cin, s);                                      // Input line with spaces

    vector<string> vec;                                   // Vector to store individual words
    string temp = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            if (!temp.empty()) {                          // Avoid pushing empty strings from multiple spaces
                vec.push_back(temp);
                temp = "";
            }
        } else {
            temp += s[i];                                 // Add character to current word
        }
    }

    if (!temp.empty()) vec.push_back(temp);               // Push last word if any

    reverse(vec.begin(), vec.end());                      // Reverse the vector of words

    string result = "";
    for (int i = 0; i < vec.size(); i++) {
        result += vec[i];                                 // Add each word
        if (i != vec.size() - 1) result += ' ';           // Add space between words
    }

    cout << result << endl;                               // Output the final reversed sentence
}



void good()
{
    // T.C = O(n), S.C = O(n)         // n = length of string

    string s;
    getline(cin, s);                                          // Input full line with spaces

    int i = s.size() - 1;
    int j = s.size();
    string temp = "";

    while (i >= 0)
    {
        if (s[i] == ' ')
        {
            if (i + 1 < j)                                     // Word exists between i+1 and j-1
            {
                temp += s.substr(i + 1, j - i - 1);            // Add that word to result
                temp += ' ';                                   // Add space
            }
            j = i;                                             // Move end pointer to space
        }
        i--;
    }

    // Add the first word (from 0 to j-1)
    if (j > 0)
    {
        temp += s.substr(0, j);
    }

    // Trim trailing spaces (if any)
    while (!temp.empty() && temp.back() == ' ')
    {
        temp.pop_back();
    }

    cout << temp << endl;                                      // Output the final reversed sentence
}




void better()
{
    /*
     * 💡 Approach: Using stringstream
     * --------------------------------------------
     * 🔸 Tokenize string using stringstream.
     * 🔸 Prepend each word to result.
     * 🔸 Trim trailing space before output.
     * 🔸 T.C. = O(N), S.C. = O(N)
     * --------------------------------------------
     */

    string s;
    getline(cin, s);                            // Input line with spaces

    stringstream ss(s);
    string token;
    string result;

    while (ss >> token) {
        result = token + " " + result;          // Prepend each word
    }

    if (!result.empty())
        result.pop_back();                      // Remove last extra space

    cout << result << endl;
}

void optimal()
{
    /*
     * 💡 Approach: Two Pointer (Reverse In-place)
     * ----------------------------------------------------------
     * 🔸 Step 1: Reverse the entire string
     * 🔸 Step 2: Use two pointers (l and r) to reverse individual words
     * 🔸 Step 3: Overwrite extra spaces and compress
     * 🔸 Step 4: Resize final string using substr
     * 🔸 T.C. = O(N), S.C. = O(1)
     * ----------------------------------------------------------
     */

    string s;
    getline(cin, s);                                // Input string with spaces

    reverse(s.begin(), s.end());                    // Step 1: Reverse full string

    int i = 0;
    int l = 0, r = 0;
    int n = s.length();

    while (i < n) {
        while (i < n && s[i] != ' ') {
            s[r++] = s[i++];                        // Copy word forward
        }

        if (l < r) {
            reverse(s.begin() + l, s.begin() + r);  // Step 2: Reverse current word
            s[r++] = ' ';                           // Add single space after word
            l = r;                                  // Move l to r for next word
        }

        i++;                                         // Skip multiple spaces
    }

    if (r > 0) r--;                                  // Remove trailing space
    s = s.substr(0, r);                              // Final trimming

    cout << s << endl;                               // Output result
}

int main()
{
    optimal();
    return 0;
}
