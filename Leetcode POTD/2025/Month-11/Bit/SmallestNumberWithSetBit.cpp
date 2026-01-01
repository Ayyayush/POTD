#include <bits/stdc++.h>
using namespace std;

void brute()
{
    /*
        🧠 Approach: Bit Counting (Brute Force)
        -------------------------------------------------
        - Har number ke liye total bits aur set bits count karo.
        - Agar total bits == set bits, wahi answer hai.
        - total bits = floor(log2(i)) + 1
        - set bits   = __builtin_popcount(i)
    */

    // 🔹 Time Complexity: O(1024 - n) ≈ O(1)
    // 🔹 Space Complexity: O(1)

    int n;
    cout << "Enter n: ";
    cin >> n;

    int ans = n + 1;                                    // assume next number initially
    for (int i = n; i <= 1024; i++)                     // loop till 1024
    {
        int total = floor(log2(i)) + 1;                 // total bits in binary
        int setbit = __builtin_popcount(i);             // count of 1s
        if (total == setbit)                            // agar equal hain to answer mil gaya
        {
            ans = i;
            break;
        }
    }

    cout << "Smallest number: " << ans << endl;
}


void better()
{
    /*
        🧠 Approach: Simple Observation (Next Power of 2 Trick)
        ----------------------------------------------------------
        - Agar koi number i power of 2 hota hai (e.g. 8 = 1000),
          to (i - 1) ek aisa number hota hai jisme saare bits 1 hote hain (7 = 111).
        - So hum n ke baad next power of 2 dhoondhte hain aur ans = i - 1 kar dete hain.
    */

    // 🔹 Time Complexity: O(log N)
    // 🔹 Space Complexity: O(1)

    int n;
    cout << "Enter n: ";
    cin >> n;

    int ans = n;
    for (int i = n + 1; i <= 1025; i++)                 // iterate till next power of 2 found
    {
        if ((i & (i - 1)) == 0)                         // agar i power of 2 hai
        {
            ans = i - 1;                                // one less gives all 1s
            break;
        }
    }

    cout << "Smallest number: " << ans << endl;
}


void optimal()
{
    /*
        🧠 Approach: Using Built-in Functions (Efficient Bit Ops)
        ----------------------------------------------------------
        - Binary observation: Agar total bits == set bits → all 1s.
        - Yaani next number jiska (i & (i+1)) == 0 ho, wahi answer.
        - Yeh approach ek hi pass mein efficiently solve karta hai.
    */

    // 🔹 Time Complexity: O(log N)
    // 🔹 Space Complexity: O(1)

    int n;
    cout << "Enter n: ";
    cin >> n;

    int ans = n;
    int nextPower = 1;

    while (nextPower <= n)                              // find next power of 2 greater than n
        nextPower <<= 1;                                // left shift = multiply by 2

    ans = nextPower - 1;                                // one less gives all bits 1

    cout << "Smallest number: " << ans << endl;
}


int main()
{
    cout << "---- Brute ----" << endl;
    brute();

    cout << "\n---- Better ----" << endl;
    better();

    cout << "\n---- Optimal ----" << endl;
    optimal();

    return 0;
}
 


class Solution:
    def smallestNumber(self, n: int) -> int:
        # Find the smallest number >= n which is of form 2^k - 1 (binary: all 1s)
        i = n
        while True:
            # Check if i is of form 2^k - 1: then (i & (i + 1)) == 0
            if (i & (i + 1)) == 0:   # complex line explained in comment
                return i
            i += 1
