#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////
// 💡 Problem: Count Trailing Zeroes in n! (Factorial of n)
// Approach 1️⃣: Brute Force (Compute factorial, then count trailing zeros)
//
// 🔹 Time Complexity: O(n²) approx   (because factorial grows very large → multiplication cost rises)
// 🔹 Space Complexity: O(1)
// ⚠️ Note: Works only for small n (since factorial quickly overflows)
//////////////////////////////////////////////////////////////////////////////////////////////////////
void brute()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    long long prod = 1;                       // factorial ko store karne ke liye
    int count = 0;                            // trailing zeros counter

    while (n >= 1)
    {
        prod *= n;                            // factorial multiply karte ja rahe hain
        n--;                                  // n ko decrease kar rahe hain
    }

    while (prod)                              // ab factorial ke end se zero count karte hain
    {
        int rem = prod % 10;                  // last digit nikalna
        if (rem == 0)
            count++;                          // agar 0 mila to count++
        else
            break;                            // jaise hi non-zero mila, stop (trailing zeros end)
        prod /= 10;                           // number ko ek digit chhota karo
    }

    cout << "Trailing Zeros (Brute): " << count << endl;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
// 💡 Approach 2️⃣: Better Approach (Count factors of 5 in n!)
// 🔹 Idea: Every trailing zero = 1 pair of (2 × 5)
//         → Count only factors of 5 (since 2s are more frequent)
//
// 🔹 Formula: count = n/5 + n/25 + n/125 + ...
//
// 🔹 Time Complexity: O(log₅ n)
// 🔹 Space Complexity: O(1)
// ✅ Works efficiently even for very large n (like 10⁹)
//////////////////////////////////////////////////////////////////////////////////////////////////////
void better()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int count = 0;

    for (int i = 5; i <= n; i *= 5)           // har power of 5 ke liye loop
    {
        count += (n / i);                     // kitne numbers 5,25,125,... se divisible hain
    }

    cout << "Trailing Zeros (Better): " << count << endl;
}


int main()
{
    brute();          // Brute force approach
    better();         // Better approach
    return 0;
}
