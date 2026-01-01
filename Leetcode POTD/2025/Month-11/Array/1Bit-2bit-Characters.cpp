/**
 * I 1bit and 2bit Characters
 *
 * APPROACH: Greedy Traversal
 * -----------------------------------------
 * Problem Explanation (Hinglish):
 * - Agar bit 0 ho → ye ek 1-bit character represent karta hai (single character).
 * - Agar bit 1 ho → ye 2-bit character ka start hota hai 
 *   Example: 10 ya 11   (ye ek single 2-bit character maanta hai)
 *
 * Hume check karna hai ki LAST bit (array ka last element)
 * ek 1-bit character hai ya nahi.
 *
 * Logic:
 * - Array ko left se right traverse karenge.
 * - Agar current element 1 hai → 2-bit character hai → pointer +2
 * - Agar element 0 hai → 1-bit character → pointer +1
 * - Agar traversal ke end pe pointer LAST index par aata hai → last character 1-bit tha → return true
 *
 * TIME COMPLEXITY: O(n)       //// single traversal
 * SPACE COMPLEXITY: O(1)      //// no extra space
 */

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();                                   // total bits ka size
        int i = 0;                                             // pointer traversal ke liye

        while(i < n - 1) {                                     // last se ek pehle tak traverse
            if(bits[i] == 1) {
                i += 2;                                        // agar 1 → ye 2-bit char -> next 2 skip
            } else {
                i += 1;                                        // agar 0 → ye 1-bit char -> next 1 skip
            }
        }

        return (i == n - 1);                                   // agar pointer last index pe hai -> last char 1-bit tha
    }
};
