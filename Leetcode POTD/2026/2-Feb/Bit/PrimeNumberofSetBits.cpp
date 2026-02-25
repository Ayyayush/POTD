#include <bits/stdc++.h>
using namespace std;

/** how to proceed in interview
 * step -1: Observe that we need count of set bits for every number
 * step -2: For each number, check if set-bit count is prime
 * step -3: Use builtin popcount for efficiency
 */

/*
    Approach : Brute Force
    T.C      : O((R-L) * log N * sqrt(log N))
    S.C      : O(1)
*/
void brute()
{
    int left = 6, right = 10;                 // hardcoded input
    int cnt = 0;

    for(int i = left; i <= right; i++)
    {
        int setBits = 0;
        int num = i;

        while(num > 0)
        {
            setBits += (num & 1);
            num >>= 1;
        }

        if(setBits < 2) 
            continue;

        bool isPrime = true;
        for(int j = 2; j * j <= setBits; j++)
        {
            if(setBits % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if(isPrime)
            cnt++;
    }

    cout << "Count (Brute): " << cnt << endl;
}


/*
    Approach : Better
    T.C      : O((R-L) * sqrt(log N))
    S.C      : O(1)
*/
void better()
{
    int left = 6, right = 10;                 // hardcoded input
    int cnt = 0;

    for(int i = left; i <= right; i++)
    {
        int setBits = __builtin_popcount(i);

        if(setBits < 2) 
            continue;

        bool isPrime = true;
        for(int j = 2; j * j <= setBits; j++)
        {
            if(setBits % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if(isPrime)
            cnt++;
    }

    cout << "Count (Better): " << cnt << endl;
}


/*
    Approach : Optimal (Your class Solution logic)
    T.C      : O(R-L)
    S.C      : O(1)
*/
void optimal()
{
    int left = 6, right = 10;                 // hardcoded input
    int cnt = 0;

    auto checkprime = [&](int count) {
        if(count < 2) 
            return 0;

        for(int i = 2; i * i <= count; i++)
        {
            if(count % i == 0)
                return 0;
        }
        return 1;
    };

    for(int i = left; i <= right; i++)
    {
        int setBits = __builtin_popcount(i);
        cnt += checkprime(setBits);
    }

    cout << "Count (Optimal): " << cnt << endl;
}


int main()
{
    brute();
    better();
    optimal();

    return 0;
}


/**
 * JavaScript way of Optimal method
 *
 * var countPrimeSetBits = function(left, right) {
 *     function isPrime(n) {
 *         if(n < 2) return false;
 *         for(let i = 2; i * i <= n; i++) {
 *             if(n % i === 0) return false;
 *         }
 *         return true;
 *     }
 *
 *     let count = 0;
 *     for(let i = left; i <= right; i++) {
 *         let setBits = i.toString(2).split('1').length - 1;
 *         if(isPrime(setBits)) count++;
 *     }
 *     return count;
 * };
 */


/**
 * Python way of Optimal method
 *
 * def countPrimeSetBits(left, right):
 *     def isPrime(n):
 *         if n < 2:
 *             return False
 *         for i in range(2, int(n ** 0.5) + 1):
 *             if n % i == 0:
 *                 return False
 *         return True
 *
 *     count = 0
 *     for i in range(left, right + 1):
 *         if isPrime(bin(i).count('1')):
 *             count += 1
 *
 *     return count
 */