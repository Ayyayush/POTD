#include <bits/stdc++.h>
using namespace std;

/*
============================================================
LeetCode 2906 - Construct Product Matrix
============================================================

PROBLEM SUMMARY:
Given a matrix grid, har cell ke liye aisa value calculate karo:
→ product of ALL elements except the current cell
→ result ko mod 12345 ke saath return karna hai

------------------------------------------------------------
! BRUTE APPROACH (Tumhara wala idea)
------------------------------------------------------------
1. Sabka total product nikaalo
2. Har cell ke liye divide kar do

PROBLEM:
- Overflow ho jata hai (even __int128 risky)
- Division allowed nahi hota mod ke case mein generally
- Zeros handle karna tricky

------------------------------------------------------------
! ZERO CASE HANDLING
------------------------------------------------------------
Case 1: count >= 2 zero
→ har position ka product = 0

Case 2: count == 1 zero
→ sirf zero wali position pe product of non-zero elements
→ baaki sab = 0

Case 3: no zero
→ product / grid[i][j]

------------------------------------------------------------
T.C = O(n * m)
S.C = O(n * m)
------------------------------------------------------------
*/

class Solution {
public:
    const int mod = 12345;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();                         // rows
        int n = grid[0].size();                      // columns
        
        __int128 prod = 1;                           // large product store karne ke liye
        int count = 0;                               // zero count
        
        vector<vector<int>> result(m, vector<int>(n, 0)); // result matrix
        
        /*
        ------------------------------------------------------------
        Step 1: Total product calculate karo (non-zero elements ka)
        + zero count track karo
        ------------------------------------------------------------
        */
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count++;                         
                } else {
                    prod *= grid[i][j];              
                }
            }
        }

        /*
        ------------------------------------------------------------
        Case: Agar 2 ya usse zyada zero hain
        → har element ka product zero hi hoga
        ------------------------------------------------------------
        */
        if (count >= 2) {
            return result;                           // already 0 filled
        }

        /*
        ------------------------------------------------------------
        Step 2: Result fill karna
        ------------------------------------------------------------
        */
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (count == 1) {
                    /*
                    ------------------------------------------------
                    Sirf ek zero hai:
                    → zero wali position pe full product
                    → baaki sab = 0
                    ------------------------------------------------
                    */
                    if (grid[i][j] == 0) {
                        result[i][j] = (int)(prod % mod);
                    } else {
                        result[i][j] = 0;
                    }
                } else {
                    /*
                    ------------------------------------------------
                    No zero case:
                    → simply divide
                    ------------------------------------------------
                    */
                    result[i][j] = (int)((prod / grid[i][j]) % mod);
                }
            }
        }

        return result;
    }
};



/************************************************** C++ **************************************************/

/*
============================================================
! OPTIMAL APPROACH (Prefix + Suffix)  ⭐ IMPORTANT
============================================================

IDEA:
Har cell ke liye:
→ Left side ka product (prefix)
→ Right side ka product (suffix)

Final:
result[i][j] = prefix * suffix

------------------------------------------------------------
WHY THIS WORKS?
→ division avoid ho jata hai
→ overflow control hota hai (mod use karte hain)
→ clean approach

------------------------------------------------------------
EXAMPLE:
grid =
[
  [1, 2],
  [3, 4]
]

Flatten order traversal:
1 → 2 → 3 → 4

-----------------------------------
Step 1: Suffix (right product)
-----------------------------------
Start from end:

Position (1,1) → suffix = 1
Position (1,0) → suffix = 4
Position (0,1) → suffix = 3*4 = 12
Position (0,0) → suffix = 2*3*4 = 24

So suffix stored in result initially:
[
  [24, 12],
  [4, 1]
]

-----------------------------------
Step 2: Prefix (left product)
-----------------------------------
prefix start = 1

(0,0): result = 1 * 24 = 24
prefix = 1

(0,1): result = 1 * 12 = 12
prefix = 1*2 = 2

(1,0): result = 2 * 4 = 8
prefix = 2*3 = 6

(1,1): result = 6 * 1 = 6

-----------------------------------
FINAL RESULT:
[
  [24, 12],
  [8, 6]
]

------------------------------------------------------------
T.C = O(n * m)
S.C = O(n * m)  (result matrix)
------------------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int MOD = 12345;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> result(n, vector<int>(m)); // final answer

        /*
        ------------------------------------------------------------
        Step 1: Suffix Product (Right side product)
        ------------------------------------------------------------
        result[i][j] = product of all elements AFTER this cell
        ------------------------------------------------------------
        */
        long long suffix = 1;

        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {

                result[i][j] = suffix;

                /*
                Update suffix:
                current element ko multiply karo
                */
                suffix = (suffix * grid[i][j]) % MOD;
            }
        }

        /*
        ------------------------------------------------------------
        Step 2: Prefix Product (Left side product)
        ------------------------------------------------------------
        result[i][j] = prefix * suffix
        ------------------------------------------------------------
        */
        long long prefix = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                result[i][j] = (prefix * result[i][j]) % MOD;

                /*
                Update prefix:
                current element ko include karo
                */
                prefix = (prefix * grid[i][j]) % MOD;
            }
        }

        return result;
    }
};