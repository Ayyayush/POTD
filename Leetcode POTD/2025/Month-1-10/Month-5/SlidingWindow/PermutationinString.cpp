#include <bits/stdc++.h>
using namespace std;

void brute() // o(N!*N)
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    sort(s1.begin(), s1.end());
    do
    {
        if (s2.find(s1) != string::npos)
        {
            cout << "true" << endl;
            exit(1);
        }
    } while (next_permutation(s1.begin(), s1.end())); // yeh galti thi: `s2.end()` ki jagah `s1.end()` aana chahiye
    cout << "False" << endl;
}


void better()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    sort(s1.begin(), s1.end());                  // ✅ yahan s1 ko sort karna hai

    string subs = "";
    int i = 0, j = 0;

    while (j < s2.size())
    {
        subs += s2[j];

        if (subs.size() == s1.size())
        {
            string subsort = subs;
            sort(subsort.begin(), subsort.end());
            if (subsort == s1)
            {
                cout << "True" << endl;
                return;
            }

            subs.erase(0, 1);                    // ✅ window slide karne ke liye pehla char hata rahe
            i++;
        }

        j++;
    }

    cout << "False" << endl;
}

int main()
{
    better();
    return 0;
}
