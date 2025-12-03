#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // ✅ Approach: Simulation using string expansion
    // ⏱️ T.C = O(k * log k) approx (each level doubles or more)
    // 🛢️ S.C = O(k) for growing string

    int k = 10;                                 // Example input
    string s = "a";

    while (s.size() < k) {
        string temp = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'z') {
                temp += 'a';                    // Wrap around from z → a
            } else {
                temp += s[i] + 1;               // Next character in alphabet
            }
        }

        s.append(temp);                         // Append transformed part
    }

    cout << s[k - 1] << endl;                   // Output kth character (1-based index)
}


/**
 * Approach 2
 * hum log string geberate krte hi h 
 * maan lo hume 16th character chahiye
 * toh wo s[k-1] wale inde xpe hoga 
 * toh agar 15 ka binary likhenge toh 1111   aayega 
 * ab maan lo first character h a 
 * a mein s[k-1] wala index == 15 abhi 
 * toh agar iss index ke number set bits == 1111== 4 add kre 
 * a+4 ===== e toh ye answer h 
 * 
 * 
 * *PROOF
 * 
 * SUPER STRINGS (Pattern Growth Observation)
 *
 * We are constructing a string `s` by a pattern rule, doubling the string and adding new characters in between.
 * Let's see how the string grows with each step:
 *
 * Step 1:
 * s = 'a'
 * Length = 1
 *
 * Step 2:
 * s = 'ab'
 * Length = 2
 *
 * Step 3:
 * s = 'abbc'
 * Length = 4
 *
 * Step 4:
 * s = 'abbc bccd'
 * Length = 8
 *  ↑    ↑    ↑
 *  1    5    9  (positions of added characters)
 *
 * Step 5:
 * s = 'abbc bccd bccdcdde'
 * Length = 16
 *  ↑    ↑    ↑     ↑
 *  1    5    9     13  (positions of added characters in merged strings)
 *
 * Observation:
 * At each step, we are duplicating the previous string and adding a new character to form a longer string.
 * The length doubles every time (1 → 2 → 4 → 8 → 16).
 * This is a recursive pattern formation.
 * 
 * ans ==e dikhta h hume 
 * 
 * 
 * 
 * example maan lo 12 h 
 * 12 h toh hum 16th wale tak jana padega kyunki power wise krna h
 * maan lo 12 charcter yaani s[11] chahiye ==c
 * 12 ka binary h   1100  == 2 set bits 
 * a + 2 ==c    == correct answer
 * 
 * 
 * simply count set bits of k-1   
 * ek built in pop_count function h  wo use kr skte h ya traditionally bhi kr skte h
 * *REASON 
 * maan lo 16th charcter ==15 th index ==e aaya kaise h
 * 8 ka double kiya h toh 16 hua
 * ab baat do beech se 
 * 8th *2 ==16
 * toh 16th charcter d ka next shift h 
 * toh ab backtrack krna h
 * ab maan lo d kha se aaya tha
 * 8 ka half karo 
 * 4th charcter == c h tbhi next shift pe d bana 
 * toh ab aise hi c ka bhi orgin dhundo 
 * firr uska bhi origin toh 4 baar half kiya toh oroigin mila 
 * yaani a ko 4times shift kiya toh e bna 
 * 
 * 
 * 
 */



 //Approach-2 (bit observation to find shift)
//T.C : O(log(k-1))
//S.C : O(1)
class Solution {
public:
    char kthCharacter(int k) {
        int shift = __builtin_popcount(k-1);

        return 'a' + shift;
    }
};











char findChar(int k)
 {
    // Base case
    if (k == 1) return 'a';

    // Find largest power of 2 less than k
    int len = 1;
    while (2 * len < k) len *= 2;

    // First half: return directly
    if (k <= len) return findChar(k);

    // Second half: next character of mirrored index
    char prev = findChar(k - len);
    return (prev == 'z') ? 'a' : prev + 1;
}

void optimal()
{
    // ✅ T.C = O(log k)
    // 🛢️ S.C = O(log k) recursion stack

    int k = 10;                                // Example input
    cout << findChar(k) << endl;               // Output kth character
}

int main()
{
    optimal();
    return 0;
}
