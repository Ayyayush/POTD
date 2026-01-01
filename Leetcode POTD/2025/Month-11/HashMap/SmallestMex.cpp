#include <bits/stdc++.h>
using namespace std;

/**
 * Approach -1 
 * Simple set-based approach (fails on edge cases)
 * 
 * Intuition:
 * - Normalize numbers by adding value until positive
 * - Take modulo 'value' and store unique remainders
 * - Sort and check first missing integer
 * 
 * Limitation: Does not consider **frequency of remainders**, fails in some test cases
 * T.C: O(n log n) due to sorting
 * S.C: O(n)
 */
class SolutionSetBased
{
public:
    int findSmallestInteger(vector<int> &nums, int value)
    {
        unordered_set<int> st; // unique remainders store karne ke liye

        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] <= 0)
            {                     
                nums[i] += value; // negative number ko positive me convert karo
            }

            st.insert(nums[i] % value); // modulo value store karo
        }

        vector<int> result; // unique remainders ko vector me daalenge
        for (auto x : st)
        {
            result.push_back(x); 
        }

        sort(result.begin(), result.end()); // ascending order me sort karo

        for (int i = 0; i < result.size(); i++)
        {
            if (result[i] != i + 1) // agar index aur remainder match nahi karte
                return i + 1;       // missing integer return karo
        }

        return result.size(); // agar sab match hue, toh next integer missing
    }
};


/**
 * Approach -2 (Frequency-based modulo approach) ✅ Recommended
 * 
 * Intuition:
 * - Observation: kisi number ko +/- value operations se reduce karke
 *   hum uska remainder modulo 'value' tak le aa sakte hain
 * - Count frequency of each remainder in a map
 * - Start MEX = 0, keep using remainders if available
 * - First missing remainder → maximum MEX
 * 
 * Time Complexity: O(n)  → loop through nums + MEX incrementation
 * Space Complexity: O(value) → map stores at most 'value' remainders
 */
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mp; // store frequency of each remainder

        // Step 1: normalize numbers and count remainders
        for(int &num : nums) {
            int r = ((num % value) + value) % value; // normalization to [0,value-1]
            mp[r]++;
        }

        int MEX = 0; // minimum excluded integer

        // Step 2: increment MEX using available remainders
        while(mp[(MEX % value)] > 0) {
            mp[(MEX % value)]--; // use this remainder
            MEX++;
        }

        return MEX; // maximum MEX found
    }
};

/**
Dry Run Example:

nums = [1,-10,7,13,6,8], value = 5

Step 1: Normalize & Count Remainders
-1 %5 → 1 → count[1]=1
-10%5 → 0 → count[0]=1
7%5 → 2 → count[2]=1
13%5 → 3 → count[3]=1
6%5 → 1 → count[1]=2
8%5 → 3 → count[3]=2

count map: {0:1, 1:2, 2:1, 3:2}

Step 2: Find MEX
MEX=0 → count[0]>0 → use → count[0]=0 → MEX=1
MEX=1 → count[1]>0 → use → count[1]=1 → MEX=2
MEX=2 → count[2]>0 → use → count[2]=0 → MEX=3
MEX=3 → count[3]>0 → use → count[3]=1 → MEX=4
MEX=4 → count[4]=0 → stop → return 4 ✅
*/
