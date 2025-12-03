/*
 * GfG Link: https://www.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1
 *
 * Case-specific Sorting of Strings
 *
 * Difficulty: Medium Accuracy: 69.88% Submissions: 62K+ Points: 4 Average Time: 45m
 *
 * Given a string s consisting of only uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.
 *
 * Examples :
 *
 * Input: s = "GEekS"
 * Output: EGekS
 * Explanation: Sorted form of given string with the same case of character will result in output as EGekS.
 *
 * Input: s = "XWMSPQ"
 * Output: MPQSWX
 * Explanation: Since all characters are of the same case We can simply perform a sorting operation on the entire string.
 *
 * Constraints:
 * 1 ≤ s.length() ≤ 10^5
 */

/************************************************************ C++ ************************************************/

// Approach 1: Separate lowercase and uppercase letters, sort each group, then rebuild the string by choosing from the appropriate sorted group based on the original character’s case.
// Time Complexity: O(n + k log k) where n = length of s, k is roughly n/2 for each group; overall dominated by sorting at O(n log n).
// Space Complexity: O(n) extra space for the two buckets storing characters.
class Solution {
public:
    string caseSort(string& s) {
        int n = s.length();

        vector<char> lower;  // to hold all lowercase letters
        vector<char> upper;  // to hold all uppercase letters

        // 1) Partition into lowercase and uppercase buckets
        for (char ch : s) {
            if (islower(ch)) {
                lower.push_back(ch);
            } else {
                upper.push_back(ch);
            }
        }

        // 2) Sort both buckets independently
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());

        // 3) Reconstruct result by consuming from sorted buckets
        string result = s;  // initialize result with original size
        int    l      = 0;  // index for lowercase bucket
        int    u      = 0;  // index for uppercase bucket

        for (int i = 0; i < n; i++) {
            if (islower(s[i])) {
                result[i] = lower[l++];  // place next sorted lowercase
            } else {
                result[i] = upper[u++];  // place next sorted uppercase
            }
        }

        return result;
    }
};

/*
 *
 * Dry Run
 *
 * Input: s = "dCbA"
 *
 * Step 1: Partition
 *   lower = ['d','b']
 *   upper = ['C','A']
 *
 * Step 2: Sort buckets
 *   lower -> ['b','d']
 *   upper -> ['A','C']
 *
 * Step 3: Reconstruct result
 *   i=0: s[0]='d' is lower -> result[0] = lower[0] = 'b'
 *   i=1: s[1]='C' is upper -> result[1] = upper[0] = 'A'
 *   i=2: s[2]='b' is lower -> result[2] = lower[1] = 'd'
 *   i=3: s[3]='A' is upper -> result[3] = upper[1] = 'C'
 *
 * Final result = "bAdC"
 */

// Approach 2: Count lowercase and uppercase letters using fixed-size frequency arrays, then rebuild the string by picking the next available character from the corresponding frequency array in order.
// Time Complexity: O(n + 26) ⇒ O(n), where n = length of s.
// Space Complexity: O(1) extra space for two fixed-size arrays of length 26.

class Solution {
public:
    string caseSort(string& s) {
        int n = s.size();

        int lower[26] = { 0 };
        int upper[26] = { 0 };

        // 1) Count frequencies
        for (char ch : s) {
            if (islower(ch)) {
                lower[ch - 'a']++;
            } else {
                upper[ch - 'A']++;
            }
        }

        // 2) Reconstruct result by consuming counts
        string result = s;
        int    l      = 0; // index for lowercase freq array
        int    u      = 0; // index for uppercase freq array

        for (int i = 0; i < n; i++) {
            if (islower(s[i])) {
                while (lower[l] == 0) {
                    l++;
                }
                result[i] = 'a' + l;
                lower[l]--;
            } else {
                while (upper[u] == 0) {
                    u++;
                }
                result[i] = 'A' + u;
                upper[u]--;
            }
        }

        return result;
    }
};

