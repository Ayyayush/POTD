#include <bits/stdc++.h>
using namespace std;

/*
🟩 PROBLEM: Count Set Bits (Hamming Weight)
*/


/*---------------------------------------------------------
                    🟦 BRUTE FORCE APPROACH
  Approach: Convert number to binary string and count '1'
  Time Complexity: O(log n)
  Space Complexity: O(log n)        // storing binary string
---------------------------------------------------------*/
void brute()
{
    long long n;
    cin >> n;                                   // input

    string bin = "";                            // build binary form
    while (n > 0)
    {
        bin += to_string(n % 2);                // append last bit
        n /= 2;
    }

    int countSetBits = 0;
    for (char c : bin)
    {
        if (c == '1') countSetBits++;
    }

    cout << countSetBits << "\n";
}


/*---------------------------------------------------------
                    🟦 BETTER APPROACH
  Approach Name: Check Each Bit Manually
  Logic: Repeatedly divide by 2 and check remainder
  Time Complexity: O(log n)
  Space Complexity: O(1)
---------------------------------------------------------*/
void better()
{
    long long n;
    cin >> n;

    int countSetBits = 0;

    while (n > 0)
    {
        if (n % 2 == 1) countSetBits++;         // check last bit
        n /= 2;                                 // shift right
    }

    cout << countSetBits << "\n";
}


/*---------------------------------------------------------
                    🟩 OPTIMAL APPROACH
  Approach Name: Brian Kernighan’s Algorithm  
  Logic: n & (n - 1) removes the lowest set bit each time
  Time Complexity: O(number of set bits)
  Space Complexity: O(1)
---------------------------------------------------------*/
void optimal()
{
    long long n;
    cin >> n;

    int countSetBits = 0;

    while (n > 0)
    {
        n = n & (n - 1);                         // removes 1 set bit
        countSetBits++;
    }

    cout << countSetBits << "\n";
}


int main()
{
    return 0;
}
