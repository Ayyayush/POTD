/**
 * 🔥 Leetcode 2452
 * Words Within Two Edits of Dictionary
 * 
 * 🧠 Problem Summary (Hinglish)
 * ----------------------------------------------------
 * Tumhe 2 arrays diye gaye hain:
 * 👉 queries (words to check)
 * 👉 dictionary (valid words)
 * 
 * Har query word ke liye check karo:
 * 👉 Kya woh dictionary ke kisi word se max 2 characters me different hai?
 * 
 * Agar haan → us word ko answer me add karo
 */

/*******************************************************
 * 🔴 Approach: Brute Force (Compare each query with all dictionary words)
 * 
 * T.C : O(Q * D * L)
 *   Q = queries.size()
 *   D = dictionary.size()
 *   L = length of each word
 * 
 * S.C : O(1) (excluding result)
 *******************************************************/

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {

        int wordLength = queries[0].size();   // All words have same length
        vector<string> result;

        // Step 1: Iterate over each query word
        for (auto &queryWord : queries) {

            // Step 2: Compare with each dictionary word
            for (auto &dictWord : dictionary) {

                int mismatchCount = 0;

                // Step 3: Compare characters
                for (int index = 0; index < wordLength; index++) {

                    if (queryWord[index] != dictWord[index]) {
                        mismatchCount++;
                    }

                    // Optimization: stop early if more than 2 mismatches
                    if (mismatchCount > 2) break;
                }

                // Step 4: Valid word found
                if (mismatchCount <= 2) {
                    result.push_back(queryWord);
                    break; // No need to check other dictionary words
                }
            }
        }

        return result;
    }
};