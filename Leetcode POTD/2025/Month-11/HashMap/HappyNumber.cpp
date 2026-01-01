/**
 * 🧠 Problem: Happy Number
 * 
 * Ek number "happy" tab kehlata hai jab:
 *   - Agar hum uske har digit ka square lekar repeatedly sum karte hain,
 *     toh eventually result 1 ban jaata hai.
 * 
 * Agar yeh process kabhi 1 tak nahi pahunchti aur ek cycle me fass jaati hai,
 * toh wo number "unhappy" hota hai.
 * 
 * 💡 Example:
 *   n = 19
 *   1² + 9² = 82
 *   8² + 2² = 68
 *   6² + 8² = 100
 *   1² + 0² + 0² = 1 ✅ (Happy number)
 * 
 *   n = 2
 *   2² = 4
 *   4² = 16
 *   1² + 6² = 37
 *   3² + 7² = 58
 *   5² + 8² = 89
 *   8² + 9² = 145
 *   1² + 4² + 5² = 42
 *   4² + 2² = 20
 *   2² + 0² = 4 (cycle repeat ho gaya ❌ — not happy)
 */


// 🧩 Approach 1 (Naive iterative approach)
class Solution {
public:
    bool isHappy(int n) {
        long long sum = n;                                       // current number ko sum variable me store kiya
        
        while (sum != 1) {                                       // jab tak sum 1 nahi ban jata tab tak process chalayenge
            if (sum > 1 && sum <= 3)                             // agar sum 2 ya 3 ho gaya toh cycle repeat hone wali hai (unhappy)
                break;

            int num = sum;                                       // current number ko num me store kiya
            int digitsum = 0;                                    // digits ke square ka sum nikalne ke liye variable

            while (num) {                                        // number ke sabhi digits pe loop
                int rem = num % 10;                              // last digit nikali
                digitsum += (rem * rem);                         // uska square add kiya
                num /= 10;                                       // last digit hata di
            }

            sum = digitsum;                                      // sum update kiya digitsum ke equal
        }

        return sum == 1;                                         // agar final result 1 hai -> happy number ✅
    }
};



/**
 * 🧩 Approach 2 (Optimal — HashSet / Cycle Detection)
 * 
 * Idea:
 *   Kabhi kabhi square-sum calculation ek loop me chali jaati hai.
 *   Jaise: 37 → 58 → 89 → 145 → 42 → 20 → 4 → 16 → 37 (loop ❌)
 * 
 *   Isko detect karne ke liye hum ek `unordered_set` use karte hain.
 *   Har nayi value ko hash set me daalte hain.
 *   Agar koi number repeat ho gaya => cycle detected => unhappy number.
 * 
 *   Agar 1 mil gaya => happy number ✅
 * 
 * 🔹 Time Complexity: O(log n) average
 * 🔹 Space Complexity: O(log n) (hash set)
 */

 
class SolutionOptimal {
public:

    // helper function — ek number ke digits ke square ka sum nikalta hai
    int getSquareSum(int num) {
        int sum = 0;
        while (num > 0) {
            int digit = num % 10;                                // last digit nikali
            sum += (digit * digit);                              // square add kiya
            num /= 10;                                           // digit remove
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;                                 // already seen numbers ka set
        
        while (n != 1 && seen.find(n) == seen.end()) {           // jab tak n 1 nahi hota aur repeat nahi hota
            seen.insert(n);                                      // current number ko mark kar diya
            n = getSquareSum(n);                                 // square-sum update kar diya
        }

        return n == 1;                                           // agar n == 1 => happy ✅ else unhappy ❌
    }
};


/**
 * ✅ Dry Run (Optimal approach)
 * 
 * Input: n = 19
 * 
 * Step 1: seen = {}
 * n = 19 → (1² + 9² = 82)
 * seen = {19}
 * 
 * Step 2: n = 82 → (8² + 2² = 68)
 * seen = {19, 82}
 * 
 * Step 3: n = 68 → (6² + 8² = 100)
 * seen = {19, 82, 68}
 * 
 * Step 4: n = 100 → (1² + 0² + 0² = 1)
 * ✅ 1 mil gaya → return true (Happy Number)
 */

