/**
 * Power of Three
 * ---------------
 * Question:
 * Given an integer n, return true if it is a power of three. Otherwise, return false.
 * 
 * Follow-up (Google Interview):
 *  - Can you solve it without using loops or recursion?
 * 
 * Understanding:
 * n is a power of three if:
 *    n = 3^k  for some integer k >= 0
 * 
 * Examples:
 *  Input: n = 27  → 27 = 3^3 → Output: true
 *  Input: n = 9   → 9 = 3^2  → Output: true
 *  Input: n = 45  → Not a power of 3 → Output: false
 */


/* ------------------------------------------------------
   Approach-1: Iterative Division
   ------------------------------------------------------
   Idea:
   - Jab tak n 3 se perfectly divisible hai, tab tak divide karte raho.
   - Agar final value 1 aa gayi → power of 3 hai.
   - Agar beech me divisible nahi hua → false.
   
   Time Complexity:  O(log₃(n))  -> Har step me n ko /3 karte hain
   Space Complexity: O(1)
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;   // Negative ya zero → false
        
        while (n % 3 == 0) {        // Jab tak divisible hai
            n /= 3;                 // n ko 3 se divide karte raho
        }
        
        return n == 1;              // Agar 1 bacha → true
    }
};
// Example:
// n = 27 → 27%3==0 → 9 → 9%3==0 → 3 → 3%3==0 → 1 → true
// n = 45 → 45%3==0 → 15 → 15%3 != 0 → false



/* ------------------------------------------------------
   Approach-2: Recursive Division
   ------------------------------------------------------
   Idea:
   - Same as iterative but recursion ka use.
   - Base cases:
       - n <= 0 → false
       - n == 1 → true
   - Recursive call:
       n%3 == 0 && isPowerOfThree(n/3)
   
   Time Complexity:  O(log₃(n))
   Space Complexity: O(log₃(n))  -> Recursive call stack
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;          // Negative ya zero → false
        if (n == 1) return true;           // Base case
        return n % 3 == 0 && isPowerOfThree(n / 3);
    }
};
// Example:
// isPowerOfThree(27) → 27%3==0 → isPowerOfThree(9)
// isPowerOfThree(9)  → 9%3==0  → isPowerOfThree(3)
// isPowerOfThree(3)  → 3%3==0  → isPowerOfThree(1) → true



/* ------------------------------------------------------
   Approach-3: Largest Power of 3 Check
   ------------------------------------------------------
   Idea:
   - 32-bit signed integer ka maximum power of 3: 3^19 = 1162261467
   - Agar n positive hai aur 1162261467 % n == 0 hai → n must be power of 3.
   - Kyunki power of 3 ke saare divisors bhi power of 3 hote hain.
   
   Time Complexity:  O(1)
   Space Complexity: O(1)
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;  
        // 1162261467 = 3^19 (largest power of 3 within 32-bit int range)
    }
};
// Example:
// n = 27 → 1162261467 % 27 == 0 → true
// n = 45 → 1162261467 % 45 != 0 → false



/* ------------------------------------------------------
   Approach-4: Using Logarithms
   ------------------------------------------------------
   Idea:
   - If n = 3^k, then log₃(n) = k (integer)
   - Using change of base formula:
        log₃(n) = log₁₀(n) / log₁₀(3)
   - Agar result integer hai → power of 3.
   
   Time Complexity:  O(1)
   Space Complexity: O(1)
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;    // Negative ya zero → false

        // Calculate log base 3 of n
        double logValue = log10(n) / log10(3);

        // Check if logValue is integer (floating-point precision ke liye safer check better hota hai)
        return logValue == (int)logValue;
    }
};
// Example:
// n = 27 → log10(27)/log10(3) = 3.0 → integer → true
// n = 28 → log10(28)/log10(3) ≈ 3.033 → not integer → false
