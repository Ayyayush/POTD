// special binry strings robelm

/**
 * no of zero = no of one 
 * every prefix of binary string has at least as many 1's as 0's 
 * we have a special binary string s 
 * 
 * 
 * 
 * ! obseration 
 * koi bhi specla string 
 * same hacter se enmd uar start nhi ho skti agar usse speial hoa h toh 
 * eg 1__1
 * ab iske beech 2 00 daale toh 0 consecutve ho gye 
 * agar 11 daala oth 1 teen ho he aur 0 2 
 * 
 * balenced parenthsis ko agar stig mein represent kanr achah tohwo haesha spca string ke caegory in fal karega 
 * 
 * 
 * 
 */

 /************************************************************ C++ ******************************************************/
// Approach : Recursion + Divide & Sort
// Time Complexity  : ~O(n^2)       // Each level does substring + sort
// Space Complexity : O(n)          // Recursion stack + storing substrings

class Solution {
public:
    string makeLargestSpecial(string s) {

        vector<string> specials;       
        // This will store all valid special substrings 
        // found at current recursion level

        int start = 0;                 
        // Marks starting index of current special substring

        int sum = 0;                   
        // Used to check balance
        // '1' -> +1
        // '0' -> -1
        // When sum becomes 0 -> valid special substring found

        for(int i = 0; i < s.length(); i++) {

            sum += s[i] == '1' ? 1 : -1;    
            // If char is '1' increase balance
            // If char is '0' decrease balance

            if(sum == 0) {
                // We found one complete special substring

                string inner = s.substr(start+1, i-start-1); 
                // Extract inner portion (without outer 1 and 0)

                specials.push_back("1" + makeLargestSpecial(inner) + "0"); 
                // Recursively solve inner part
                // Then wrap it again with outer 1 and 0

                start = i+1;  
                // Move start to next position
            }
        }

        sort(begin(specials), end(specials), greater<string>()); 
        // Sort substrings in descending order
        // So that final string becomes lexicographically largest

        string result;

        for(string &str : specials) {
            result += str;  
            // Combine all sorted special substrings
        }

        return result;    
    }
};