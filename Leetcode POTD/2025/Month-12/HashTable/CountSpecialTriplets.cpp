/**
 * Count Special Triplets 
 * -----------------------------------------------------------
 * What the problem says ⬇️
 * 
 * Humein ek array diya hai `nums`.
 * Humein count karna hai total number of triplets (i, j, k)
 * jisme:
 * 
 *      nums[i] + nums[k] = 2 * nums[j]
 * 
 * aur index condition:
 *      i < j < k
 * 
 * Yaani nums[j] ek "middle value" honi chahiye
 * jo i-th aur k-th value ke beech ka AVERAGE ho.
 * 
 * -----------------------------------------------------------
 * ! Example 1:
 * nums = [1, 2, 3]
 *
 * Possible triplet:
 *   i=1 (1), j=2 (2), k=3 (3)
 *
 * Check: 1 + 3 = 4
 *        2 * 2 = 4 ✓
 *
 * Total = 1 triplet
 * 
 * -----------------------------------------------------------
 * ! Example 2:
 * nums = [2, 4, 2, 4]
 *
 * Valid triplets:
 *   (2,4,6)? No → 6 is not present
 *   But:
 *      For j = 4 → we need nums[i] + nums[k] = 8
 *      Possible: (2,4,2) and (2,4,2) from different positions
 *
 * Total = 2 triplets
 * -----------------------------------------------------------
 */


/**************************************************************
 * Approach-1 (2-Pass using HashMaps) — Corrected Version
 * -----------------------------------------------------------
 * *Idea*
 * - Har element ko middle (j) maanenge.
 * - Left map prefix mei store karega: freq of nums[i].
 * - Right map suffix mei store karega: freq of nums[k].
 * 
 * - For each j:
 *       nums[i] + nums[k] = 2 * nums[j]
 *
 *       → nums[k] = 2*nums[j] - nums[i]
 *
 *   Yaani humein *each possible nums[i] ke liye* required nums[k] dhoondhna hai.
 *
 * Time Complexity  : O(n * log n) approx (due to iterating over mp_left keys)
 * Space Complexity : O(n)
 *
 * -----------------------------------------------------------
 * Example Working:
 *
 * nums = [1, 2, 3]
 *
 * j = 2 (value = 2)
 *   left = {1}
 *   right = {3}
 *
 *   For i=1:
 *        required_k = 2*2 - 1 = 3
 *        Exists in right? YES
 *
 * → 1 triplet found
 ************************************************************* */

class Solution {
public:
    int M = 1e9+7;

    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> mp_left;
        unordered_map<int, int> mp_right;

        int result = 0;

        for(int &num : nums) {
            mp_right[num]++;
        }

        for(int &num : nums) {
            mp_right[num]--;

            int left  = mp_left[num*2];
            int right = mp_right[num*2];

            result = (result + (1LL * left * right)) % M;

            mp_left[num]++;
        }

        return result;
    }
};




/**************************************************************
 * Approach-2 (Optimized: Using precomputed valid_i & valid_j)
 * -----------------------------------------------------------
 * *Idea*
 * - Triplet condition:
 *       nums[i] + nums[k] = 2 * nums[j]
 *
 *   Rewrite:
 *       nums[i] = nums[j] / 2     (only if nums[j] even)
 *       nums[k] = nums[j] * 2
 *
 * - So while iterating j:
 *      Step-1: count valid k
 *      Step-2: update j for future k
 *      Step-3: increase valid_i for future iterations
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(n)
 *
 * -----------------------------------------------------------
 * Example:
 * nums = [2, 4, 2, 4]
 *
 * j = 4:
 *    i must be: 4/2 = 2
 *    k must be: 4*2 = 8 (not found)
 *
 * j = 2:
 *    i must be: 1 (not found)
 *
 * Finally 2 valid triplets milte hain.
 *************************************************************/
class Solution2 {
public:
    int M = 1e9+7;

    int specialTriplets(vector<int>& nums) {
        unordered_map<int,long long> valid_i, valid_j;
        long long result = 0;

        for (int num : nums) {

            // STEP-1: treat this as 'k'
            if (num % 2 == 0) {
                result = (result + valid_j[num / 2]) % M;
            }

            // STEP-2: treat this as 'j'
            valid_j[num] = (valid_j[num] + valid_i[num * 2]) % M;

            // STEP-3: treat this as 'i'
            valid_i[num]++;
        }

        return result;
    }
};


/**************************************************************
 * Approach-3 (Frequency Array Method)
 * -----------------------------------------------------------
 * *Idea*
 * - Instead of maps, freq arrays use karte hain (fast lookup)
 * - Same logic as Approach-1 but faster.
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(maxValue)
 *
 * -----------------------------------------------------------
 * Example Flow:
 * nums = [1,2,3]
 *
 * rightFreq = freq of all numbers
 * leftFreq  = empty at start
 *
 * For j = 2:
 *   target = 4
 *   leftFreq[4] = 0
 *   rightFreq[4] = 0
 *
 * For j = 3:
 *   target = 6
 *   none found
 *
 * Final Output = 1
 *************************************************************/
class Solution3 {
public:

    long long countTriplets(const vector<int>& nums, int limit, const int MOD) {

        vector<int> right(limit + 1, 0), left(limit + 1, 0);

        for (int x : nums)
            right[x]++;

        long long ans = 0;

        for (int val : nums) {
            right[val]--;

            int target = val * 2;

            if (target <= limit) {
                ans = (ans + 1LL * left[target] * right[target]) % MOD;
            }

            left[val]++;
        }

        return ans;
    }

    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9+7;
        int mx = *max_element(nums.begin(), nums.end());
        return countTriplets(nums, mx * 2, MOD);
    }
};
