#include <bits/stdc++.h>
using namespace std;

/**
 * Maximum frequency of an element after performing operations 
 * 
 * nums[i] mein -k se k ke beech koi number add kr skte h 
 * total operations given limit tak hi ho skte h 
 * 
 *! Example 1:
 * nums = {1,4,5}   k = 1   numOps = 2
 * -k to k == -1, 0, 1 
 * exactly 2 operations 
 * nums[1] = 4 + 1 = 5 
 * ab 5 ki freq ho gayi 2 
 * maxfreq = 2 
 * 
 *! Example 2:
 * nums = {5,11,20,20}   k = 1   numOps = 1
 * 20 + 0 → 1 operation ho gaya
 * chahe 5 ya 11 pe bhi operation kr skte h, par total 1 hi operation allowed
 * 20 ki maxfreq = 2
 * 
 *! Example 3:
 * nums = {1,7,13,13,17}   k = 5   numOps = 2
 * maan lo no == a 
 * koi bhi number which falls in the range of a-k to a+k 
 * it can be easily converted to a
 * 
 *! Observation 1:
 * eg: a = 7  k = 2 
 * a-k == 5   a+k == 9 
 * ye dono number ke beech mein koi bhi number easily 7 banaya ja sakta h 
 * jaise 5,6,7,8,9 
 * ab jitne numOps allow krenge utne 7 bana skte h 
 * baaki maxfreq = 7 ki
 * 
 *! Observation 2:
 * It is always better to choose an element having max freq jo already exist krta ho nums mein
 * 
 * eg: nums = {1,7,13,13,17}   k = 5   ops = 2
 * agar 17 choose kare → 13,13 ko 17 banaya → total 2 ops → maxfreq = 3
 * 
 * agar 13 choose kare → 13,13,17 → range [8,18] → totalcount = 3, countOf13 = 2, needConversion = 1
 * sirf ek 17 ko 13 bna diya → operations = 1 → quota full krne ke liye kisi pe +0 bhi add kr skte h
 * 
 *! One more example:
 * nums = {1,7,13,13,17,17,17,17}   k = 5   numOps = 2
 * total count in range = 6
 * count of 13 = 2
 * needConversion = 6 - 2 = 4 
 * numOps = 2 h par required 4 → possible nahi 
 * toh requiredOps = min(numOps, required)
 * sirf 2 hi 17 ko 13 bana payenge → maxfreq = 4
 * 
 * par agar hum reverse kr dein (13 ko 17 bana dein)
 * toh maxfreq = 6 mil sakta h
 * 
 *! Conclusion:
 * Ab challenge yeh h ki har target ko try krna padega 
 * → 0(n²) lag jayega 
 * → large constraints me feasible nahi
 * 
 *! Improving the solution:
 * hum freq array le lenge aur prefix sum nikal lenge 
 * taaki cumsum[r] - cumsum[l-1] → directly bata de kitne number [l,r] range me hain.
 * 
 * Example:
 * nums = {1,7,13,13,17,17,17,17}
 * k = 5
 * prefix array banake hum quickly count nikal sakte h:
 * cumsum[8,18] = cumsum[18] - cumsum[7] = 6 
 * 
 * targetcount = cumsum[target] - cumsum[target - 1]
 * 
 */

//----------------------------------------------//
// 🧩 BRUTE FORCE APPROACH
//----------------------------------------------//
/*
🔹 Approach:
Har element ko target maan ke check kar lenge ki 
kitne elements [target - k, target + k] range me aate hain.
Then calculate how many conversions are needed.

🔹 Time Complexity: O(n²)
🔹 Space Complexity: O(1)
*/

void brute() {
    vector<int> nums = {1, 7, 13, 13, 17};    // Example input
    int k = 5;                                // Allowed range ±k
    int numOps = 2;                           // Max operations allowed
    int n = nums.size();
    int result = 0;                           // Stores max frequency

    // Iterate through each number as target
    for (int i = 0; i < n; i++) {
        int target = nums[i];                 // Current target number
        int totalCountInRange = 0;            // Numbers within [target-k, target+k]
        int countOfTarget = 0;                // Count of target itself

        // Check for all numbers in nums
        for (int j = 0; j < n; j++) {
            if (nums[j] >= target - k && nums[j] <= target + k)
                totalCountInRange++;          // This number can be converted into target

            if (nums[j] == target)
                countOfTarget++;              // Already target h
        }

        int needConversion = totalCountInRange - countOfTarget;     // Kitne convert karne padenge
        int possible = countOfTarget + min(needConversion, numOps); // Limited by numOps
        result = max(result, possible);                             // Update max freq
    }

    cout << "Brute Result = " << result << endl;
}

//----------------------------------------------//
// 🚀 OPTIMAL APPROACH (Prefix Sum + Range Count)
//----------------------------------------------//
/*
🔹 Approach:
Instead of checking every pair (O(n²)), 
we use prefix sum of frequency array to count how many numbers 
fall within [target - k, target + k] efficiently.

🔹 Time Complexity: O(maxElement)
🔹 Space Complexity: O(maxElement)
*/

void optimal() {
    vector<int> nums = {1, 7, 13, 13, 17};    // Example input
    int k = 5;                                // Allowed range
    int numOperations = 2;                    // Max operations allowed

    // Step 1: Maximum element + k (to avoid overflow in freq)
    int maxEl = *max_element(nums.begin(), nums.end()) + k;
    vector<int> freq(maxEl + 1, 0);           // Frequency array

    // Step 2: Fill frequency
    for (int &num : nums) {
        freq[num]++;
    }

    // Step 3: Build cumulative prefix sum
    for (int i = 1; i <= maxEl; i++) {
        freq[i] += freq[i - 1];               // Prefix sum cumulative freq
    }

    int result = 0;                           // Store max possible frequency

    // Step 4: Iterate over possible target values
    for (int target = 0; target <= maxEl; target++) {

        if (freq[target] == 0)
            continue;                         // Skip non-existing numbers

        int leftNum = max(0, target - k);     // Lower limit of range
        int rightNum = min(maxEl, target + k);// Upper limit (boundary safe)

        // Total numbers in [target - k, target + k]
        int totalCount = freq[rightNum] - (leftNum > 0 ? freq[leftNum - 1] : 0);

        // Count of target itself
        int targetCount = freq[target] - (target > 0 ? freq[target - 1] : 0);

        // Required conversions to make all equal to target
        int needConversion = totalCount - targetCount;

        // Max possible freq after allowed conversions
        int maxPossibleFreq = targetCount + min(needConversion, numOperations);

        result = max(result, maxPossibleFreq); // Update answer
    }

    cout << "Optimal Result = " << result << endl;
}

//----------------------------------------------//
int main() {
    brute();      // Run brute approach
    optimal();    // Run optimal approach
    return 0;
}
