/**
 * * MAXIMUM LENGTH OF VALID SUBSEQUENCES
 * 
 * Given an array or string, we are trying to find the **maximum length of a subsequence**
 * where for every pair of **adjacent elements**, the sum is **odd**.
 * 
 * eg: For numbers => [1, 2, 3, 4]
 *  - 1 + 2 = 3  → 3 % 2 == 1 ✅
 *  - 2 + 3 = 5  → 5 % 2 == 1 ✅
 *  - 3 + 4 = 7  → 7 % 2 == 1 ✅
 * 
 * **Key Rule**:
 *   ➤ Every adjacent pair's sum must be odd.
 *   ➤ So, (a[i] + a[i+1]) % 2 === 1
 * 
 * ----------------------------------------------------
 * BRUTE FORCE APPROACH:
 *   ➤ Generate all subsequences using subset method (2^N)
 *   ➤ Check each subsequence if all adjacent pairs give odd sum
 *   ➤ Time Complexity: O(2^N)
 * 
 * ----------------------------------------------------
 * BETTER: MATH BASED APPROACH
 * 
 * Reference set:
 *   sub = [a, d, f, g, h, l, n]
 *   Char values (assume ASCII or positional even/odd):
 *     a → even
 *     d → odd
 *     f → even
 *     g → even
 *     h → odd
 *     l → even
 *     n → odd
 * 
 * ➤ We analyze based on whether their **sum is even or odd**
 * ➤ If (sub[i] + sub[i+1]) % 2 == 0 → sum is even → both even or both odd
 * ➤ If (sub[i] + sub[i+1]) % 2 == 1 → sum is odd → one even, one odd
 * 
 * 
 * -------------------------
 * TYPE 1 → sum % 2 == 0:
 * CASE 1:
 *   ➤ First two are both even → all must be even (like [a, f, g, l])
 * CASE 2:
 *   ➤ First two are both odd → all must be odd (like [d, h, n])
 * 
 * -------------------------
 * TYPE 2 → sum % 2 == 1:
 * CASE 1:
 *   ➤ First is even, second is odd → pattern must alternate (even → odd → even → odd…)
 * CASE 2:
 *   ➤ First is odd, second is even → pattern must alternate (odd → even → odd → even…)
 * 
 * 
 * ✨ In the image:
 *   ➤ (sub[0] + sub[1]) % 2 = 1 → [even + odd]
 *   ➤ (sub[1] + sub[2]) % 2 = 1 → [odd + even]
 *   ➤ (sub[2] + sub[3]) % 2 = 1 → [even + odd]
 *   ➤ So this sequence is valid as long as the alternating pattern continues.
 * 
 * Thus, only valid subsequences with alternating even-odd or full even/full odd will give
 * maximum length subsequences with required modulo condition
 * 
 * 
 * 3 CHZIEIN HI DHUNDNI H 
 * pick all even no's 
 * pick all odd no's 
 * alternating pairity numbers 
 * 
 * eg:: dryrun
 * 1,2,1,1,2,1,2
 *
 * even == 2,2,2,2
 * odd  == 1,1,1,1
 * alternate pairitiy == 1,2   2,1   1,2   2,1   1,2      == 1,2,1,2,1,2
 * 
 * alternate pairity se jyada length mil rha h 
 * alternate paairity mein dhyaan rakhna h abhi jo pairity mili h
 * next choose krne pe dusri pairity chahiye 
 * mtlb abhi odd mila h toh agla even lo 
 * 
 * 
 * ALTERNATING PAIRITY COUNT
 * pairity = sub[i]%2
 * if next  sub[i]%2   !=   pairity then count++
 * 
 * 
 * 
 */


 //T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int countEven = 0, countOdd = 0;
        for (int num : nums) {
            if (num % 2 == 0) countEven++;
            else countOdd++;
        }

        // Try building alternating parity subsequence
        int altLen = 1; // At least one number
        int prevParity = nums[0] % 2;

        for (int i = 1; i < nums.size(); ++i) {
            int currParity = nums[i] % 2;
            if (currParity != prevParity) {
                altLen++;
                prevParity = currParity;
            }
        }

        return max({countEven, countOdd, altLen});
    }
};
