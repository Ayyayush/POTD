/**
 * Problem: Count the Number of Substrings With Dominant Ones
 *
 * Dominant Ones ka matlab:
 *      For any substring:
 *          (count_of_ones)^2 >= (count_of_zeroes)^2
 *
 * Since square dono non-negative values ka order maintain karta hai:
 *      (ones * ones) >= (zeros * zeros)
 *  ==> ones >= zeros
 *
 * Matlab simple rule:
 *      Substring tab valid hota hai jab usme jitne '1' hote hain 
 *      wo '0' se zyada ya barabar ho.
 *
 * Example 1:
 *      s = "101"
 *
 *      Substrings:
 *          "1"   -> ones=1, zeros=0 -> valid
 *          "10"  -> ones=1, zeros=1 -> valid
 *          "101" -> ones=2, zeros=1 -> valid
 *          "0"   -> ones=0, zeros=1 -> NOT valid
 *          "01"  -> ones=1, zeros=1 -> valid
 *          "1"   -> ones=1, zeros=0 -> valid
 *
 *      Total valid substrings = 5
 *
 * Example 2:
 *      s = "1100"
 *
 *      Valid substrings:
 *          "1", "1", "11"
 *          "110"  -> ones=2, zeros=1 -> valid
 *          "1100" -> ones=2, zeros=2 -> valid
 *          "10"   -> ones=1, zeros=1 -> valid
 *          "100"  -> ones=1, zeros=2 -> NOT valid
 *          "0", "0" -> invalid
 *
 *      Total valid = 6
 *
 *
 * Approach (Brute Force):
 *      Har possible substring (i...j) check karna.
 *
 * Time Complexity:  O(n^2)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int numberOfSubstrings(string s) {

        int count = 0;                     // final answer store karega
        int zero, one;                     // har substring ke zero/one count

        for (int i = 0; i < s.size(); i++) {

            one = 0;
            zero = 0;

            for (int j = i; j < s.size(); j++) {

                if (s[j] == '0')
                    zero++;
                else
                    one++;

                if (one >= (zero * zero))
                    count++;               // valid substring
            }
        }

        return count;
    }
};


/**
 * The above approach gives TLE.
 *
 * So we will be improving our approach.
 * TLE wale code ko dekhkar yeh samajh aata hai ki sabse slow kaam kya ho raha hai:
 *      — har index j ko ek-ek karke badhana.
 *
 * Dominant condition:
 *      zero * zero > one   → invalid
 *
 * Brute force me hum har j ko 1 step badhate hain.
 * But actually hume calculate kar sakte hain ki:
 *      "1s ko kitna increase hona padega taaki condition satisfy ho"
 *
 * Example:
 *      s = 0001111011
 *
 *      Substring: s[2..3]
 *         zeros = 2
 *         ones  = 0
 *
 *      Condition satisfy karne ke liye:
 *         ones >= 4 (2^2)
 *
 *      Kaunse index par ones 4 ho jayenge?
 *
 *      → index 6 tak (best case)
 *
 * Mathematically:
 *      needOne = (zero^2) - one
 *
 *      Toh j ko needOne steps jump kara do.
 *      Kyunki needOne se kam move karne ka koi fayda nahi.
 *
 * BUT… guaranteed nahi ki those jumps me 1 hi milenge.
 * Par j = j + needOne se kam se kam useless checks avoid ho jate hain.
 *
 *
 * Next Case:
 *      Jab substring me more 1s hain aur zero kam:
 *
 *      Condition:
 *          zero^2 <= one
 *
 *      If next index contains '0', zero++ ho jayega,
 *      isliye hume check karna padta hai ki:
 *
 *          zero + k <= sqrt(one)
 *
 *      Yani k steps aur safely move kar sakte hain.
 *
 */


 /**************************************************************** C++ ****************************************************************/
 // Approach (Improving the brute-force by skipping j whenever possible)
 // T.C : Worst case O(n^2), average ≈ O(n * sqrt(n))
 // S.C : O(n)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        vector<int> cumCountOne(n, 0);
        cumCountOne[0] = (s[0] == '1') ? 1 : 0;

        // Build prefix sum of ones
        for(int i = 1; i < n; i++) {
            cumCountOne[i] = cumCountOne[i-1] + (s[i] == '1' ? 1 : 0);
        }

        int result = 0;

        for(int i = 0; i < n; i++) {

            for(int j = i; j < n; j++) {

                int oneCount  = cumCountOne[j] - (i > 0 ? cumCountOne[i-1] : 0);
                int zeroCount = (j - i + 1) - oneCount;

                // CASE 1: Too many zeros → jump
                if ((zeroCount * zeroCount) > oneCount) {

                    int need = (zeroCount * zeroCount) - oneCount;
                    j += need - 1;   // skip useless positions
                }

                // CASE 2: Perfect equal (zero^2 == ones)
                else if ((zeroCount * zeroCount) == oneCount) {

                    result++;

                }
                // CASE 3: Already valid → try to maximize
                else {

                    result++;

                    int k = sqrt(oneCount) - zeroCount;
                    int next = j + k;

                    if (next >= n) {
                        result += (n - j - 1);
                        break;
                    } else {
                        result += k;
                    }

                    j = next;
                }
            }
        }

        return result;
    }
};
