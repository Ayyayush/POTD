/**
 * ============================================================
 * Binary Watch Problem
 * ============================================================
 *
 * A binary watch displays time using LEDs.
 *
 * ➤ There are TOTAL 10 LEDs:
 *    - Top 4 LEDs  → represent HOURS
 *    - Bottom 6 LEDs → represent MINUTES
 *
 * ------------------------------------------------------------
 * HOW BINARY WATCH WORKS
 * ------------------------------------------------------------
 *
 * Each LED represents a power of 2.
 *
 * HOURS LEDs (4 bits):
 * [8, 4, 2, 1]  → max hour = 11
 *
 * MINUTES LEDs (6 bits):
 * [32, 16, 8, 4, 2, 1] → max minute = 59
 *
 * ------------------------------------------------------------
 * EXAMPLE 1
 * ------------------------------------------------------------
 *
 * Suppose LEDs ON are:
 * Hours:   0100
 * Minutes:000001
 *
 * Hour calculation:
 * 0*8 + 1*4 + 0*2 + 0*1 = 4
 *
 * Minute calculation:
 * 0*32 + 0*16 + 0*8 + 0*4 + 0*2 + 1*1 = 1
 *
 * ➤ Time = "4:01"
 *
 * ------------------------------------------------------------
 * IMPORTANT RULES
 * ------------------------------------------------------------
 *
 * 1️⃣ Hour range:
 *     - Must be between 0 and 11
 *
 * 2️⃣ Minute range:
 *     - Must be between 0 and 59
 *
 * 3️⃣ Leading zero rule:
 *     - Hour should NOT have leading zero
 *       ❌ "04:01"
 *       ✅ "4:01"
 *
 * 4️⃣ Minute formatting:
 *     - If minute < 10, add leading zero
 *       ❌ "4:1"
 *       ✅ "4:01"
 *
 * ------------------------------------------------------------
 * WHAT THE PROBLEM ASKS
 * ------------------------------------------------------------
 *
 * Given:
 * - An integer `turnedOn`
 * - It represents number of LEDs that are ON
 *
 * Task:
 * - Return ALL possible valid times the watch can display
 *
 * ------------------------------------------------------------
 * EXAMPLE 2
 * ------------------------------------------------------------
 *
 * Input:
 * turnedOn = 1
 *
 * Output:
 * [
 *   "0:01", "0:02", "0:04", "0:08",
 *   "0:16", "0:32", "1:00", "2:00",
 *   "4:00", "8:00"
 * ]
 *
 * ------------------------------------------------------------
 * KEY INTERVIEW INSIGHT
 * ------------------------------------------------------------
 *
 * - This problem is about:
 *   ✔ Bit manipulation
 *   ✔ Backtracking / Combinations
 *   ✔ Binary representation
 *
 * - Very common LeetCode interview question
 *
 * ============================================================
 */

 //Approach (Simple enumeration)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for (int HH = 0; HH <= 11; HH++) {

            for (int MM = 0; MM <= 59; MM++) {
                
                if (__builtin_popcount(HH) + __builtin_popcount(MM) == turnedOn) {
                    string hour   = to_string(HH);
                    string minute = (MM < 10 ? "0" : "") + to_string(MM);
                    
                    result.push_back(hour + ":" + minute);
                }
            }
        }
        return result;
    }
};



