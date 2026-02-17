/**
 * ============================================================
 * Reverse Bits – LeetCode Problem
 * ============================================================
 *
 * Problem Statement:
 * Given a 32-bit unsigned integer n, reverse its binary bits
 * and return the decimal value of the reversed bits.
 *
 * IMPORTANT:
 * - Total bits are always 32
 * - Leading zero bits MUST be considered
 *
 * Example:
 * n = 57
 *
 * Binary (32-bit):
 * 00000000000000000000000000111001
 *
 * Reversed Bits:
 * 10011100000000000000000000000000
 *
 * Output:
 * 39
 *
 * ============================================================
 *
 * Why naive solution fails?
 * - Using `while(n > 0)` ignores leading zeros
 * - LeetCode expects reversal of ALL 32 bits
 *
 * ============================================================
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * ============================================================
 * BRUTE FORCE APPROACH (STRIVER FORMAT)
 * ============================================================
 *
 * Idea:
 * - Extract exactly 32 bits from the number
 * - Store bits in string form
 * - Convert reversed binary string back to decimal
 *
 * Steps:
 * 1. Loop 32 times and extract rightmost bit using (n & 1)
 * 2. Store extracted bits in a string
 * 3. Convert the binary string into decimal value
 *
 * Time Complexity : O(32)
 * Space Complexity: O(32)
 * ============================================================
 */
void brute(uint32_t n, uint32_t &ans)
{
    string binary = "";

    /*
     * Step 1: Extract exactly 32 bits
     */
    for (int i = 0; i < 32; i++)
    {
        binary += to_string(n & 1);
        n = n >> 1;
    }

    /*
     * Step 2: Convert binary string to decimal
     */
    ans = 0;
    uint32_t power = 1;

    for (int i = binary.length() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            ans += power;
        }
        power <<= 1;
    }
}

/**
 * ============================================================
 * BETTER / OPTIMIZED APPROACH (STRIVER FORMAT)
 * ============================================================
 *
 * Idea:
 * - Extract rightmost bit using (n & 1)
 * - Left shift answer and insert extracted bit
 *
 * Formula:
 * ans = (ans << 1) | (n & 1)
 *
 * Loop exactly 32 times
 *
 * Time Complexity : O(32)
 * Space Complexity: O(1)
 * ============================================================
 */
void better(uint32_t n, uint32_t &ans)
{
    ans = 0;

    /*
     * Process exactly 32 bits
     */
    for (int i = 0; i < 32; i++)
    {
        /*
         * Shift answer left and add rightmost bit of n
         */
        ans = (ans << 1) | (n & 1);

        /*
         * Shift n right to process next bit
         */
        n = n >> 1;
    }
}

/**
 * ============================================================
 * OPTIMAL APPROACH
 * ============================================================
 *
 * Same as better approach (bit manipulation)
 *
 * Time Complexity : O(32)
 * Space Complexity: O(1)
 * ============================================================
 */
void optimal(uint32_t n, uint32_t &ans)
{
    ans = 0;

    for (int i = 0; i < 32; i++)
    {
        ans = (ans << 1) | (n & 1);
        n >>= 1;
    }
}











int main()
{
    uint32_t n;
    cin >> n;

    uint32_t ans;

    // Call optimal approach
    optimal(n, ans);

    cout << ans;
    return 0;
}
