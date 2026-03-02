#include <bits/stdc++.h>
using namespace std;

void brute()
{
    /*
    ! Problem: Concatenation of Consecutive Binary Numbers
    ! Approach: String Simulation (Binary Conversion + Concatenation)

    Convert every number from 1 → n into binary
    Append the binary strings
    Convert the final binary string into decimal
    */

    // ! Time Complexity: O(n log n)
    // ! Space Complexity: O(n log n)

    int n = 12;                         // Hardcoded input
    const int MOD = 1000000007;

    string result = "";

    for(int i = 1; i <= n; i++)
    {
        int num = i;
        string binary = "";

        while(num)
        {
            binary.push_back((num % 2) + '0');      // Extract bit
            num /= 2;
        }

        reverse(binary.begin(), binary.end());      // Correct order
        result += binary;                           // Concatenate
    }

    long long ans = 0;

    for(char bit : result)
    {
        ans = (ans * 2 + (bit - '0')) % MOD;        // Binary → decimal
    }

    cout << ans << endl;
}

void better()
{

}

void optimal()
{
    /*
    ! Approach: Bit Manipulation + Left Shift

    Instead of building the binary string,
    we directly shift the current answer.

    Idea:
    When a new number i comes,
    we shift ans left by number of bits in i
    and add i.

    ans = (ans << bits) | i

    Example:
    n = 3

    1 -> 1
    ans = 1

    2 -> 10
    ans = (1 << 2) + 2 = 110

    3 -> 11
    ans = (110 << 2) + 3 = 11011
    */

    // ! Time Complexity: O(n)
    // ! Space Complexity: O(1)

    int n = 12;                         // Hardcoded input
    const int MOD = 1000000007;

    long long ans = 0;
    int bitLength = 0;

    for(int i = 1; i <= n; i++)
    {
        // Check if i is power of 2
        if((i & (i - 1)) == 0)
        {
            bitLength++;                // Bit length increases
        }

        ans = ((ans << bitLength) + i) % MOD;   // Shift and append
    }

    cout << ans << endl;
}

int main()
{
    brute();
    optimal();

    return 0;
}

/*
! Optimal Approach in JavaScript

let ans = 0n
let MOD = 1000000007n
let bitLen = 0n

for(let i = 1n; i <= n; i++)
{
    if((i & (i-1n)) === 0n) bitLen++

    ans = ((ans << bitLen) + i) % MOD
}


! Optimal Approach in Python

MOD = 10**9 + 7
ans = 0
bitLen = 0

for i in range(1, n+1):

    if (i & (i-1)) == 0:
        bitLen += 1

    ans = ((ans << bitLen) + i) % MOD
*/