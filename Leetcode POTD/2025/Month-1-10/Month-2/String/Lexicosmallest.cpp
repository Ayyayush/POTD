#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int i, j, s, count;
    cin >> s;

    char k;
    char mingreatest = 'z';  // Initialize to highest lower-case letter
    char target;
    cin >> target;  // Fix for reading a single character
    
    vector<char> letters(s);  // Initialize vector with size s

    for (i = 0; i < s; i++)
    {
        cin >> letters[i];  // Read each letter into the vector
    }

    // Transform all characters to lower-case
    transform(letters.begin(), letters.end(), letters.begin(), (int (*)(int))tolower);

    for (i = 0; i < letters.size(); i++)
    {
        if (letters[i] > target)
        {
            k = letters[i];
            mingreatest = min(k, mingreatest);  // Update mingreatest
        }
    }

    cout << mingreatest;
}

void better()

    {
    int i, s;
    cin >> s;

    char target, k;
    char mingreatest = '{'; // Initialize to a character lexicographically after 'z'
    cin >> target;

    vector<char> letters(s);

    for (i = 0; i < s; i++)
    {
        cin >> letters[i];
    }

    // Ensure letters are sorted (if not already sorted in the input)
    sort(letters.begin(), letters.end());

    for (i = 0; i < letters.size(); i++)
    {
        if (letters[i] > target)
        {
            mingreatest = letters[i]; // Find the smallest letter greater than target
            break;
        }
    }

    // If no valid letter found, wrap around and return letters[0]
    if (mingreatest == '{')
    {
        mingreatest = letters[0];
    }

    cout << mingreatest;

}
int main()
{
    brute();
    return 0;
}
