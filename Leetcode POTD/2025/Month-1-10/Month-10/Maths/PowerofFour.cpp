#include <bits/stdc++.h>
using namespace std;

/**
 * Approach -1 
 * @brief Checks if a given number is a power of 4 using iterative division.
 *
 * This method repeatedly divides the number by 4 while it remains divisible.
 * If the result becomes 1, the number is a power of 4.
 *
 * @note
 * Example:
 *    n = 64 → 64 → 16 → 4 → 1 → returns true
 *    n = 20 → 20 → 5 → returns false
 *
 * @complexity
 * Time Complexity:  O(log₄(n))  (since we divide by 4 each step)
 * Space Complexity: O(1)        (no extra space used)
 */
void brute()
{
    int n;
    cin >> n; // Input number

    if (n <= 0)
    {
        cout << "false\n";
        return;
    }

    while (n > 1 && n % 4 == 0)
    {
        n /= 4;
    }

    cout << (n == 1 ? "true\n" : "false\n");
}

/**
 * Approach -2
 * @brief Checks if a given number is a power of 4 using logarithms.
 *
 * This method applies the formula:
 *      n = 4^x  ⇔  x = log₄(n) = log(n) / log(4)
 * If x is an integer (within floating-point precision), n is a power of 4.
 *
 * @note
 * Example:
 *    n = 64 → log(64)/log(4) = 3 → returns true
 *    n = 13 → log(13)/log(4) ≈ 1.85 → returns false
 *
 * @complexity
 * Time Complexity:  O(1)
 * Space Complexity: O(1)
 */
void better()
{
    int n;
    cin >> n; // Input number

    if (n <= 0)
    {
        cout << "false\n";
        return;
    }

    double x = log(n) / log(4); // Calculate log base 4 of n
    cout << (fabs(x - round(x)) < 1e-10 ? "true\n" : "false\n");
}

/**
 * Approach -3
 * Using maths and bitmagic
 * dekh lo power of 2 h ki nhi aur >=1 h na
 *
 * firr ab dekho
 * 8 power of 2 h 4 se divisble bhi h
 * but power of 4 nhi h
 * toh aise examples ke liye kuch trick lagana padega
 *
 * hum power of 2 mein n & n-1 isliye kr pate h kyunki
 * usme ek hi bit set hota h
 *
 *
 * Ab power of 4 ki properties dekhte h
 * 4 -1 ==3
 * 16-1 ==15
 * 64-1 ==63
 * so we see
 * 4 pow n -1   is always divisble by 3
 * (n-1)% 3==0
 *
 * Proof Induction
 * let for k  (4 pow k-1)%3 ==true
 * (k+1)=>  (4^k-1) => (4^k+1  -1)
 * (4^k.4)-1     -- use later
 * 4^k-1 == 3x
 * 4^k == 3x+1
 *
 * using now
 * (3x+1 .4)-1
 * (12x+4)-1
 * 12x + 3
 * 3(4x+1)
 * thus it is divisble by 3
 * aghar k ke liye valid h toh k+1 ke liye bhi valid h
 *
 *
 * T.C == O(1)
 * S.c == O(1)
 */

void optimal()
{
    int n;
    cin >> n; // Input number

    if (n <= 0)
        return false;
    if (n == 1)
        return true;

    return n % 4 == 0 && ((n) & (n - 1)) == 0 && (n - 1) % 3 == 0;
}
int main()
{
    brute();  // Iterative method
    better(); // Mathematical log method
    return 0;
}
