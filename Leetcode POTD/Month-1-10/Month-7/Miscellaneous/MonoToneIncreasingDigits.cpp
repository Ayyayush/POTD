#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // ✅ T.C. = O(n * d), d = digits in n, because har decrement ke saath full digit check
    // ✅ S.C. = O(d), string conversion

    int n;
    cin >> n;

    bool found = false;

    while (!found)
    {
        string s = to_string(n);                       // number ko string mein convert kiya

        if (s.size() == 1)
        {
            cout << n << endl;                         // single digit → already monotone increasing
            return;
        }

        int i = 0;
        for (i = 0; i < s.size() - 1; i++)             // adjacent digits ko check kar rahe hain
        {
            if (s[i] > s[i + 1])                       // agar koi digit > next digit hai
            {
                n--;                                   // number ko ek kam kar do
                break;                                 // check dobara karenge
            }
        }

        if (i == s.size() - 1)                         // agar pura loop chala without break → increasing
        {
            found = true;
        }
    }

    cout << n << endl;                                 // final valid number print karo
}

void better()
{
    // ✅ T.C. = O(d), where d = number of digits
    // ✅ S.C. = O(1)

    int n;
    cin >> n;

    string str = to_string(n);                         // number ko string mein convert kiya
    int mark = str.size();                             // mark → jaha se 9 lagana start karenge

    for (int i = str.size() - 1; i > 0; i--)            // right to left traversal
    {
        if (str[i] < str[i - 1])                        // agar current digit previous se choti hai
        {
            str[i - 1]--;                               // previous digit ko 1 se kam karo
            mark = i;                                   // mark = jaha se 9 fill karna hai
        }
    }

    for (int i = mark; i < str.size(); i++)            // mark se leke end tak sabko '9' karo
    {
        str[i] = '9';
    }

    cout << stoi(str) << endl;                         // final answer print karo
}

int main()
{
    // brute();
    better();
    return 0;
}
