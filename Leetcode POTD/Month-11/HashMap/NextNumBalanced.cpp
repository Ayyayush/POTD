#include <bits/stdc++.h>
using namespace std;

/**
 * Quote of the Day ::
 * Almost 80 to 90 % of the problems get resolved if you stick to it 
 * staying strong and not quitting 
 */


//////////////////////////////////////////////////////////////////
// Approach 1 : Brute Force
// T.C. ≈ O(10^7 * log10(n)) → worst case we iterate through all numbers and count digits
// S.C. = O(1) → only a map of size ≤ 10 is used
// Idea: Check each number one by one if it is a "special number" (or balanced number)
// A number is special if: each digit d occurs exactly d times
// Example: 
// 22 → digit 2 occurs twice ✅
// 121 → digit 1 occurs twice ❌ (fails condition)
//////////////////////////////////////////////////////////////////
void brute()
{
    int n = 1;                       // starting number
    long long ans = -1;               // to store final answer
    bool nextfound = true;            // flag to check valid number

    // loop from n+1 to a reasonable upper limit (1224444 is maximum possible balanced number)
    for (long long i = n + 1; i <= 1224444; i++)
    {
        long long x = i;
        unordered_map<long long, long long> mp; // store digit frequency

        // count frequency of each digit
        while (x)
        {
            int rem = x % 10; // extract last digit
            mp[rem]++;        // increment its count
            x /= 10;          // remove last digit
        }

        // check if every digit satisfies the "balanced" condition
        nextfound = true; // reset flag
        x = i;

        while (x)
        {
            int rem = x % 10;       // extract digit again
            if (mp[rem] != rem)     // check if frequency == digit
            {
                nextfound = false;  // condition fails
                break;              // stop checking this number
            }
            x /= 10;                // move to next digit
        }

        // if number satisfies the condition → this is the answer
        if (nextfound)
        {
            ans = i;
            break; // stop after finding first valid number
        }
    }

    cout << ans << endl; // print result
}



/**
 * Approach 2 : Precomputed List + Binary Search
 * T.C : O(log(n)) for binary search → practically O(1) as list is small
 * S.C : O(1) → list is precomputed and fixed
 * 
 * Idea: All "balanced numbers" up to 10^6 (or max possible) are precomputed.
 * For a given n, find the smallest number > n using upper_bound.
 * This is fast but not ideal for interviews as it relies on hardcoding.
 * 
 * Example:
 * n = 23
 * balancedList = {1, 22, 122, 212, 221, ...}
 * upper_bound(balancedList.begin(), balancedList.end(), 23) → 122
 */

class SolutionBinary {
public:
    vector<int> balancedList{
        1, 22, 122, 212, 221, 333, 1333, 3133, 3313,
        3331, 4444, 14444, 22333, 23233, 23323, 23332, 
        32233, 32323, 32332, 33223, 33232, 33322, 41444, 
        44144, 44414, 44441, 55555, 122333, 123233, 123323, 
        123332, 132233, 132323, 132332, 133223, 133232, 
        133322, 155555, 212333, 213233, 213323, 213332, 
        221333, 223133, 223313, 223331, 224444, 231233, 
        231323, 231332, 232133, 232313, 232331, 233123, 
        233132, 233213, 233231, 233312, 233321, 242444, 
        244244, 244424, 244442, 312233, 312323, 312332, 
        313223, 313232, 313322, 321233, 321323, 321332, 
        322133, 322313, 322331, 323123, 323132, 323213, 
        323231, 323312, 323321, 331223, 331232, 331322, 
        332123, 332132, 332213, 332231, 332312, 332321, 
        333122, 333212, 333221, 422444, 424244, 424424, 
        424442, 442244, 442424, 442442, 444224, 444242, 
        444422, 515555, 551555, 555155, 555515, 555551,
        666666, 1224444
    };

    int nextBeautifulNumber(int n) {
        return *upper_bound(begin(balancedList), end(balancedList), n);
    }
};



/***
 * Approach 3 : Backtracking / Digit Frequency
 * T.C : O(9^d), d = number of digits in n → each digit 1-9 can appear ≤ d times
 * S.C : O(1) → only small vector/map of size 10
 * 
 * Idea: Generate balanced numbers digit by digit using backtracking
 * Example: 
 * n = 120
 * Steps:
 * 1. Take digits vector = {1,2,3,4,5,6,7,8,9}
 * 2. Try forming numbers using allowed digit frequencies
 * 3. Start from smallest digits
 * 4. For example:
 *    - result = 0 → pick 1 → result = 1, reduce frequency of 1 by 1
 *    - pick 2 → result = 12, reduce frequency of 2 by 1
 *    - pick 2 again → result = 122 (valid as freq of 2 = 2)
 *    - check if 122 > n → yes → return 122
 */

class SolutionBacktrack {
public:
    vector<int> digitCount{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // backtrack function to generate numbers recursively
    int backtrack(int n, int curr, int count) {
        // base case: if we have placed all digits
        if(count == 0) {
            // check if current number is balanced
            for(int digit = 1; digit <= 9; digit++) {
                if(digitCount[digit] != 0 && digitCount[digit] != digit) {
                    return 0; // invalid
                }
            }
            return curr > n ? curr : 0; // valid and > n
        }

        int result = 0;

        // try all digits from 1 to 9
        for(int digit = 1; digit <= 9; digit++) {
            if(digitCount[digit] > 0 && digitCount[digit] <= count) {
                digitCount[digit]--; // use digit
                result = backtrack(n, curr*10 + digit, count-1); // recursive call
                digitCount[digit]++; // backtrack (restore frequency)
            }

            if(result != 0) {
                break; // found valid number, no need to continue
            }
        }

        return result;
    }

    int nextBeautifulNumber(int n) {
        int numDigits = to_string(n).length(); // start with number of digits in n

        int result = backtrack(n, 0, numDigits); // try numbers with same digits
        if(result == 0) {
            result = backtrack(n, 0, numDigits+1); // try with one extra digit
        }

        return result;
    }
};



int main()
{
    brute(); // call the brute function
    return 0;
}
