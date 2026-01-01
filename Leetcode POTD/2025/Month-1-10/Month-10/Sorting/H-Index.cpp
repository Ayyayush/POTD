
/**
 * H-Index (LeetCode 274)
 * -----------------------------------
 * Problem:
 *  - H-index ka matlab hai ek researcher ke research papers ka
 *    "impact factor" nikalna.
 *  - Agar kisi researcher ke `h` papers ke paas at least `h` citations hain,
 *    toh us researcher ka h-index = h hoga.
 *
 * Example:
 *  citations = [3, 0, 6, 1, 5]
 *  
 *  Step 1: Sort -> [0, 1, 3, 5, 6]
 *  Step 2: Check from right side:
 *      Paper with 6 citations → at least 1 paper ≥ 1 citation
 *      Paper with 5 citations → at least 2 papers ≥ 2 citations
 *      Paper with 3 citations → at least 3 papers ≥ 3 citations ✅
 *      Paper with 1 citation  → only 4 papers ≥ 4 citations ❌
 *  So H-index = 3
 *
 * Constraints:
 *  - H-index can never be greater than total number of papers (n).
 *  - Isliye agar koi citation n se bada hota hai,
 *    toh hum usse count karenge "n or more" ke bucket mein.
 *
 * Approach:
 *  1. Naya array (bucket) banayenge size = n+1, initially 0.
 *     Isme bucket[i] store karega "kitne papers ke paas i citations hain".
 *  2. Agar citation > n hai, toh usko bucket[n] mein daalenge.
 *  3. Ab hum peeche se traverse karenge (n to 0),
 *     aur cumulative count nikalenge ki "at least i citations wale kitne papers hain".
 *  4. Jis point pe cumulative_count >= i ho jaata hai,
 *     wahi answer hai.
 *
 * Time Complexity  : O(n)      (ek baar traverse + bucket fill)
 * Space Complexity : O(n)      (extra bucket array use hua hai)
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        // Step 1: Bucket banate hain size n+1
        vector<int> bucket(n + 1, 0);

        // Step 2: Fill bucket
        for (int c : citations) {
            if (c >= n) {
                bucket[n]++;               // agar citation >= n hai, last bucket mein daal do
            } else {
                bucket[c]++;               // warna apne value ke bucket mein daal do
            }
        }

        // Step 3: Traverse from back (n -> 0) for maximum h-index
        int count = 0;                      // count = at least i citations wale papers
        for (int i = n; i >= 0; i--) {
            count += bucket[i];             // cumulative count
            if (count >= i) {
                return i;                   // h-index mil gaya
            }
        }

        return 0; // fallback (yaha kabhi reach nhi karega)
    }
};
