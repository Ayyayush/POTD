#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////////////
// BRUTE FORCE APPROACH
// ----------------------------------------------------------
// IDEA:
// Traverse the string from the END and print each word
// as soon as we detect a space.
//
// EXAMPLE:
// Input : "hello world from spt"
// Scan from the end:
// "spt" → print
// "from" → print
// "world" → print
// "hello" → print
//
// Time Complexity:  O(n²)   (due to inner printing loop)
// Space Complexity: O(1)
/////////////////////////////////////////////////////////////
void brute()
{
    string str;
    getline(cin, str);

    int n = str.size();
    int flag = n;       // Marks the end of each word

    // Traverse from the end
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            // Print the word between i+1 and flag-1
            for (int j = i + 1; j < flag; j++)
                cout << str[j];
            cout << " ";

            flag = i;   // Move flag to current position
        }
    }

    // Print the first word
    for (int j = 0; j < flag; j++)
        cout << str[j];

    cout << endl;
}

/////////////////////////////////////////////////////////////
// BETTER APPROACH
// ----------------------------------------------------------
// IDEA:
// Same as brute, but instead of printing directly,
// we STORE reversed words inside a string and print at the end.
//
// EXAMPLE:
// Input : "hello world spt"
// result = "spt world hello"
//
// Time Complexity:  O(n²)   (due to repeated concatenation)
// Space Complexity: O(n)
/////////////////////////////////////////////////////////////
void better()
{
    string str;
    getline(cin, str);

    int n = str.size();
    string result = "";
    int flag = n;

    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            for (int j = i + 1; j < flag; j++)
                result += str[j];
            result += " ";
            flag = i;
        }
    }

    // Add first word
    for (int j = 0; j < flag; j++)
        result += str[j];

    cout << result << endl;
}

/////////////////////////////////////////////////////////////
// OPTIMAL APPROACH - 1
// ----------------------------------------------------------
// IDEA:
// Move from RIGHT → LEFT
// 1. Skip extra spaces
// 2. Extract each word using indices
// 3. Append into result
//
// EXAMPLE:
// s = "  hello  world  spt  "
// Output = "spt world hello"
//
// Time Complexity:  O(n)
// Space Complexity: O(n)
/////////////////////////////////////////////////////////////
class Solution1 {
public:
    string reverseWords(string s) {
        int n = s.size();
        string result = "", word = "";
        int i = n - 1;

        while (i >= 0) {

            // Skip spaces
            while (i >= 0 && s[i] == ' ') i--;

            if (i < 0) break;

            int j = i;

            // Find the start of the word
            while (i >= 0 && s[i] != ' ') i--;

            word = s.substr(i + 1, j - i);      // Extract current word

            if (!result.empty()) result += " ";
            result += word;
        }

        return result;
    }
};

/////////////////////////////////////////////////////////////
// OPTIMAL APPROACH - 2 (Using stringstream)
// ----------------------------------------------------------
// IDEA:
// stringstream splits the string on spaces.
// We push each token to the front of result.
//
// EXAMPLE:
// Input: "hello world spt"
// token = hello → result = "hello"
// token = world → result = "world hello"
// token = spt   → result = "spt world hello"
//
// Time Complexity:  O(n)
// Space Complexity: O(n)
/////////////////////////////////////////////////////////////
class Solution2 {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "", result = "";

        while (ss >> token) {
            result = token + " " + result;    // Insert at front
        }

        return result.substr(0, result.length() - 1); // Remove last space
    }
};

/////////////////////////////////////////////////////////////
// OPTIMAL APPROACH - 3 (Fastest two-pointer)
// ----------------------------------------------------------
// IDEA:
// Use two pointers from the back.
// Extract every word using substring.
//
// EXAMPLE:
// s = "hello world spt"
// → "spt world hello"
//
// Time Complexity:  O(n)
// Space Complexity: O(n)
/////////////////////////////////////////////////////////////
class Solution3 {
public:
    string reverseWords(string s) {
        int i = s.size() - 1;
        int j = s.size();
        string temp = "";

        while (i >= 0) {
            if (s[i] == ' ') {
                if (i + 1 < j) {
                    temp += s.substr(i + 1, j - i - 1);
                    temp += ' ';
                }
                j = i;
            }
            i--;
        }

        // First word
        if (j > 0)
            temp += s.substr(0, j);

        // Remove trailing spaces
        while (!temp.empty() && temp.back() == ' ')
            temp.pop_back();

        return temp;
    }
};

/////////////////////////////////////////////////////////////
void optimal()
{
    // Using optimal class
    Solution1 obj;
    string s;
    getline(cin, s);
    cout << obj.reverseWords(s);
}
/////////////////////////////////////////////////////////////

int main()
{
    // CALL ANY FUNCTION HERE
    // brute();
    // better();
    optimal();
    return 0;
}
