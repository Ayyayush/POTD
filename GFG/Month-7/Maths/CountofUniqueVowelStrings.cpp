/**
 * Count of unique vowel strings 
 * 
 * permutations are the different ways in which a set of items can be arranged in order 
 * 
 * eg::
 * s="aaokee"
 * isme vowels h aaoee 
 * toh dekho dirfect factorial se bhi answerr aa jayega 
 * par woi tab valid hota jab repeating na ho
 * unique h aoe 
 * iska permutation hota 6
 * but multiple occurance h 
 * and question mein h ki ek baar mein ek hi le skte h 
 * 
 * agar repeat kr rhe h toh jitne repeat h unse divide bhi krna h 
 */

 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vowelCount(string& s) {
        // Step 1: Frequency array banate hain jisme har character 'a' to 'z' ka count hoga
        int freq[26] = {0};        // freq[0] → 'a', freq[4] → 'e', freq[8] → 'i', freq[14] → 'o', freq[20] → 'u'
        int cnt = 0;               // Different vowels ka count
        int mul = 1;               // Product of frequencies of vowels

        // Step 2: Har character ke liye check karo agar woh vowel hai toh uska count badhao
        for (char c : s) {
            if (strchr("aeiou", c)) {                   // strchr returns non-null if c is a vowel
                freq[c - 'a']++;                        // Character ko index mein convert karke frequency badha rahe hain
            }
        }

        // Step 3: Vowels ke indices: a=0, e=4, i=8, o=14, u=20
        // Har vowel ke liye agar uski frequency > 0 hai toh usse product mein multiply karo aur count badhao
        for (int v : {0, 4, 8, 14, 20}) {
            if (freq[v] > 0) {
                mul *= freq[v];                         // Multiply all vowel frequencies
                cnt++;                                  // Count number of distinct vowels present
            }
        }

        // Step 4: Agar koi vowel nahi mila toh return 0
        // Else: multiply the product of frequencies * factorial of number of vowels
        // tgamma(n+1) == n! (factorial)
        return cnt > 0 ? mul * tgamma(cnt + 1) : 0;
    }
};
