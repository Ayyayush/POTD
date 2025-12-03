#include <bits/stdc++.h>
using namespace std;
void brute()
{
    stack<char> st;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[' || s[i] == '(' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                cout << "1-" << "False" << endl;
                return;
            }
            char c = s[i];
            if (!st.empty() && c == '}' && st.top() == '{')
            {
                st.pop();
            }
           else if (!st.empty() && c == ')' && st.top() == '(')
            {
                st.pop();
            }
            else if (!st.empty() && c == ']' && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                cout << "2-" << "False" << endl;
                return;
            }
        }
    }

    if (st.empty())
    {
        cout << "True" << endl;

        return;
    }
    else
    {
        cout << "2-" << "False" << endl;
        return;
    }
}
int main()
{
    brute();
    return 0;
}