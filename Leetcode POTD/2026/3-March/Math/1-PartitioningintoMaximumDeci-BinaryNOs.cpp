/**
 * ! Problem: Partitioning Into Minimum Number of Deci-Binary Numbers
 * ! LeetCode 1689
 *
 * deci-binary number ka matlab:
 * number jisme sirf digits 0 ya 1 ho
 *
 * Example:
 * 101
 * 11
 * 10
 * 1
 *
 *
 * n ek string diya hua hai jo sirf digits se bana hai
 *
 *
 * ------------------------------------------------------------
 * Example
 *
 * n = 32
 *
 * hume aise deci-binary numbers find karne hain
 * jinko add karne par 32 ban jaye
 *
 * Example:
 *
 * 10
 * 11
 * 10
 * ----
 * 32
 *
 * yahan total 3 numbers use hue
 *
 * aur sabke digits sirf 0 ya 1 hain
 *
 *
 * ------------------------------------------------------------
 * ! Thought Process (Brute Force Thinking)
 *
 * beginner hone ke nate pehle brute force se samajhte hain
 *
 *
 * Example: n = 32
 *
 * deci-binary numbers kya kya ho sakte hain
 *
 * 1
 * 10
 * 11
 *
 * leading zero allowed nahi hai
 *
 *
 * ab main chahunga ki bada wala deci-binary number loon
 *
 * 10 aur 11 mein se 11 bada hai
 *
 *
 * step by step subtraction:
 *
 * 32 - 11 = 21
 * 21 - 11 = 10
 * 10 - 10 = 0
 *
 *
 * total operations = 3
 *
 *
 * ------------------------------------------------------------
 * ! Important Observation
 *
 * agar number ki length 2 hai
 *
 * toh sabse bada deci-binary number hoga:
 *
 * 11
 *
 * fir uske baad
 *
 * 10
 *
 * fir
 *
 * 1
 *
 *
 * ------------------------------------------------------------
 * Example: n = 57
 *
 * 57 - 11 = 46
 * 46 - 11 = 35
 * 35 - 11 = 24
 * 24 - 11 = 13
 * 13 - 11 = 2
 *
 * ab 2 ko banane ke liye
 *
 * 1
 * 1
 *
 *
 * total operations = 7
 *
 *
 * ------------------------------------------------------------
 * ! Trick samajhne ki koshish
 *
 * jab hum 11 subtract karte hain
 * toh dono digits ek ek karke kam ho rahe hote hain
 *
 * yani har subtraction mein har digit se 1 kam ho raha hai
 *
 *
 * iska matlab:
 *
 * jab tak sabse bada digit zero nahi hota
 * tab tak operations chalenge
 *
 *
 * Example:
 *
 * n = 57
 *
 * digits = [5 , 7]
 *
 * sabse bada digit = 7
 *
 * iska matlab hume 7 deci-binary numbers chahiye
 *
 *
 * ------------------------------------------------------------
 * ! FINAL TRICK
 *
 * answer = maximum digit in the number
 *
 *
 * Example:
 *
 * n = 32
 *
 * digits = [3 , 2]
 *
 * max digit = 3
 *
 * answer = 3
 *
 *
 * ------------------------------------------------------------
 * ! Approach: Greedy Observation
 *
 * ! Time Complexity: O(n)
 * ! Space Complexity: O(1)
 */



/**************************************************************** C++ ********************************************************************/


// Method-1 (This method explains why Method-2 trick worked)
// T.C : O(n * D), where D = max digit (≤9) ≈ O(n)
// S.C : O(1)

class Solution {
public:
    int minPartitions(string n) {

        int count = 0;

        while(true)
        {
            bool changed = false;

            for(char &ch : n)
            {
                if(ch != '0')
                {
                    ch--;             // har digit se 1 subtract kar rahe hain
                    changed = true;
                }
            }

            if(!changed)              // agar sab digits 0 ho gaye
                break;

            count++;
        }

        return count;
    }
};



// Method-2 (Optimized Observation)
// largest digit ko 0 hone mein jitna time lagega
// utne hi deci-binary numbers lagenge

// T.C : O(n)
// S.C : O(1)

class Solution {
public:
    int minPartitions(string n) {

        return *max_element(n.begin(), n.end()) - '0';

    }
};