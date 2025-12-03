#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O((n - m + 1) * m) ≈ O(n * m)      // n = txt.size(), m = pat.size()
    // Space Complexity: O(1) (excluding output vector)

    string pat, txt;
    cin >> txt >> pat;

    vector<int> index;     // Matching positions store karne ke liye
    int size = pat.size(); // Pattern ka size

    for (int i = 0; i < txt.size(); i++)
    {
        if (i + size - 1 < txt.size() && txt.substr(i, size) == pat)
        {
            index.push_back(i + 1); // 1-based indexing ke according push karo
        }
    }

    for (int i : index)
        cout << i << " ";
    cout << endl;
}

void good()
{
    // Time Complexity: O((n - m + 1) * m) in worst case     // Slightly better in practical performance
    // Space Complexity: O(1) (excluding output vector)

    string pat, txt;
    cin >> txt >> pat;

    vector<int> index;
    int size = pat.size();
    int j = 0;

    while (j < txt.size())
    {
        // Pehle check karo ki pattern fit ho sakta hai aur first/last char match karta hai ya nahi
        if (j + size - 1 < txt.size() && txt[j] == pat[0] && txt[j + size - 1] == pat[pat.size() - 1])
        {
            if (txt.substr(j, size) == pat)
            {
                index.push_back(j + 1); // 1-based indexing ke according result store karo
            }
        }
        j++;
    }

    for (int i : index)
        cout << i << " ";
    cout << endl;
}

// Ye helper function pattern aur text ka substring compare karta hai character by character
bool isMatch(const string &txt, const string &pat, int start)
{
    for (int i = 0; i < pat.size(); i++)
    {
        if (txt[start + i] != pat[i])
            return false;
    }
    return true;
}






// ✅ Optimal approach using Rabin-Karp Algorithm
// T.C. = O(n + m) average case, O(n * m) worst case (hash collisions)
// S.C. = O(1)
void optimal()
{
    string txt, pat;
    cin >> txt >> pat; // user se text aur pattern input lo

    int n = txt.size(); // text ka length
    int m = pat.size(); // pattern ka length

    vector<int> result; // answer store karne ke liye

    if (m > n)
    { // agar pattern text se bada hai toh match ho hi nahi sakta
        cout << "No match found\n";
        return;
    }

    int patHash = 0; // pattern ka hash
    int txtHash = 0; // text ke initial m characters ka hash
    int power = 1;   // base powers ka tracking (base^(m-1))

    // 🔁 Initial hash calculate kar rahe hain pattern aur first window of text ka
    for (int i = m - 1; i >= 0; i--)
    {
        int patVal = pat[i] - 'a' + 1; // pattern ka character value (1 to 26)
        int txtVal = txt[i] - 'a' + 1; // text ka character value (1 to 26)

        patHash = (patHash + (patVal * power) % MOD) % MOD;
        txtHash = (txtHash + (txtVal * power) % MOD) % MOD;

        if (i != 0)
            power = (power * BASE) % MOD; // power ko update karo except last iteration
    }

    int highestPower = power; // leftmost character remove karne ke liye base^(m-1)

    // 🔍 Check first window (0th index)
    if (txtHash == patHash && isMatch(txt, pat, 0))
    {
        result.push_back(1); // 1-based indexing
    }

    // 🔁 Sliding window hash rolling
    for (int i = 1; i <= n - m; i++)
    {
        int leftVal = txt[i - 1] - 'a' + 1;      // jo character nikal raha hai (leftmost)
        int rightVal = txt[i + m - 1] - 'a' + 1; // jo character add ho raha hai (rightmost)

        // remove leftmost char contribution (modulo add to prevent negative)
        txtHash = (txtHash - (leftVal * highestPower) % MOD + MOD) % MOD;

        // shift left and add new rightmost char
        txtHash = (txtHash * BASE) % MOD;
        txtHash = (txtHash + rightVal) % MOD;

        // agar hash match kare toh manually match bhi check karo to avoid collision
        if (txtHash == patHash && isMatch(txt, pat, i))
        {
            result.push_back(i + 1); // 1-based indexing
        }
    }

    // ✅ Final result print karo
    if (result.empty())
    {
        cout << "No match found\n";
    }
    else
    {
        cout << "Pattern found at positions: ";
        for (int pos : result)
            cout << pos << " ";
        cout << endl;
    }
}




int main()
{
    better();
    return 0;
}
