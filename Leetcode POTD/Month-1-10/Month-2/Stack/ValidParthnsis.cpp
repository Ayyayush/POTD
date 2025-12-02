#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int i, j, bracOpen = 0, bracClose = 0, braceleft = 0, braceright = 0, leftp = 0, rightp = 0;
    string stk;
    getline(cin, stk);
    for (i = 0; i < stk.size(); i++)
    {
        if (stk[i] == '(')
            bracOpen++;
        else if (stk[i] == ')')
            bracClose++;
        else if (stk[i] == '[')
            braceleft++;
        else if (stk[i] == ']')
            braceright++;
        else if (stk[i] == '{')
            leftp++;
        else if (stk[i] == '}')
            rightp++;
    }
    if (bracOpen == bracClose && leftp == rightp && braceleft == braceright)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}

void better()
{

    int i, j, bracOpen = 0, bracClose = 0, braceleft = 0, braceright = 0, leftp = 0, rightp = 0;
    stack<int> stk;
    string s;
    getline(cin, s);
    for (i = 0; i < s.size(); i++)
    {
        stk.push(s[i]);
    }
    while (stk.empty())
    {

        if (stk.top() == '(' && bracOpen == bracClose && braceleft == braceright && leftp == rightp)
        {
            bracOpen++;
        }
        else if (stk.top() == ')' && bracOpen > bracClose && braceleft == braceright && leftp == rightp)
        {
            bracClose++;
        }
        else if (stk.top() == '[' && bracOpen == bracClose && braceleft == braceright && leftp == rightp)
        {
            braceleft++;
        }
        else if (stk.top() == ']' && bracOpen == bracClose && braceleft > braceright && leftp == rightp)
        {
            braceright++;
        }
        else if (stk.top() == '{' && bracOpen == bracClose && braceleft == braceright && leftp == rightp)
        {
            leftp++;
        }
        else if (stk.top() == '}' && bracOpen == bracClose && braceleft == braceright && leftp > rightp)
        {
            rightp++;
        }

        stk.pop();
    }
    if (bracOpen == bracClose && leftp == rightp && braceleft == braceright)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}







void optimal()             // O(N)          S.C==0(N)
{
    stack<char> stk;
    string s;

    getline(cin, s);    // Input pura string lete hain, including spaces.

    for (char ch : s)
    {
        if (ch == '[' || ch == '(' || ch == '{')
        {
            stk.push(ch);    // Agar opening bracket hai toh stack mein daal do.
        }
        else if (ch == ']' || ch == ')' || ch == '}')
        {
            if (stk.empty()==1)    // Agar stack empty hai aur closing bracket aaya, toh invalid hai.
            {
                cout << "Invalid" << endl;
                return;
            }

            char top = stk.top();
            if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
            {
                stk.pop();    // Agar match hua toh stack se pop karo.
            }
            else
            {
                cout << "Invalid" << endl;
                return;
            }
        }
    }

    if (stk.empty())    // Agar stack khali hai toh string valid hai.
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;    // Agar stack mein kuch bacha hai toh invalid hai.
    }
}


 

int main()
{
    optimal();
    return 0;
}