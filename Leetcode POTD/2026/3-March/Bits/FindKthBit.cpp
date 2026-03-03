#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
! PROBLEM NAME:
! Find Kth Bit in Nth Binary String
! (LeetCode 1545)

! COMPANY TAGS:
! Amazon
! Microsoft
! Google
! Facebook

-------------------------------------------------------------------------------
! PROBLEM DESCRIPTION:

We define a binary string sequence as:

S1 = "0"

For i > 1:
Si = S(i-1) + "1" + reverse(invert(S(i-1)))

Where:
- invert(x): change '0' -> '1' and '1' -> '0'
- reverse(x): reverse the string

Example:

S1 = "0"

S2 = "0" + "1" + reverse(invert("0"))
   = "0" + "1" + "1"
   = "011"

S3 = "011" + "1" + reverse(invert("011"))
   = "011" + "1" + "001"
   = "0111001"

If n = 3 and k = 5
Answer = 0

-------------------------------------------------------------------------------
! BRUTE FORCE IDEA (Not Implemented Here)

- Build full string from S1 to Sn
- Return k-th character

But:
Length of Sn = 2^n - 1
Time Complexity = O(2^n)
Space Complexity = O(2^n)

This is exponential and not efficient for large n.

-------------------------------------------------------------------------------
! OPTIMAL APPROACH (Recursive Mathematical Insight)

Observation:

Length of Sn = 2^n - 1

Middle index:
mid = (len + 1) / 2

Pattern:
- Middle element is always '1'
- Left half = S(n-1)
- Right half = reverse(invert(S(n-1)))

Recursive rules:

1) If k == mid → return '1'
2) If k < mid → same as findKthBit(n-1, k)
3) If k > mid:
       mirrored_index = len - k + 1
       result = invert( findKthBit(n-1, mirrored_index) )

-------------------------------------------------------------------------------
! TIME COMPLEXITY:
O(n)      (Each recursive call reduces n by 1)

! SPACE COMPLEXITY:
O(n)      (Recursion stack)

===============================================================================
*/



class Solution 
{
public:
    char findKthBit(int n, int k) 
    {
        string s = "0", prev = "0";  
        // s -> current constructed string S(n)
        // prev -> stores previous string S(n-1)

        // ! Build strings from S(2) to S(n)
        for (int i = 2; i <= n; i++) 
        {
            s = prev + "1";  
            // First part: S(n-1)
            // Middle part: '1'

            // ! Invert previous string (0 -> 1, 1 -> 0)
            for (int j = 0; j < prev.size(); j++) 
            {
                if (prev[j] == '0')
                    prev[j] = '1';   // Flip 0 to 1
                else if (prev[j] == '1')
                    prev[j] = '0';   // Flip 1 to 0
            }

            // ! Reverse the inverted string
            reverse(prev.begin(), prev.end());

            // ! Append reversed inverted string
            s += prev;

            // ! Update prev for next iteration
            prev = s;
        }

        cout << s << endl;   // Printing full constructed string (for debugging)

        return s[k - 1];     // Return k-th bit (1-based index → convert to 0-based)
    }
};




class Solution {
public:
    
    char findKthBit(int n, int k) {
        
        // ! BASE CASE
        // If n == 1, S1 = "0"
        if (n == 1)
            return '0';
        
        // ! LENGTH CALCULATION
        // Length of Sn = 2^n - 1
        int len = (1 << n) - 1;
        
        // ! MIDDLE INDEX
        int mid = (len + 1) / 2;
        
        // ! CASE 1: Middle element
        if (k == mid)
            return '1';
        
        // ! CASE 2: Left half
        // Same as previous string
        if (k < mid)
            return findKthBit(n - 1, k);
        
        // ! CASE 3: Right half
        // Mirror index logic
        int mirroredIndex = len - k + 1;
        
        // Recursive call on previous level
        char ch = findKthBit(n - 1, mirroredIndex);
        
        // Invert result
        if (ch == '0')
            return '1';
        else
            return '0';
    }
};




int main()
{
    Solution obj;
    
    // Example test
    int n = 3;
    int k = 5;
    
    cout << "Answer: " << obj.findKthBit(n, k) << endl;
    
    return 0;
}