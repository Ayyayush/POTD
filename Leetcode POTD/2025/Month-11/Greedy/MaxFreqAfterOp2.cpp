#include <bits/stdc++.h>
using namespace std;

/**
 * 🔹 Maximum Element After Operation - Part 2
 * --------------------------------------------------------
 * Part 1 wala code sahi chal raha tha lekin ek major problem thi —
 * waha humne ek **frequency array** liya tha jiska size `max(nums) + k` tak tha.
 * 
 * ⚠️ Problem:
 * Agar `max(nums)` = 10^9 ho, toh utna bada freq array lena impossible hai (Memory Limit Exceeded).
 * 
 * --------------------------------------------------------
 * 🧠 Intuition:
 * Hume har number ke aas-paas ke range [num - k, num + k] mein dekhna hai
 * ki us number ko target banana possible hai ya nahi.
 * 
 * Agar hum har number ke liye ye range mark kar dein (start and end), 
 * toh hum prefix sum ke concept se pata kar sakte hain 
 * ki har point par kitne numbers influence kar rahe hain.
 * 
 * Iske liye hum **Difference Array Technique** use karte hain.
 * 
 * --------------------------------------------------------
 * 🔍 Example:
 * nums = {5, 11, 20, 20},   k = 5,   numOperations = 2
 * 
 * Har element ke liye range:
 * - 5  → [0, 10]
 * - 11 → [6, 16]
 * - 20 → [15, 25]
 * - 20 → [15, 25]
 * 
 * Ab hum difference array mein:
 * diff[range_start]++  and diff[range_end + 1]--
 * 
 * Ye karne se jab hum prefix sum nikalte hain,
 * toh har position pe hume milta hai — 
 * “Kitne numbers us position ko apne range ke andar cover kar rahe hain”.
 * 
 * --------------------------------------------------------
 * 🔧 Phir hum:
 * - current `target` ka freq nikalte hain (kitne already target hain)
 * - aur dekhte hain kitne aur convert kiye ja sakte hain (numOperations ke limit tak)
 * 
 * --------------------------------------------------------
 * 🧩 Approach Summary:
 * - Use map<int,int> diff → sorted order cumulative ranges ke liye
 * - Use unordered_map<int,int> freq → exact freq of each number
 * - Traverse map in sorted order → build prefix sum
 * - Update result using possible conversions
 * 
 * --------------------------------------------------------
 * ✅ Approach - Using Difference Array Technique
 * ⏱️ Time Complexity: O(n log n)
 * 🧠 Space Complexity: O(n)
 */

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        int maxVal = *max_element(begin(nums), end(nums)) + k;     // max possible reachable value

        map<int, int> diff;                                        // to store difference array in sorted order
        unordered_map<int, int> freq;                              // to store exact frequency of elements

        // ---------------------------------------
        // Step 1: Build frequency and difference map
        // ---------------------------------------
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;                                       // count of each number

            int l = max(nums[i] - k, 0);                           // left boundary of its range
            int r = min(nums[i] + k, maxVal);                      // right boundary of its range

            diff[l]++;                                             // mark range start
            diff[r + 1]--;                                         // mark range end

            diff[nums[i]] += 0;                                    // ensure current number exists in map
        }

        // ---------------------------------------
        // Step 2: Traverse map to compute prefix sum
        // ---------------------------------------
        int result = 1;                                            // minimum frequency at least 1
        int cumSum = 0;                                            // cumulative prefix sum

        for (auto it = diff.begin(); it != diff.end(); it++) {
            int target = it->first;                                // current target value (key in map)
            it->second += cumSum;                                  // convert diff array → prefix sum value

            int targetFreq = freq[target];                         // freq of this exact number
            int needConversion = it->second - targetFreq;           // how many nearby nums can be converted

            int maxPossibleFreq = min(needConversion, numOperations); // we can convert up to numOperations

            // max frequency achievable for this target
            result = max(result, targetFreq + maxPossibleFreq);     

            cumSum = it->second;                                   // update cumulative sum for next iteration
        }

        return result;                                             // return maximum frequency possible
    }
};
