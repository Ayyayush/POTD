#include <bits/stdc++.h>
using namespace std;

void brute()
{
    /*
    ! Approach : Binary → Decimal Conversion + Simulation
    ! Time Complexity  : O(n + steps)
    ! Space Complexity : O(1)

    NOTE:
    - This approach is not safe for large inputs because
      binary string length can be up to 500 bits.
    - long long cannot store such large numbers.
    */

    string s = "1101";                          // hardcoded input

    long long num = 0;
    int count = 0;

    for(auto ch : s)
    {
        num = num * 2 + (ch - '0');              // convert binary → decimal
    }

    while(num != 1)
    {
        if(num % 2 == 0)                         // even
        {
            num /= 2;
        }
        else                                     // odd
        {
            num += 1;
        }

        count++;
    }

    cout << "Steps : " << count << endl;
}



void better()
{
    /*
    ! Approach : Direct Simulation on Binary String
    ! Time Complexity  : O(n^2)
    ! Space Complexity : O(1)

    Idea:
    - If last bit = 0 → divide by 2 → remove last bit
    - If last bit = 1 → add 1 → simulate binary addition
    */

    string s = "1101";                          // hardcoded input

    int op = 0;

    while(s.length() > 1)
    {
        int n = s.length();

        if(s[n-1] == '0')
        {
            s.pop_back();                       // divide by 2
        }
        else
        {
            int i = n-1;

            while(i >= 0 && s[i] != '0')
            {
                s[i] = '0';                     // propagate carry
                i--;
            }

            if(i < 0)
            {
                s = '1' + s;
            }
            else
            {
                s[i] = '1';
            }
        }

        op++;
    }

    cout << "Steps : " << op << endl;
}





void optimal()
{
    /*
    ! Approach : Greedy + Carry Logic
    ! Time Complexity  : O(n)
    ! Space Complexity : O(1)

    Idea:
    - Traverse from right to left
    - Maintain carry
    - If bit + carry = odd → need +1 then /2 (2 operations)
    - If bit + carry = even → only /2 (1 operation)
     ye humne observe kiya 
    */

    string s = "1101";                          // hardcoded input

    int n = s.length();
    int op = 0;
    int carry = 0;

    for(int i = n-1; i >= 1; i--)
    {
        if(((s[i] - '0') + carry) % 2 == 1)     // odd
        {
            op += 2;
            carry = 1;
        }
        else
        {
            op += 1;
        }
    }

    op += carry;

    cout << "Steps : " << op << endl;
}

int main()
{
    brute();
    better();
    optimal();
    return 0;
}


/*
! Optimal JavaScript Version

function numSteps(s)
{
    let op = 0;
    let carry = 0;

    for(let i=s.length-1;i>0;i--)
    {
        if((Number(s[i]) + carry) % 2 === 1)
        {
            op += 2;
            carry = 1;
        }
        else
        {
            op += 1;
        }
    }

    return op + carry;
}

-----------------------------------------------------

! Optimal Python Version

def numSteps(s):

    op = 0
    carry = 0

    for i in range(len(s)-1,0,-1):

        if (int(s[i]) + carry) % 2 == 1:
            op += 2
            carry = 1
        else:
            op += 1

    return op + carry
*/