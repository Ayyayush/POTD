#include <bits/stdc++.h>
using namespace std;
void brute()
{
    string s;
    getline(cin, s);
    map<char, int> lp;
    for (int i = 0; i < s.size(); i++)
    {
        lp[s[i]] = i;
    }

    int start = 0, end = 0, count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        end = max(end, lp[s[i]]);

        if (i == end)
        {
            count++;
            start = i + 1;
        }
    }

    cout << count << endl;
}
int main()
{
    brute();
    return 0;
}