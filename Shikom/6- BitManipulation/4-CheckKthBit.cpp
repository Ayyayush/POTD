#include <bits/stdc++.h>
using namespace std;

/*
🟩 PROBLEM: Check if the K-th bit of number n is set (1) or not.
*/


/*---------------------------------------------------------
                    🟦 BRUTE FORCE APPROACH
  Approach: Convert number to binary string and check k-th bit
  Time Complexity: O(log n)
  Space Complexity: O(log n)     // storing binary
---------------------------------------------------------*/
void brute()
{
    long long n, k;
    cin >> n >> k;

    string bin = "";
    long long temp = n;

    while (temp > 0)
    {
        bin += char((temp % 2) + '0');   // append bit ('0' or '1')
        temp /= 2;
    }

    // bin is reversed (LSB first), so index k is correct
    if (k < bin.size() && bin[k] == '1')
        cout << "SET\n";
    else
        cout << "NOT SET\n";
}


/*---------------------------------------------------------
                    🟦 BETTER APPROACH
  Approach Name: Repeated Division  
  Logic: Extract bits until we reach k-th bit  
  Time Complexity: O(k)
  Space Complexity: O(1)
---------------------------------------------------------*/
void better()
{
    long long n, k;
    cin >> n >> k;

    long long steps = k;
    while (steps--)
    {
        n /= 2;        // right shift by division
    }

    if (n % 2 == 1)
        cout << "SET\n";
    else
        cout << "NOT SET\n";
}


/*---------------------------------------------------------
                    🟩 OPTIMAL APPROACH 1
  Approach Name: Bit Masking  
  Logic: Check if (n & (1 << k)) is non-zero  
  Time Complexity: O(1)
  Space Complexity: O(1)
---------------------------------------------------------*/
void optimal()
{
    long long n, k;
    cin >> n >> k;

    long long mask = 1LL << k;      // create mask for k-th bit

    if (n & mask)
        cout << "SET\n";
    else
        cout << "NOT SET\n";
}


/*---------------------------------------------------------
                    🟩 OPTIMAL APPROACH 2
  Approach Name: Right Shift Method  
  Logic: Shift right k times → check LSB  
  Time Complexity: O(1)
  Space Complexity: O(1)
---------------------------------------------------------*/
void optimal2()
{
    long long n, k;
    cin >> n >> k;

    long long shifted = n >> k;     // bring k-th bit to LSB

    if (shifted & 1)
        cout << "SET\n";
    else
        cout << "NOT SET\n";
}


int main()
{
    return 0;
}
