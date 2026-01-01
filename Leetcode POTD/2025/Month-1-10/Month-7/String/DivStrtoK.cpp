#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // T.C. = O(N)                     // N = s.size() -> poora string ek baar traverse hota hai
    // S.C. = O(N/K + K)               // Output vector mein N/K strings aur ek modified string banate ho

    string s;                          // Input string
    int k;                             // Har group ki length
    char fill;                         // Jo character se fill karna hai

    cin >> s >> k >> fill;             // Input le lo

    if (s.size() % k != 0)             // Agar s poora divide nahi hota k se
    {
        int tofill = k - (s.size() % k);    // Kitne characters fill karne hai
        s += string(tofill, fill);          // Correct way: string bana ke add karo
    }

    vector<string> str;                      // Answer vector
    for (int i = 0; i < s.size(); i += k)    // Har k length ka group banao
    {
        str.push_back(s.substr(i, k));       // Substring lo aur push karo
    }

    for (auto it : str)                      // Output print karo
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    brute();
    return 0;
}
