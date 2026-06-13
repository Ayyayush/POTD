class Solution {
public:
    /*
        Approach: Reverse Alphabet Weight Encoding
        Time Complexity: O(total_characters_across_all_words)
        Space Complexity: O(1)   // ignoring output string
    */
    string mapWordWeights(vector<string>& inputWords, vector<int>& letterWeights) {

        string ffdkkdkfjfkdkslsl = "";                        // stores final answer
        string lowercaseSet = "abcdefghijklmnopqrstuvwxyz"; // reference alphabet

        for (int wordPos = 0; wordPos < inputWords.size(); wordPos++) {

            int currentWeightTotal = 0;                   // weight sum of current word

            for (int charPos = 0; charPos < inputWords[wordPos].size(); charPos++) {

                int letterPos = inputWords[wordPos][charPos] - 'a';
                                                         // maps character to index (0–25)
                currentWeightTotal += letterWeights[letterPos];
                                                         // add corresponding weight
            }

            currentWeightTotal %= 26;                     // reduce within alphabet range

            int reverseAlphabetPos = 25 - currentWeightTotal;
                                                         // reverse alphabetical mapping

            ffdkkdkfjfkdkslsl += lowercaseSet[reverseAlphabetPos];
                                                         // append mapped character
        }

        return ffdkkdkfjfkdkslsl;                             // return final encoded string
    }
};