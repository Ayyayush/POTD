#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(n^2) because of nested loop for minimum character calculation inside main loop
    // Space Complexity: O(n) for storing temporary strings t and p

    string s;
    cin >> s; // Input string

    string t = "", p = ""; // t = temporary stack string, p = final answer string

    for (int i = 0; i < s.size(); i++) // poora string traverse karo
    {
        t += s[i]; // current character t mein daalo

        // suffix minimum character calculate kar rahe hain manually nested loop se
        char minch = s[i];                      
        for (int j = i + 1; j < s.size(); j++) 
        {
            if (minch > s[j])
            {
                minch = s[j]; // minimum character update karo aage ke characters me
            }
        }

        // Jab tak t empty nahi hai aur t ka last character suffix minimum se chhota ya barabar hai
        while (!t.empty() && t.back() <= minch)
        {
            p += t.back(); // t ke last character ko p mein daalo
            t.pop_back();  // t se last character hatao (pop)
        }
    }

    // Loop ke baad agar t mein koi characters bache hain to unko reverse order mein p mein daalo
    while (!t.empty())
    {
        p += t.back();
        t.pop_back();
    }

    cout << p << endl; // Final string print karo
}

void better()
{
    // Time Complexity: O(n) due to pre-processing suffix minimums and single pass stack simulation
    // Space Complexity: O(n) for suffix minimum array and temporary strings

    string s;
    cin >> s; // Input string

    string t = "", p = ""; // t = temporary stack string, p = final answer string

    int n = s.size();
    vector<char> minchar(n + 1, '{'); // suffix minimum array, '{' is a character greater than 'z'

    // Preprocessing suffix minimums from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        minchar[i] = min(s[i], minchar[i + 1]);
    }
    // minchar[i] represents minimum character from s[i] to s[n-1]

    int i = 0;
    while (i < n)
    {
        t.push_back(s[i]); // current character t mein daalo

        // suffix minimum for the remaining characters after current index i
        char rightMin = minchar[i + 1];

        // jab tak t empty nahi hai aur t ka last character suffix minimum se chhota ya barabar hai
        while (!t.empty() && t.back() <= rightMin)
        {
            p += t.back(); // t ke last character ko p mein daalo
            t.pop_back();  // t se last character hatao (pop)
        }
        i++;
    }

    // loop ke baad agar t mein koi characters bache hain to unko reverse order mein p mein daalo
    while (!t.empty())
    {
        p += t.back();
        t.pop_back();
    }

    cout << p << endl; // Final string print karo
}

int main()
{
    // Call brute or better to test
    brute();
    // better();
    return 0;
}
