/***
 * ! MIN TIME TO MAKE ROPE COLORFUL
 * ----------------------------------------------------------
 * 💡 Problem:
 * Hume ek string di gayi hai `colors` jisme har character ek balloon ka color represent karta hai.
 * Aur ek array `neededTime[]` diya gaya hai jisme har balloon ko burst karne me lagne wala time diya gaya hai.
 * 
 * 🎯 Goal:
 * Hume itna minimum time nikalna hai jisse koi bhi **do consecutive balloons** ek hi color ke na rahein.
 *
 * ----------------------------------------------------------
 * 🔹 Example 1:
 * colors = "a b a a c"
 * neededTime = [1, 2, 3, 4, 5]
 * 
 * Yahan last me "a a" consecutive hain.
 *  -> dono me se kam time (3) wala burst karenge.
 * ✅ Output = 3
 * 
 * ----------------------------------------------------------
 * 🔹 Example 2:
 * colors = "a a a b b b a b b b b"
 * neededTime = [3, 5, 10, 7, 5, 3, 5, 5, 4, 8, 1]
 * 
 * yahan multiple consecutive groups hain:
 *  "a a a"       -> remove min(3,5), min(5,10) => total 8
 *  "b b b"       -> remove min(7,5), min(5,3) => total 8 + 5 + 3 = 16
 *  "b b b b"     -> remove min(5,4), min(4,8), min(8,1) => total 16 + 4 + 4 + 1 = 25 ❌
 * Expected = 26 ✅
 *
 * (kyunki overlapping erase ke baad 1 removal miss ho gaya)
 * ----------------------------------------------------------
 * 🔹 Example 3:
 * colors = "a a a a a a a"
 * neededTime = [1, 2, 1, 5, 1, 1, 6]
 * 
 * Har balloon same color ka hai, sirf highest time wala (6) bachana hai.
 * Baaki sab remove karne ka total = 1 + 2 + 1 + 5 + 1 + 1 = 11 ✅
 * ----------------------------------------------------------
 *
 * 🧠 Approach 1 → Brute Force (Erase-based)
 * ----------------------------------------------------------
 * Har pair of consecutive balloons check karo.
 * Agar colors same hain, chhota time wala remove kar do (erase operation se).
 * Ye har baar shifting karega, isliye O(n²).
 * ----------------------------------------------------------
 * 🧮 T.C = O(n²)
 * 🧮 S.C = O(1)
 */

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;                                            // total cost store karega

        for (int i = 0; i < colors.size() - 1; i++) {            // loop har adjacent pair pe chalega
            if (colors[i] == colors[i + 1]) {                    // agar dono colors same hain

                if (neededTime[i] < neededTime[i + 1]) {         // agar left balloon ka time kam hai
                    cost += neededTime[i];                       // kam time wala burst kar denge
                    neededTime.erase(neededTime.begin() + i);    // vector se remove
                    colors.erase(i, 1);                          // string se remove
                } else {
                    cost += neededTime[i + 1];                   // agar right kam hai, usse remove
                    neededTime.erase(neededTime.begin() + i + 1);
                    colors.erase(i + 1, 1);
                }

                i--;                                             // erase ke baad position adjust karni hoti hai
            }
        }

        return cost;
    }
};

/**
 * ----------------------------------------------------------
 * 🔍 Dry Run (for brute-force)
 * ----------------------------------------------------------
 * Example: colors = "a a a b b b a b b b b"
 * neededTime = [3,5,10,7,5,3,5,5,4,8,1]
 * 
 * Step 1: i=0 → 'a','a' same → remove min(3,5)=3 → cost=3
 * Step 2: i=0 → 'a','a' again (5,10) → remove 5 → cost=8
 * Step 3: i=0 → 'a','b' different → skip
 * Step 4: i=1 → 'b','b' same (7,5) → remove 5 → cost=13
 * Step 5: i=1 → 'b','b' (7,3) → remove 3 → cost=16
 * Step 6: i=2 → 'a','b' diff → skip
 * Step 7: i=3 → 'b','b' (5,4) → remove 4 → cost=20
 * Step 8: i=3 → 'b','b' (5,8) → remove 5 → cost=25
 * Step 9: i=3 → 'b','b' (8,1) → remove 1 → cost=26 ✅ (Expected)
 *
 * ❌ But erase shifting causes missing case sometimes, so not stable.
 * ----------------------------------------------------------
 */



/**
 * ----------------------------------------------------------
 * ✅ Optimal Approach (Greedy Approach)
 * ----------------------------------------------------------
 * 🧠 IDEA:
 * 1️⃣ Har consecutive same color group me, sirf ek balloon rehna chahiye — jo burst karne me sabse zyada time leta hai.
 * 2️⃣ Baaki sabko burst kar do (add min times).
 * 3️⃣ Har baar `prevMax` me us color group ka maximum time store karte jao.
 * 
 * ----------------------------------------------------------
 * 🧮 T.C = O(n)
 * 🧮 S.C = O(1)
 * ----------------------------------------------------------
 * 
 * 🔹 Example 1:
 * colors = "a b a a c"
 * neededTime = [1, 2, 3, 4, 5]
 * 
 * Step 1: a,b → diff → prevMax=0
 * Step 2: b,a → diff → prevMax=0
 * Step 3: a,a → same → add min(3,4)=3
 * ✅ Total time = 3
 * ----------------------------------------------------------
 * 
 * 🔹 Example 2:
 * colors = "a a a b b b a b b b b"
 * neededTime = [3,5,10,7,5,3,5,5,4,8,1]
 * 
 * Group1 (a,a,a):  min(3,5)=3 + min(5,10)=5 → +8
 * Group2 (b,b,b):  min(7,5)=5 + min(7,3)=3 → +8 + 5 + 3 = 16
 * Group3 (b,b,b,b): min(5,4)=4 + min(5,8)=5 + min(8,1)=1 → +10
 * ✅ Total = 26
 * ----------------------------------------------------------
 * 
 * 🔹 Example 3:
 * colors = "a a a a a a a"
 * neededTime = [1,2,1,5,1,1,6]
 * 
 * Har group ek hi color ka hai:
 * Remove all except max (6)
 * Total time = 1+2+1+5+1+1 = 11 ✅
 * ----------------------------------------------------------
 */

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();                                   // total balloons
        int time = 0;                                            // total minimum cost
        int prevMax = 0;                                         // previous group me sabse max time balloon

        for (int i = 0; i < n; i++) {                            // har balloon traverse karenge

            if (i > 0 && colors[i] != colors[i - 1]) {           // agar color badal gaya
                prevMax = 0;                                     // reset prevMax (new group start)
            }

            int curr = neededTime[i];                            // current balloon ka burst time
            time += min(prevMax, curr);                          // chhota burst hoga, bada rakha jayega
            prevMax = max(prevMax, curr);                        // update max for this color group
        }

        return time;                                             // return final total time
    }
};
