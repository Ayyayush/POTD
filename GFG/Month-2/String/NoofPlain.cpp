#include <bits/stdc++.h>
using namespace std;

void brute() // O(N^2)
{
    string s;
    getline(cin, s);

    string longpalin = "";
    //int maxlen = 0; // Fix: Length negative nahi ho sakti, isliye 0 initialize kiya

    for (int i = 0; i < s.size(); i++)
    {
        string palin = "";
        for (int j = i; j < s.size(); j++)
        {
            palin += s[j];

            string revs = palin;
            reverse(revs.begin(), revs.end());

            if (palin == revs && revs.size() >= 2)
            {
                if (palin.size() < longpalin.size())
                {

                    longpalin = palin; // Fix: longpalin ko bhi update karna padega
                }
            }
        }
    }

    cout << longpalin << endl; // Fix: Sirf final longest palindrome print hoga
}

int main()
{
    brute();
    return 0;
}
