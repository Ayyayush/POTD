/**
 * ✅ NINE DIVISORS PROBLEM
 * 
 * ❓ Problem Statement:
 * 0 se n ke beech aise numbers count karne hain jinke exactly **9 divisors** ho.
 *
 * ----------------------------------------------------------------
 * ✅ Brute Force Approach:
 * 🔁 Har ek number i (1 to n) ke liye uske total divisors count karo using loop.
 *    Agar divisors count == 9 ho toh answer increment karo.
 * 
 * 🔁 Inner loop chalega i tak, T.C => O(n * sqrt(n))
 * 
 * ❌ Very inefficient for n up to 10^6 or 10^7
 *
 * ----------------------------------------------------------------
 * ✅ Better Approach:
 * Fundamental Number Theory ka use karenge:
 * ➤ Kisi bhi number ko uske prime factor form mein likha ja sakta hai.
 *    For example: 36 = 2^2 * 3^2
 *
 * 🔢 Total number of divisors = (power1 + 1) * (power2 + 1) * ...
 *    Jaise 36 = 2^2 * 3^2 → Total divisors = (2+1) * (2+1) = 9 ✅
 *
 * ➤ So, humein un numbers ko count karna hai jinka divisor count formula 9 banata hai.
 *
 * ----------------------------------------------------------------
 * ✅ Mathematical Intuition:
 * 9 ke total divisors tabhi ban sakte hain jab prime powers ki form kuch iss tarah ho:
 *
 * 🔸 9 = 9 → (a^8)                    → Form: One prime raised to power 8
 * 🔸 9 = 3 * 3 → (a^2 * b^2)         → Form: Two distinct primes with power 2
 *
 * ➤ So only these 2 valid forms:
 *     1. p^8               (1 prime)
 *     2. p^2 * q^2         (2 distinct primes)
 *
 * ----------------------------------------------------------------
 * ✅ Algorithm:
 * 1. Generate all prime numbers up to sqrt(n) using sieve.
 * 2. Form numbers of type:
 *     a. p^8 <= n
 *     b. p^2 * q^2 <= n where p ≠ q
 * 3. Count all such valid numbers.
 *
 * ----------------------------------------------------------------
 * ✅ Optimal T.C = O(√n log log n) for sieve + O(n) for rest
 * ✅ Space = O(n) for sieve
 *
 * ----------------------------------------------------------------
 * ✅ What to Say in Interview:
 *
 * 🔸 "Instead of brute-force checking divisors for each number,
 *      I used number theory — the total number of divisors of a number
 *      is the product of (power + 1) of all prime powers.
 *      Only two combinations give 9 as result:
 *      one is p^8 (single prime) and another is p^2 * q^2 (two distinct primes).
 *      I used Sieve of Eratosthenes to generate primes efficiently up to √n,
 *      and then generated and counted numbers of those two forms that are ≤ n."
 * 
 */


 
class Solution {
public:

    // ✅ Function to count numbers from 1 to n having exactly 9 divisors
    int countNumbers(int n) {

        int count = 0;                                           // Final answer: count of numbers with exactly 9 divisors
        int limit = sqrt(n);                                     // Kyunki p^2 * q^2 ≤ n hona chahiye, toh upper limit √n tak sufficient hai

        vector<int> spf(limit + 1);                              // spf[i] => smallest prime factor of i
        iota(spf.begin(), spf.end(), 0);                         // Initially spf[i] = i

        // 🔸 Modified Sieve to fill smallest prime factors
        for (int i = 2; i * i <= limit; ++i)
        {
            if (spf[i] == i)                                     // Agar i ek prime hai
            {
                for (int j = i * i; j <= limit; j += i)
                {
                    if (spf[j] == j) spf[j] = i;                 // Mark smallest prime factor
                }
            }
        }

        // 🔸 Loop from 2 to sqrt(n) to handle all candidate bases
        for (int i = 2; i <= limit; ++i)
        {
            int p = spf[i];                                     // First prime factor of i
            int q = spf[i / p];                                 // Second prime factor of i

            // Case 1: i = p^2 * q^2 (i = p*q and p != q), means number = (p^2)*(q^2)
            // Total divisors = (2+1)*(2+1) = 9
            if (p * q == i && p != q && q != 1)
            {
                if (1LL * p * p * q * q <= n)                   // Check if p^2 * q^2 <= n
                    count++;
            }

            // Case 2: i is prime and i^8 <= n → number = p^8, divisors = (8+1) = 9
            else if (spf[i] == i)                               // i is a prime
            {
                if (pow(i, 8) <= n)                              // Check if i^8 ≤ n
                    count++;
            }
        }

        return count;
    }
};
