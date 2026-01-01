#include <bits/stdc++.h>
using namespace std;

/************************************************************
 * 🧠 Problem: H-Index
 * ----------------------------------------------------------
 * A researcher has published multiple papers.
 * Each paper has been cited a certain number of times.
 * 
 * The H-index is defined as:
 * ➤ The maximum value `h` such that the researcher has
 *    at least `h` papers with `≥ h` citations each.
 * 
 * 📘 Example 1:
 * Input:  citations = [3, 0, 6, 1, 5]
 * Step 1 → Sort in descending order → [6, 5, 3, 1, 0]
 * Step 2 → Check how many papers satisfy "citations ≥ index"
 * Paper 1: 6 ≥ 1 ✅
 * Paper 2: 5 ≥ 2 ✅
 * Paper 3: 3 ≥ 3 ✅
 * Paper 4: 1 ≥ 4 ❌
 * Paper 5: 0 ≥ 5 ❌
 * ✅ Hence, H-index = 3
 * 
 * 📘 Example 2:
 * Input:  citations = [1, 3, 1]
 * Sorted: [3, 1, 1]
 * Paper 1: 3 ≥ 1 ✅
 * Paper 2: 1 ≥ 2 ❌
 * Paper 3: 1 ≥ 3 ❌
 * ✅ Hence, H-index = 1
 * 
 * 
 * 
 * ----------------------------------------------------------
 * 🔹 Approach: Sorting Based (Greedy)
 * ----------------------------------------------------------
 * 1️⃣ Sort citations in descending order.
 * 2️⃣ Traverse and find the last position `i` where
 *     citations[i] >= i+1  (since index is 0-based).
 * 3️⃣ That position (i+1) is the H-index.
 * 
 * ----------------------------------------------------------
 * ⏱️ Time Complexity:  O(N log N)     (for sorting)
 * 💾 Space Complexity: O(1)           (in-place sort)
 ************************************************************/


 
 class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(),citations.rend());
        int count=0;
        for(int i=0;i<citations.size();i++)
        {
            if(citations[i]>=(i+1))
            count++;
        }
        
        return count;
    }
};





#include <bits/stdc++.h>
using namespace std;

/************************************************************
 * 🧠 Problem: H-Index
 * ----------------------------------------------------------
 * 📘 Approach - 2 : Using Bucket Sort
 * ----------------------------------------------------------
 * 💡 Idea:
 * Instead of sorting (O(N log N)), we can use a frequency array
 * (bucket) to count how many papers have a particular number
 * of citations.
 * 
 * - If a paper has citations ≥ N, we cap it at bucket[N].
 * - Then, we traverse from the back to find the highest h
 *   where total papers with ≥ h citations ≥ h.
 * 
 * ----------------------------------------------------------
 * 📊 Example:
 * citations = [3, 0, 6, 1, 5]
 * 
 * Step 1 → n = 5, create bucket of size 6 → [0,0,0,0,0,0]
 * Step 2 → fill bucket:
 *           c = 3 → bucket[3]++
 *           c = 0 → bucket[0]++
 *           c = 6 → bucket[5]++  (since ≥ n)
 *           c = 1 → bucket[1]++
 *           c = 5 → bucket[5]++
 *       bucket = [1,1,0,1,0,2]
 * 
 * Step 3 → Traverse from end:
 *     i = 5 → totalPapers = 2   (2 ≥ 5 ❌)
 *     i = 4 → totalPapers = 2   (2 ≥ 4 ❌)
 *     i = 3 → totalPapers = 3   (3 ≥ 3 ✅) → return 3
 * ✅ Hence, H-index = 3
 * 
 * ----------------------------------------------------------
 * ⏱️ Time Complexity:  O(N)
 * 💾 Space Complexity: O(N)
 ************************************************************/

void optimal() {
    vector<int> citations = {3, 0, 6, 1, 5};        // Example input
    int totalPapers = citations.size();             // Total number of papers

    vector<int> bucket(totalPapers + 1, 0);         // Bucket to store citation counts

    // Step 1: Fill frequency bucket
    for (int cites : citations) {
        if (cites >= totalPapers)
            bucket[totalPapers]++;                  // Count all papers with ≥ n citations
        else
            bucket[cites]++;                        // Count papers with exact citation value
    }

    // Step 2: Traverse from end to find H-index
    int papersWithAtLeast = 0;                      // Total papers with ≥ i citations
    for (int i = totalPapers; i >= 0; i--) {
        papersWithAtLeast += bucket[i];             // Add current bucket count
        if (papersWithAtLeast >= i) {               // Check H-index condition
            cout << "H-Index = " << i << endl;      // Output result
            return;
        }
    }

    cout << "H-Index = 0" << endl;                  // If none satisfy, H = 0
}

int main() {
    optimal();
    return 0;
}
