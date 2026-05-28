/**
 * Leetcode :: Number of Special Characters
 * 
 * ---------------------------------------------------
 * ! What is Special Character ?
 * ---------------------------------------------------
 * 
 * ek character special tab hoga:
 * 
 * agar:
 * 
 * lowercase character pehle aaye
 * AND
 * uppercase character baad me aaye
 * 
 * Example:
 * 
 * word = "aaAbcBC"
 * 
 * a -> special
 * because:
 * last 'a' comes before first 'A'
 * 
 * b -> special
 * because:
 * last 'b' comes before first 'B'
 * 
 * c -> NOT special
 * because:
 * capital C lowercase c se pehle aa gaya
 * 
 * answer = 2
 * 
 * ---------------------------------------------------
 * ! Important Observation
 * ---------------------------------------------------
 * 
 * hume bas 2 cheeze track karni h:
 * 
 * 1) lowercase ka LAST occurrence
 * 2) uppercase ka FIRST occurrence
 * 
 * ---------------------------------------------------
 * ! Why LAST lowercase ?
 * ---------------------------------------------------
 * 
 * because:
 * saare lowercase characters
 * uppercase se pehle hone chahiye
 * 
 * Example:
 * 
 * aAaa
 * 
 * yahan:
 * last lowercase 'a'
 * capital A ke baad h
 * 
 * so invalid
 * 
 * ---------------------------------------------------
 * ! Why FIRST uppercase ?
 * ---------------------------------------------------
 * 
 * because:
 * agar first uppercase hi lowercase se pehle aa gaya
 * toh already invalid
 * 
 * ---------------------------------------------------
 * ! Dry Run
 * ---------------------------------------------------
 * 
 * word = "aaAbBcC"
 * 
 * index:
 * 0 1 2 3 4 5 6
 * 
 * chars:
 * a a A b B c C
 * 
 * ---------------------------------------------------
 * ! Step 1 : Fill Arrays
 * ---------------------------------------------------
 * 
 * lastSmall:
 * 
 * a -> 1
 * b -> 3
 * c -> 5
 * 
 * firstCapital:
 * 
 * A -> 2
 * B -> 4
 * C -> 6
 * 
 * ---------------------------------------------------
 * ! Step 2 : Check Condition
 * ---------------------------------------------------
 * 
 * a:
 * 1 < 2
 * YES
 * 
 * b:
 * 3 < 4
 * YES
 * 
 * c:
 * 5 < 6
 * YES
 * 
 * answer = 3
 * 
 * ---------------------------------------------------
 * ! Another Example
 * ---------------------------------------------------
 * 
 * word = "Aa"
 * 
 * lastSmall[a] = 1
 * firstCapital[A] = 0
 * 
 * check:
 * 1 < 0 ?
 * NO
 * 
 * not special
 * 
 * ---------------------------------------------------
 * ! Time Complexity
 * ---------------------------------------------------
 * 
 * O(n)
 * 
 * ---------------------------------------------------
 * ! Space Complexity
 * ---------------------------------------------------
 * 
 * O(1)
 * 
 * because:
 * arrays size always 26
 * 
 */

class Solution {
public:

    int numberOfSpecialChars(string word) {

        /**
         * ---------------------------------------------------
         * ! lastSmall[i]
         * ---------------------------------------------------
         * stores:
         * last occurrence of lowercase
         */

        vector<int> lastSmall(26,-1);

        /**
         * ---------------------------------------------------
         * ! firstCapital[i]
         * ---------------------------------------------------
         * stores:
         * first occurrence of uppercase
         */

        vector<int> firstCapital(26,-1);

        /**
         * ---------------------------------------------------
         * ! Traverse String
         * ---------------------------------------------------
         */

        for(int i=0; i<word.length(); i++) {

            char ch = word[i];

            /**
             * lowercase
             */

            if(islower(ch)) {

                lastSmall[ch-'a'] = i;
            }

            /**
             * uppercase
             */

            else {

                /**
                 * only first occurrence store karna h
                 */

                if(firstCapital[ch-'A'] == -1) {

                    firstCapital[ch-'A'] = i;
                }
            }
        }

        /**
         * ---------------------------------------------------
         * ! Check Valid Characters
         * ---------------------------------------------------
         */

        int count = 0;

        for(int i=0; i<26; i++) {

            /**
             * lowercase and uppercase dono hone chahiye
             */

            if(
                lastSmall[i] != -1 &&
                firstCapital[i] != -1 &&
                lastSmall[i] < firstCapital[i]
            ) {

                count++;
            }
        }

        return count;
    }
};