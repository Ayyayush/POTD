#include <bits/stdc++.h>
using namespace std;

/* ===================== BRUTE FORCE ===================== */
void brute()
{
    // APPROACH: Bit-by-Bit Comparison
    // Compare each bit of start and goal individually

    // TIME COMPLEXITY: O(32)  -> constant
    // SPACE COMPLEXITY: O(1)

    int start = 10;                 // sample input
    int goal  = 7;

    int count = 0;

    for (int i = 0; i < 32; i++)
    {
        if ((start & 1) != (goal & 1))
            count++;

        start >>= 1;
        goal  >>= 1;
    }

    cout << count;
}

/* ===================== BETTER ===================== */
void better()
{
    // APPROACH: Bit Manipulation using XOR
    // XOR highlights differing bits, then count set bits manually

    // TIME COMPLEXITY: O(32)  -> constant
    // SPACE COMPLEXITY: O(1)

    int start = 10;
    int goal  = 7;

    int x = start ^ goal;
    int count = 0;

    while (x > 0)
    {
        count += (x & 1);          // check last bit
        x >>= 1;                   // right shift
    }

    cout << count;
}

/* ===================== OPTIMAL ===================== */
void optimal()
{
    // APPROACH: Brian Kernighan’s Algorithm
    // Each operation removes the lowest set bit

    // TIME COMPLEXITY: O(number of set bits)
    // SPACE COMPLEXITY: O(1)

    int start = 10;
    int goal  = 7;

    int x = start ^ goal;
    int count = 0;

    while (x)
    {
        x = x & (x - 1);           // removes lowest set bit
        count++;
    }

    cout << count;
}

/* ===================== MOST CONCISE (BUILT-IN) ===================== */
void optimal_builtin()
{
    // APPROACH: XOR + Built-in Popcount
    // Directly count differing bits

    // TIME COMPLEXITY: O(1)
    // SPACE COMPLEXITY: O(1)

    int start = 10;
    int goal  = 7;

    cout << __builtin_popcount(start ^ goal);
}

int main()
{
    brute();
    cout << "\n";

    better();
    cout << "\n";

    optimal();
    cout << "\n";

    optimal_builtin();
    return 0;
}
