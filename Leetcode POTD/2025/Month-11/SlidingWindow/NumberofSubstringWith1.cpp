/******************************************************************************************
 *  PROBLEM: Number of Substrings With Consecutive 1s
 *  -------------------------------------------------------------------------------
 *  Tumhe ek binary string s diya gaya hai (sirf '0' aur '1').
 *  Tumhe count karna hai ki kitne substrings aise hai jisme saare characters '1' ho.
 *
 *  Example:
 *  s = "111"
 *  All 1-substrings:
 *      "1", "1", "1", "11", "11", "111"
 *  Total = 6
 *
 *  Example:
 *  s = "101"
 *  Valid:
 *      "1", "1"
 *  Total = 2
 *
 *  NOTE:
 *  Har consecutive 1s ka block apne andar multiple substrings banata hai.
 *
 *****************************************************************************************/


/************************************** APPROACH - 1 ****************************************
 *  Brute Force (Check every substring)
 *  ----------------------------------------------------
 *  IDEA:
 *  - Har index i se start karke har index j tak substring banao.
 *  - Jaise hi beech me '0' mil jaaye → break (kyunki '0' se beyond substring valid nahi).
 *  - Agar substring me sirf '1' hain → count++.
 *
 *  Example:
 *  s = "110"
 *
 *  i=0:
 *      "1"  (valid)
 *      "11" (valid)
 *      "110" → 0 mila → break
 *
 *  i=1:
 *      "1" (valid)
 *      "10" → 0 mila → break
 *
 *  T.C. = O(n²)
 *  S.C. = O(1)
 *********************************************************************************************/
class Solution_Brute {
public:
    int numSub(string s) {

        long long count = 0;
        const int M = 1e9 + 7;

        for (int i = 0; i < s.size(); i++) {

            bool allOne = true;   // substring abhi tak sirf '1' hai

            for (int j = i; j < s.size(); j++) {

                if (s[j] == '0') {
                    allOne = false;
                }

                if (!allOne) break;   // aage ka substring bhi invalid hoga

                count = (count + 1) % M;  // valid substring mila
            }
        }

        return count;
    }
};




/************************************** APPROACH - 2 ****************************************
 *  Maths Formula (Count blocks of consecutive 1s)
 *  ----------------------------------------------------
 *  IDEA:
 *      Agar consecutive 1s ka block length = L ho,
 *      toh valid substrings = L * (L + 1) / 2
 *
 *  Example:
 *  s = "110111"
 *
 *  Blocks:
 *      "11"       → L = 2 → 2*3/2 = 3
 *      "111"      → L = 3 → 3*4/2 = 6
 *
 *  Total = 9
 *
 *  T.C. = O(n)
 *  S.C. = O(1)
 *********************************************************************************************/
class Solution_Math {
public:
    const int M = 1e9+7;

    int numSub(string s) {

        long long result = 0;
        long long count1 = 0;

        for (char ch : s) {

            if (ch == '1') {
                count1++;   // consecutive 1s badh rahe
            }
            else {
                result = (result + count1 * (count1 + 1) / 2) % M;
                count1 = 0; // reset
            }
        }

        // Last block bhi add karna important hai
        result = (result + count1 * (count1 + 1) / 2) % M;

        return (int)result;
    }
};




/************************************** APPROACH - 3 ****************************************
 *  Optimized Running Addition (Best Method)
 *  ----------------------------------------------------
 *  IDEA:
 *      Jab bhi '1' dikhe → consecutive count badhao.
 *      Har naye '1' ka contribution add hota hai.
 *
 *  Example: "111"
 *
 *      char '1': count1=1 → +1
 *      char '1': count1=2 → +2
 *      char '1': count1=3 → +3
 *
 *  Total = 1+2+3 = 6
 *
 *  Yahi logic fastest hai.
 *
 *  T.C. = O(n)
 *  S.C. = O(1)
 *********************************************************************************************/
class Solution {
public:
    const int M = 1e9+7;

    int numSub(string s) {

        long long result = 0;
        long long count1 = 0;

        for (char ch : s) {

            if (ch == '1') {
                count1++;                       // consecutive 1s
                result = (result + count1) % M; // direct contribution
            }
            else {
                count1 = 0;                     // reset
            }
        }

        return (int)result;
    }
};
