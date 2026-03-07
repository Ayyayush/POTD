/**
 * Leetcode 1888
 * Min no of flips to make the binary string alternating
 * Company Tags: Amazon, Google, etc.
 *
 * ! Problem Description ::
 *
 * You are given a binary string s.
 *
 * You can perform two types of operations:
 *
 * Type 1:
 * Remove the first character of the string and append it to the end.
 * (This is basically a rotation of the string)
 *
 * Type 2:
 * Pick any index i and flip the character
 * ('0' becomes '1' and '1' becomes '0')
 *
 * Goal:
 * Return the minimum number of flips required to make the string alternating.
 *
 * Alternating string examples:
 * 010101
 * 101010
 *
 *
 * ! Thought Process
 *
 * Brute Force Idea:
 *
 * iss problem ka sabse bada catch ye h ki output hum guess kr skte h
 * kyunki string alternating hona chahiye.
 *
 * Alternating string ke sirf 2 possible patterns hote hain:
 *
 * Pattern 1 : 010101...
 * Pattern 2 : 101010...
 *
 *
 * Abhi ke liye ye krte h ki Type 1 ko bhul jao
 * Samjho ki bas Type 2 operation h.
 *
 * Matlab:
 * String ko alternating banana h using only flips.
 *
 *
 * Example:
 *
 * s = 111000
 *
 * Agar hum alternating pattern "101010" banaye:
 *
 * Index : 0 1 2 3 4 5
 * s     : 1 1 1 0 0 0
 * exp   : 1 0 1 0 1 0
 *
 * mismatch at index 1 and 4
 *
 * flips = 2
 *
 * Toh answer ho gaya 2.
 *
 *
 * Agar dusra pattern use kare:
 *
 * exp = 010101
 *
 * flips = 3
 *
 * Toh hum minimum return karenge.
 *
 *
 * Ab problem mein kaha ki Type 1 (rotation) bhi use kar sakte h.
 *
 * Toh ab dekhte h isko use karne se kya hota h.
 *
 *
 * Example:
 *
 * s = 111000
 *
 * Rotation lagao:
 *
 * 111000
 * 110001
 * 100011
 * 000111
 * 001110
 * 011100
 * phir wapas original aa jayega
 *
 * Observe:
 *
 * Agar string length = n hai
 * toh maximum n rotations possible hain.
 *
 * Matlab:
 *
 * Har rotation ke baad hum check kar sakte hain
 * ki alternating banane ke liye kitne flips lagenge.
 *
 *
 * Problem:
 *
 * Har rotation pe new string banana costly ho jayega.
 *
 *
 * Trick (Very important for circular string problems):
 *
 * ! Generally circular string problems mein ye trick use hoti h
 *
 * Original string ko usi ke saath append kar do
 *
 * s = s + s
 *
 * Example:
 *
 * s = 111000
 *
 * appended string =
 *
 * 111000111000
 *
 * Ab jitni bhi rotations possible thi
 * wo sab is appended string ke andar
 * substring form mein mil jayengi.
 *
 *
 * Example windows (length = n):
 *
 * 111000
 * 110001
 * 100011
 * 000111
 * 001110
 * 011100
 *
 *
 * Ab hum sliding window use kar sakte hain.
 *
 *
 * Step 2:
 *
 * Do alternating reference strings bana lo:
 *
 * s1 = 1010101010....
 * s2 = 0101010101....
 *
 *
 * Ab appended string ke har window (length n)
 * ko s1 aur s2 se compare karenge.
 *
 *
 * Jo mismatches honge
 * wahi flips required honge.
 *
 *
 * Sliding Window Idea:
 *
 * Window size = n
 *
 * j -> window expand
 * i -> window shrink
 *
 * result1 = mismatches with s1
 * result2 = mismatches with s2
 *
 *
 * Har valid window pe:
 *
 * result = min(result, result1, result2)
 *
 *
 * Final answer = minimum flips.
 *
 */



/*************************************************************** C++ *************************************************/
//Approach-1 (Sliding Window + modifying input s = s+s)
//T.C : O(2*n) ~= O(n)
//S.C : O(2*n) for s1 and s2 and s+=s

class Solution {
public:
    int minFlips(string s) {

        int n = s.size();

        // make string circular by appending itself
        s += s;

        string s1, s2;

        /*
         * s1 = 101010...
         * s2 = 010101...
         *
         * these are the only two valid alternating patterns
         */

        for(int i = 0; i < 2*n; i++) {

            s1 += (i % 2 ? '0' : '1');
            s2 += (i % 2 ? '1' : '0');

        }

        int i = 0, j = 0;

        int result1 = 0;   // mismatches with s1
        int result2 = 0;   // mismatches with s2

        int result = INT_MAX;

        while(j < 2*n) {

            // expand window

            if(s[j] != s1[j])
                result1++;

            if(s[j] != s2[j])
                result2++;

            /*
             * shrink window if size exceeds n
             */

            if(j - i + 1 > n) {

                if(s[i] != s1[i])
                    result1--;

                if(s[i] != s2[i])
                    result2--;

                i++;

            }

            /*
             * when window size exactly n
             * we check minimum flips
             */

            if(j - i + 1 == n)
                result = min({result, result1, result2});

            j++;
        }

        return result;
    }
};


/**
 * Thought Process
 *
 * ! Better Approach
 *
 * Humne previous approach mein dekha ki humne
 * original string s ko modify karke
 *
 *      s = s + s
 *
 * kar diya tha taaki circular rotations handle ho sake.
 *
 * Lekin iss approach mein hum original string ko modify
 * nahi karenge.
 *
 *
 * Idea:
 *
 * Instead of actually appending the string,
 * hum circular indexing use karenge.
 *
 *
 * Example:
 *
 * s = "111000"
 * n = 6
 *
 * Normally rotation ke baad jo states milti hain:
 *
 * 111000
 * 110001
 * 100011
 * 000111
 * 001110
 * 011100
 *
 * Yeh sab states s+s string mein mil jaati thi.
 *
 *
 * Lekin iss approach mein hum direct circular access karenge:
 *
 * s[index % n]
 *
 * Isse index automatically wrap ho jayega.
 *
 *
 * Example:
 *
 * s = "111000"
 *
 * agar j = 7
 *
 * s[j % n] = s[7 % 6] = s[1]
 *
 * Matlab circular traversal ho gaya.
 *
 *
 * Step 1:
 *
 * Do reference alternating strings banayenge:
 *
 * s1 -> 1010101010...
 * s2 -> 0101010101...
 *
 * length = 2*n
 *
 *
 * Step 2:
 *
 * Sliding window use karenge
 *
 * window size = n
 *
 *
 * i -> window start
 * j -> window end
 *
 *
 * Window expand karte waqt:
 *
 * hum compare karenge
 *
 * s[j % n] with s1[j]
 * s[j % n] with s2[j]
 *
 *
 * Agar mismatch hua
 * toh flip count increase kar denge.
 *
 *
 * Window shrink karte waqt:
 *
 * hum mismatch subtract kar denge
 * jo window se bahar ja raha hai.
 *
 *
 * Again circular access:
 *
 * s[i % n]
 *
 *
 * Jab window size exactly n ho jaye
 * tab hum minimum flips update karenge.
 *
 *
 * Final answer = minimum flips required
 * among all rotations.
 *
 */


/*************************************************************** C++ *************************************************/
//Approach-2 (Sliding Window + without modifying input)
//T.C : O(2*n) ~= O(n)
//S.C : O(2*n) for s1 and s2

class Solution {
public:
    int minFlips(string s) {

        int n = s.size();

        string s1, s2;

        /*
         * s1 = 101010...
         * s2 = 010101...
         *
         * Ye dono possible alternating patterns hain.
         */

        for(int i = 0; i < 2*n; i++) {

            s1 += (i % 2 ? '0' : '1');
            s2 += (i % 2 ? '1' : '0');

        }

        int i = 0, j = 0;

        int result1 = 0;   // mismatches with s1
        int result2 = 0;   // mismatches with s2

        int result = INT_MAX;

        while(j < 2*n) {

            /*
             * Expand Window
             *
             * Instead of using s[j],
             * we use circular indexing:
             *
             * s[j % n]
             */

            if(s[j % n] != s1[j])
                result1++;

            if(s[j % n] != s2[j])
                result2++;

            /*
             * Shrink window if it becomes larger than n
             */

            if(j - i + 1 > n) {

                if(s[i % n] != s1[i])
                    result1--;

                if(s[i % n] != s2[i])
                    result2--;

                i++;

            }

            /*
             * If window size == n
             * update minimum flips
             */

            if(j - i + 1 == n)
                result = min({result, result1, result2});

            j++;
        }

        return result;
    }
};






/**
 * Thought process 
 * ! optimnal approach 
 * 
 * isme extra space lenge hi nhi 
 */

 
//Approach-3 (Sliding Window + without modifying input)
//T.C : O(2*n) ~= O(n)
//S.C : O(1)
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        //khandani sliding window
        int result = INT_MAX;
        int flip1 = 0;
        int flip2 = 0;

        int i = 0;
        int j = 0;

        while(j < 2*n) {

            char expectedCharS1 = (j%2) ? '1' : '0';
            char expectedCharS2 = (j%2) ? '0' : '1';

            if(s[j%n] != expectedCharS1) {
                flip1++;
            }

            if(s[j%n] != expectedCharS2) {
                flip2++;
            }

            if(j-i+1 > n) { //shrink the window from left
                expectedCharS1 = (i%2) ? '1' : '0';
                expectedCharS2 = (i%2) ? '0' : '1';

                if(s[i%n] != expectedCharS1) {
                    flip1--;
                }

                if(s[i%n] != expectedCharS2) {
                    flip2--;
                }

                i++;
            }

            if(j-i+1 == n) {
                result = min({result, flip1, flip2});
            }

            j++;

        }
        return result;
    }
};

