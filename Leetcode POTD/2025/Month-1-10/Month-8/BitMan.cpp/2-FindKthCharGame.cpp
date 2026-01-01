/**
 * *FIND KTH CHARACTER IN STRING GAME -2
 * Similar problem kth symbol in grammar
 * alice and bob game khel rhe h
 * k diya h array diya h ops naam ka
 * op[i]==type of operation
 * if op[i]==0   copy krke jod do word ko
 * eg::= word == abc  ->  abcabc
 * if op[i]==1    toh word ke har character ka next leke word mein jo do
 * eg:: word==abc   ->  abcbde
 *
 *
 *
 * eg::-= k=5 ops=[0,0,0]  word=a
 * output a+a   ,aa+aa,    aaaa+aaaa
 * 5th character ==   a
 *
 *
 * eg:- k=10  ops=[0,1,0,1]   word=a
 * a+a,  aa+bb ,   aabb+aabb ,     aabbaabb+bbccbbcc
 * 10th character == b
 *
 *
 * *BRUTE FORCE::=
 * bas simulation karte jao
 *
 *
 * *OPTIMAL THOUGHT PROCESS
 * ab maan ke chalte h bas 0 hi h ops mein
 * ab thoda isi question ka part 1 wala approach use karenge 
 * 
 * 
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
 * *HUME ye samajh aata h ki ye recurreance relation h 
 * chote problem ka solve karo toh bada bhi ho jayega 
 * 
 * 
 * toh ab chalo maan lo hume ye toh pata chal gya ki uss pichle half mein kaise jaye 
 * jaise maan lo len ==8 ka kth charcter ka answer chahiye 
 * toh k-len/2  pe jo character hota whi kth charcter bhi hota 
 * but isme fark itna h ki ops[1] or ops[0] ho toh thoda alag chiz krna h
 * toh ops[1] pe jo krna h whi stirng part 1 wale mein bhi krna tha
 *  
 *
 */



 /*
 BRUTE FORCE
 T.C==
 S.C==
 */
class Solution
{
public:
    char kthCharacter(long long k, vector<int> &ops)
    {

        string s = "a";
        int idx = 0;

        while (s.size() < k && idx < ops.size())
        {
            if (ops[idx++] == 0)
            {
                s.append(s);
            }
            else
            {
                int x = 0;
                string temp = "";
                while (x < s.size())
                {
                    temp += s[x++] + 1;
                }
                s.append(temp);
            }
        }

        return s[k - 1];
    }
};





//Approach - Recursion
//T.C : O(log(k))
//S.C : O(log(k))) of system stack
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // Base case: If k is 1, the result is the initial character 'a'
        if (k == 1) {
            return 'a';
        }

        int n = operations.size();  // Size of the operations array
        int opType;                 // Store the operation type (0 or 1)
        long long len = 1;          // Start with length 1 (initial 'a')
        long long newK;             // To store the adjusted k value

        // Traverse through the operations array to determine the operation type
        for (int i = 0; i < n; i++) {
            len *= 2;               // Double the length at each step
            if (len >= k) {         // If the current length surpasses or equals k
                opType = operations[i];  // Get the current operation type
                newK = k - len / 2;      // Adjust k for the next recursive call
                break;                   // Break as we have found the required operation
            }
        }

        // Recursively find the character before the operation is applied
        char res = kthCharacter(newK, operations);
        
        // If operation type is 0, return the character as is
        if (opType == 0) 
            return res;

        // If operation type is 1, transform the character ('a' becomes 'b', etc.)
        if (res == 'z') 
            return 'a';  // Handle wrap-around from 'z' to 'a'
        
        return res + 1;   // Increment character by 1
    }
};


