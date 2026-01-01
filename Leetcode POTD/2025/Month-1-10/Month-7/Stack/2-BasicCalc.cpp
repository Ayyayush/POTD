#include <bits/stdc++.h>
using namespace std;

void better()
{
    // T.C. = O(N)               // Har character ek hi baar check hota hai
    // S.C. = O(N)               // Stack mein numbers store hote hain

    string s;                    // Input expression lo
    getline(cin, s);

    stack<int> numstk;           // Numbers stack banaya
    int n = s.size();
    int num = 0;                 // Current number banana hai
    char prev_op = '+';          // Pehla operator '+' maan ke chalo

    for (int i = 0; i <= n; i++)
    {
        if (i < n && isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');     // Multi-digit number banana
        }
        else if (i < n && s[i] == ' ')
        {
            continue;                          // Space ko ignore karo
        }
        else
        {
            // Yaha hum purana operator check karte hain
            if (prev_op == '+')
            {
                numstk.push(num);              // Agar + hai toh direct push karo
            }
            else if (prev_op == '-')
            {
                numstk.push(-num);             // Agar - hai toh minus sign ke saath push karo
            }
            else if (prev_op == '*')
            {
                int top = numstk.top(); numstk.pop();
                numstk.push(top * num);        // Agar * hai toh turant multiply karo aur replace karo
            }
            else if (prev_op == '/')
            {
                int top = numstk.top(); numstk.pop();
                numstk.push(top / num);        // Agar / hai toh turant divide karo aur replace karo
            }

            // Ab next operator ke liye prev_op update karo
            if (i < n) prev_op = s[i];

            // Next number banane ke liye reset karo
            num = 0;
        }
    }

    // Ab final answer banane ke liye stack mein jo bhi numbers hain unko add karo
    int result = 0;
    while (!numstk.empty())
    {
        result += numstk.top();
        numstk.pop();
    }

    cout << result << endl;   // Answer print karo

    /*
    ✅ Example 1:
       Input:  "3+5 / 2"
       Dry Run:
          3 push
          +5 push
          /2 → 5/2 = 2 → replace
          Stack: [3,2]
          Answer: 3+2 = 5

    ✅ Example 2:
       Input:  "14-3/2"
       Dry Run:
          14 push
          -3 push (-3)
          /2 → -3/2 = -1 → replace
          Stack: [14,-1]
          Answer: 14 + (-1) = 13
    */
}

int main()
{
    better();
    return 0;
}
