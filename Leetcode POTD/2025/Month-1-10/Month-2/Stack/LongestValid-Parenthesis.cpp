#include <bits/stdc++.h>
using namespace std;

void optimal() // O(N)          S.C==0(N)
{
    stack<char> stk;
    string s;

    getline(cin, s); // Input pura string lete hain, including spaces.
  int count=0;



    for (char ch : s)
    {

        if (ch == '[' || ch == '(' || ch == '{')
        {
            stk.push(ch); // Agar opening bracket hai toh stack mein daal do.
        }
        else if (ch == ']' || ch == ')' || ch == '}')
        {
            if (stk.empty() == 1) // Agar stack empty hai aur closing bracket aaya, toh invalid hai.
            {
                cout << "Invalid" << endl;
                stk.push(ch);
                ch++;
                
               
            }


            char top = stk.top();
             if (ch == ')' && top == '(')
            {
                count += 2;
                stk.pop(); // Agar match hua toh stack se pop karo.
            }
            else if (ch == '}' && top == '{')
            {
                count += 2;
                stk.pop(); // Agar match hua toh stack se pop karo.
            }
            else if (ch == ']' && top == '[')
            {
                count += 2;
                stk.pop(); // Agar match hua toh stack se pop karo.
            }
            else
            {
                cout << "Invalid" << endl;
              
            }
        }
       
    }

    if (stk.empty()) // Agar stack khali hai toh string valid hai.
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl; // Agar stack mein kuch bacha hai toh invalid hai.
    }

    cout<<count<<endl;
}

int main()
{
    optimal();
    return 0;
}