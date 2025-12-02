

 /**
 * Longest Subarray with majority of the elements greater than k
 *
 * ❖ BRUTE FORCE:
 * - Hum har subarray ko nested loop ke through check karenge.
 * - Har subarray ke liye "greater than k" aur "less than or equal to k" elements count karenge.
 * - Agar "greater than k" elements ka count > "less than or equal to k" elements ke count se,
 *   toh ye subarray valid hai.
 * - Aise sab valid subarrays mein se maximum length nikal lo.
 * - Time Complexity: O(N^2)      → inefficient for large arrays.
 *
 *
 * ❖ BETTER / OPTIMAL:
 * 
 * 
 * Hume kuch naya tarika dhundna hoga 
 * maan lo array ko red aur green zone mein daal diya 
 * green > h
 * red < h 
 * toh maan lo jo bi green h 
 * wo count mein toh bas +1 ka fark daaal rhe h 
 * unki value kya h isse toh fark pad nhi rha na 
 * toh green ko +1 ki tarah treat krte h 
 * 
 * 
 * ab maan lo jo red zone wale elts h wo +1 ka fark daal rhe h less mein
 * ek tarike se -1 ka fark daal rhe h more wale mein
 * toh maan lo chalo usko -1 ki tarah treat krte h 
 * 
 * * eg :: 10,1,6,5,2,7,8,9    k=5
 * +4   aur -3  hua 
 * total sum hoga +1 
 * +1 yani green wale elts jyada h 
 * ab jis bhi subarray ka sum>1 h 
 * wo valid subarray h 
 * usse nikaal skte h largest subarray length 
 


 * 
 * 🔹 Observation:
 * - Kya zarurat hai actual values dekhne ki? 
 *   Sirf yeh dekhna hai element `k` se bada hai ya nahi.
 * - So hum array ko ek **transformed array** mein convert kar sakte hain:
 *     → agar arr[i] > k, toh usse **+1** count karo (Green zone)
 *     → agar arr[i] <= k, toh usse **-1** count karo (Red zone)
 *
 * 🔹 Eg: arr = [10,1,6,5,2,7,8,9],  k = 5
 *     Transformed:  [+1, -1, +1, -1, -1, +1, +1, +1]
 *     Prefix Sum:    1,  0,  1,  0, -1,  0,  1,  2
 * - Final sum = +2 → means "greater than k" elements are in majority
 *
 * 
 * 
 * 
 * 🔹 Idea:
 * - Har subarray ka sum nikalna hai.
 * - Agar kisi subarray ka sum > 0, toh usmein green elements (i.e., > k) zyada hain.
 * - Humein **longest subarray** chahiye jisme sum > 0 ho.
 *
 * 🔹 METHOD:
 * - At each index i, maintain `prefixSum` of the transformed array.
 * - Humein har index `i` ke liye longest subarray chahiye jiska sum > 0 ho.
 *
 * ───────
 * 🔹 CASE 1: prefixSum becomes POSITIVE (sum > 0)
 * - Iska matlab hai 0th index se lekar `i` tak ka sum > 0 hai.
 * - Directly length = i + 1 valid hai, usse maxLen update kar do.
 *
 * 🔹 CASE 2: prefixSum becomes NEGATIVE (sum < 0)
 * - Ab 0th index se lekar `i` tak ka sum invalid hai.
 * - Lekin ho sakta hai koi index `j` ho (j < i), jaha se lekar `i` tak ka sum > 0 ho.
 * - Humein aise index `j` dhundna hai jaha:
 *       prefixSum[j] < prefixSum[i] - 1
 *   (i.e., past position where total negative was more)
 *
 * 
 * 
 * 
 * ───────
 * 🔹 HOW TO FIND APT STARTING POINT?
 * (Referencing your image):
 * - Har prefix sum ko ek map mein store karo jisme:
 *       key   = prefixSum
 *       value = first index where this prefixSum occurred
 *
 * - Jab bhi current prefixSum aaye:
 *     → Check if (prefixSum - 1) exists in map
 *     → If yes, valid starting point mil gaya:
 *           length = i - map[prefixSum - 1]
 *           update maxLen accordingly
 *
 * - Is approach se hum har index ke liye maximum subarray length find kar sakte hain.
 *
 * 
 * 
 * 
 * 
 * 🔹 Why prefixSum - 1 ?
 * - Kyunki humein aise pehle index `j` chahiye jaha tak ka prefix sum aisa ho ki:
 *       prefixSum[i] - prefixSum[j] > 0
 *   → So rearranged:  prefixSum[j] < prefixSum[i]
 *   → But we want maximum such `j`, so we store earliest occurrence of prefixSum in map.
 *
 * 🔹 Final Approach:
 * - Transform array to +1/-1
 * - Track prefixSum
 * - Store earliest prefixSum occurrences in map
 * - Whenever prefixSum > 0 → full array from 0 is valid → update maxLen = i+1
 * - Else if (prefixSum - 1) exists in map → use that index to compute length
 *
 * 🔹 Time Complexity: O(N)
 * 🔹 Space Complexity: O(N)
 *
 * 
 * 
 * 
 */


 #include <bits/stdc++.h>
using namespace std;

void brute()
{
    // 🔸 Input lena
    vector<int> arr = {10, 1, 6, 5, 2, 7, 8, 9};
    int k = 5;

    int maxlength = 0;

    // 🔁 Har index se subarray start karenge
    for(int i = 0; i < arr.size(); i++) {
        int count = 0, less = 0, more = 0;

        // 🔁 Har index se lekar end tak subarray banayenge
        for(int j = i; j < arr.size(); j++) {
            count++;                                     // 🧮 Subarray length update
            if(arr[j] <= k) less++;                      // 📉 Count of elements ≤ k
            else more++;                                 // 📈 Count of elements > k

            if(more > less) {
                maxlength = max(count, maxlength);       // ✅ Valid subarray → update answer
            }
        }
    }

    // 🔸 Output dena
    cout << "Longest subarray length with majority elements > k is: " << maxlength << endl;
}


void optimal()
{
    // 🔸 Input
    vector<int> arr = {10, 1, 6, 5, 2, 7, 8, 9};
    int k = 5;

    // 🔸 Step 1: Transform array
    int n = arr.size();
    vector<int> transformed(n);
    for (int i = 0; i < n; i++) {
        if (arr[i] > k)
            transformed[i] = 1;             // ✅ Green zone → greater than k → +1
        else
            transformed[i] = -1;            // ✅ Red zone → less than or equal to k → -1
    }

    // 🔸 Step 2: Use prefix sum logic
    unordered_map<int, int> prefixIndex;    // prefixSum → earliest index
    int prefixSum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += transformed[i];        // ⚙️ Current prefix sum

        if (prefixSum > 0) {
            maxLength = i + 1;              // ✅ Entire subarray from 0 to i is valid
        } else {
            if (prefixIndex.find(prefixSum - 1) != prefixIndex.end()) {
                int len = i - prefixIndex[prefixSum - 1];     // 📍 Valid subarray found
                maxLength = max(maxLength, len);              // 🔄 Update maxLength
            }
        }

        // ⚠️ Store only first occurrence of prefixSum to maximize subarray length
        if (prefixIndex.find(prefixSum) == prefixIndex.end()) {
            prefixIndex[prefixSum] = i;
        }
    }

    // 🔸 Output result
    cout << "Longest subarray length with majority elements > k is: " << maxLength << endl;
}

int main()
{
    optimal();
    return 0;
}
