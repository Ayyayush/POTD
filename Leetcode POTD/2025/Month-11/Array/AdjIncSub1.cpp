class Solution {
public:
    // Helper function to check if subarray nums[start...end-1] is strictly increasing
    bool isIncreasing(vector<int>& nums, int start, int end) {                            
        /*
            Yaha hum ek helper function bana rahe hain jo check karega
            ki 'start' se 'end-1' tak ke elements strictly increasing hain ya nahi.

            Agar kahin bhi nums[i] <= nums[i-1] mila, iska matlab sequence
            increasing nahi hai → return false kar do.
        */
        for (int i = start + 1; i < end; i++) {                                           // iterate from start+1 to end-1
            if (nums[i] <= nums[i - 1])                                                   // agar koi bhi element apne pichle se chhota ya equal hai
                return false;                                                             // strictly increasing nahi hai
        }
        return true;                                                                      // agar poora loop safely traverse ho gaya toh sequence increasing hai
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {                               // main function to check if 2 increasing subarrays of length k exist
        int n = nums.size();                                                              // array size store kiya

        /*
            Idea:
            - Hume 2 consecutive subarrays of length 'k' find karne hain jo dono strictly increasing ho.
            - Isliye hum 'start' ko 0 se lekar n - 2*k tak iterate karenge,
              taaki dono subarrays ke liye jagah bache.
        */
        for (int start = 0; start + 2 * k <= n; start++) {                                // ensure hum array ke end se bahar na nikle
            bool firstInc = isIncreasing(nums, start, start + k);                         // pehla subarray check karo [start, start+k)
            bool secondInc = isIncreasing(nums, start + k, start + 2 * k);                // doosra subarray check karo [start+k, start+2*k)

            if (firstInc && secondInc)                                                    // agar dono increasing mil gaye
                return true;                                                              // return true kar do
        }
        return false;                                                                     // agar kahin bhi aisa nahi mila toh false
    }
};


/**
 * 🔹 Optimal Approach Explanation:
 * 
 * Ek hi traversal mein check karo ki array mein 2 consecutive increasing subarrays hain ya nahi.
 * 
 * Idea:
 * - Hum 2*k length ka ek window consider karte hain.
 * - Agar koi increasing run (consecutive strictly increasing elements) 
 *   aisi mil jaye jisme 2*k elements hain, toh obviously usme 2 subarrays of k length honge.
 * 
 * - Agar pichle run (prevRun) aur current run (currRun) dono >= k ho jaaye,
 *   matlab pichla increasing sequence khatam hua aur next bhi k length se zyada ka hai,
 *   toh bhi dono increasing subarrays mil gaye.
 * 
 * Ye O(n) mein ho jaata hai bina extra space ke.
 */


// Approach-2 (Optimal)
// 🕒 T.C. : O(n)
// 💾 S.C. : O(1)
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();                                                              // size of input array

        int currRun = 1;                                                                  // current increasing streak ka length
        int prevRun = 0;                                                                  // previous streak ka length store karega

        for (int i = 1; i < n; i++) {                                                     // traverse array
            if (nums[i] > nums[i - 1]) {                                                  // agar current element previous se bada hai
                currRun++;                                                                 // increasing streak continue karo
            } else {                                                                      // agar break ho gaya increasing order
                prevRun = currRun;                                                        // previous run store kar lo
                currRun = 1;                                                              // naya run start
            }

            if (currRun >= 2 * k) {                                                       // agar ek hi run itna bada mil gaya
                // matlab ek hi increasing sequence ke andar 2 subarrays of length k aa sakte hain
                return true;
            }

            if (min(currRun, prevRun) >= k) {                                             // agar dono consecutive runs atleast k length ke hain
                // matlab ek pichla subarray aur ek current subarray valid hain
                return true;
            }
        }

        return false;                                                                     // agar kahin bhi aisa na mila toh false
    }
};
