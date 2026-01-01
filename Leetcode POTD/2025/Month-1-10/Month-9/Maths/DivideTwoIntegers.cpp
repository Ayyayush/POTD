#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // ✅ Brute Force Approach: Use built-in division
    // T.C = O(1)        // C++ ka internal division operator use ho raha hai
    // S.C = O(1)

    int dividend = 10, divisor = 3;
    int rem = dividend / divisor;     // directly divide kar diya

    cout << rem << endl;
}

void better()
{
    // ✅ Better Approach: Bit manipulation with edge case handling
    // T.C = O(32) ≈ O(1)     // 32-bit integer shifting
    // S.C = O(1)

    int dividend = -2147483648;      // INT_MIN
    int divisor = -1;

    // Edge Case: Overflow if INT_MIN / -1
    if (dividend == INT_MIN && divisor == -1)
    {
        cout << INT_MAX << endl;
        return;
    }

    if (dividend == INT_MIN && divisor == 1)
    {
        cout << INT_MIN << endl;
        return;
    }

    // Determine sign of result
    bool isNegative = (dividend < 0) ^ (divisor < 0);     // XOR for sign

    // Convert to long long before taking absolute value to avoid overflow
    long long num = abs((long long)dividend);     // numerator
    long long den = abs((long long)divisor);      // denominator

    int quotient = 0;

    // Loop from 31 down to 0 bits
    for (int i = 31; i >= 0; i--)
    {
        if ((num >> i) >= den)
        {
            num -= (den << i);             // subtract (den * 2^i) from num
            quotient += (1 << i);          // add 2^i to result
        }
    }

    cout << (isNegative ? -quotient : quotient) << endl;
}
