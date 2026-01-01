#include <bits/stdc++.h>
using namespace std;

/*
 * 🟢 Problem: Minimum Deletions to Make String K-Special
 * ------------------------------------------------------
 * Given a string, delete as few characters as possible to make sure:
 *   For every pair of characters, |freq[i] - freq[j]| <= k
 * 
 * Goal: Return minimum number of deletions to make the string K-special.
 */


void brute()
{
    /*
    -------------------------------------------------------------
    🔴 Brute Force Approach
    -------------------------------------------------------------
    🧠 Logic:
    - Step 1: Count frequency of all characters using a hash map
    - Step 2: Store all frequencies in a vector and sort them
    - Step 3: Try every frequency as a potential "target frequency"
        - For each target freq:
            - If a freq is smaller than target → delete all of it
            - If a freq is bigger than target+k → delete extra part
    - Step 4: Return the minimum deletions needed among all trials

    🧪 Example:
    word = "aabcaba", k = 0
    Frequencies → a:4, b:2, c:1 → [1,2,4]
    Try target = 1:
      - b(2) > 1 → 2-1-k = 1
      - a(4) > 1 → 4-1-k = 3
      → total = 1+3 = 4
    Try target = 2, target = 4 etc.

    -------------------------------------------------------------
    ✅ Time Complexity:
    - O(N)         → To count frequencies
    - O(26 log 26) → Sorting frequency vector (max 26 elements)
    - O(26*26)     → Trying each target against all others
    - Total: O(N + 676) ≈ O(N)

    ✅ Space Complexity:
    - O(26) for hashmap and frequency vector
    -------------------------------------------------------------
    */

    string word = "aabcaba";    // Sample Input
    int k = 0;                  // Max allowed diff

    unordered_map<char, int> mp;

    // Step 1: Count frequencies
    for (char c : word) {
        mp[c]++;
    }

    // Step 2: Store frequencies in vector
    vector<int> freq;
    for (auto it : mp) {
        freq.push_back(it.second);
    }

    // Step 3: Sort frequencies
    sort(freq.begin(), freq.end());

    int ans = INT_MAX;

    // Step 4: Try each frequency as target
    for (int i = 0; i < freq.size(); i++) {
        int deletions = 0;
        int target = freq[i];

        for (int j = 0; j < freq.size(); j++) {
            if (freq[j] > target + k) {
                // Remove characters exceeding target+k
                deletions += freq[j] - (target + k);
            } else if (freq[j] < target) {
                // Remove all chars below target
                deletions += freq[j];
            }
        }

        // Track minimum deletions
        ans = min(ans, deletions);
    }

    cout << "Minimum deletions (Brute): " << ans << endl;
}




void better() {
    /*
     * 🔵 Better Approach (Optimized via Sorting)
     * ---------------------------------------------------
     * 🧠 Logic:
     * 1. Count frequencies of all 26 lowercase letters
     * 2. Sort the frequency array (many will be 0)
     * 3. For every index i:
     *      - Assume freq[i] is the min frequency to keep
     *      - Delete all chars before i (fully delete lower freqs)
     *      - For every j > i:
     *           - If freq[j] > freq[i] + k, remove extra part
     *      - Track the total deletions
     *
     * ✨ This avoids nested loops on hashmap, uses fixed size vector

     * ---------------------------------------------------
     * ✅ Time Complexity  : O(N + 26 log 26) = O(N)
     * ✅ Space Complexity : O(1) - constant space array
     * ---------------------------------------------------
     */

    string word = "aabcaba"; // Sample Input
    int k = 2;

    vector<int> freq(26, 0);

    // Step 1: Frequency count for all lowercase letters
    for (char &ch : word) {
        freq[ch - 'a']++;
    }

    // Step 2: Sort the frequency array
    sort(begin(freq), end(freq));

    int result = INT_MAX;
    int deleted_till_now = 0;

    // Step 3: Try each freq[i] as the base frequency to keep
    for (int i = 0; i < 26; i++) {
        int minFreq = freq[i];
        int temp = deleted_till_now;

        // Step 3.1: For characters with frequency > minFreq
        for (int j = 25; j > i; j--) {
            if (freq[j] - freq[i] <= k) break;

            temp += freq[j] - minFreq - k;
        }

        result = min(result, temp);

        // Accumulate deletions from lower frequencies
        deleted_till_now += minFreq;
    }

    cout << "Minimum deletions (Better): " << result << endl;
}


int main()
{
    brute();     // Run brute force version
    better();    // Run optimized version
    return 0;
}
