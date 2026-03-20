/**
 * ! Count Submatrices with Top-Left (0,0) and Sum ≤ k
 * 
 * ------------------ PROBLEM DESCRIPTION ------------------
 * Hume ek 2D grid diya gaya hai
 * Hume count karna hai kitne submatrices ka sum ≤ k hai
 * 
 * ! IMPORTANT CONSTRAINT:
 * Har submatrix ka starting point FIXED hai → (0,0)
 * 
 * --------------------------------------------------------
 * ! BRUTE FORCE IDEA
 * 
 * Har possible (i,j) ke liye:
 * → (0,0) se (i,j) tak ka submatrix lo
 * → sum calculate karo (har baar)
 * → check karo ≤ k
 * 
 * Problem:
 * → baar-baar same elements add ho rahe hain (repetitive work)
 * → inefficient
 * 
 * --------------------------------------------------------
 * ! OPTIMAL APPROACH (2D PREFIX SUM)
 * 
 * Ye approach bahut common hai jab:
 * → submatrix sum repeatedly calculate karna ho
 * 
 * Idea:
 * Har cell (i,j) par:
 * → store karo sum of submatrix from (0,0) → (i,j)
 * 
 * Formula:
 * grid[i][j] = grid[i][j]
 *              + top
 *              + left
 *              - top-left (double count remove)
 * 
 * --------------------------------------------------------
 * ! VISUAL UNDERSTANDING
 * 
 * Example grid:
 * 1 2 3
 * 4 5 6
 * 7 8 9
 * 
 * Suppose (1,2) pe ho (value = 6):
 * 
 * → upar ka sum (0,2) = 1+2+3
 * → left ka sum (1,1) = 1+2+4+5
 * → overlap (0,1) subtract
 * 
 * → total sum mil jaata hai without recomputation
 * 
 * --------------------------------------------------------
 * ! KEY OBSERVATION
 * 
 * Jaise hi kisi row me sum > k ho jaye:
 * → uske aage ke elements aur bade honge
 * → isliye break kar sakte hain (optimization)
 * 
 * --------------------------------------------------------
 * ! TIME COMPLEXITY
 * 
 * O(m * n)
 * → har cell ek hi baar process ho raha hai
 * 
 * --------------------------------------------------------
 * ! SPACE COMPLEXITY
 * 
 * O(1)
 * → in-place prefix sum bana rahe hain (extra space nahi)
 * 
 */

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();              // total rows
        int n = grid[0].size();           // total columns
        
        int count = 0;                    // final answer
        
        // ! Build prefix sum + count valid submatrices
        for (int i = 0; i < m; i++)       // row loop
        {
            for (int j = 0; j < n; j++)   // col loop
            {
                // ! add top contribution
                if (i - 1 >= 0)
                    grid[i][j] += grid[i - 1][j];

                // ! add left contribution
                if (j - 1 >= 0)
                    grid[i][j] += grid[i][j - 1];

                // ! remove double counted overlap
                if (i - 1 >= 0 && j - 1 >= 0)
                    grid[i][j] -= grid[i - 1][j - 1];

                // ! check condition
                if (grid[i][j] <= k)
                    count++;              // valid submatrix
                else
                    break;                // optimization: aage sab bade honge
            }
        }
        
        return count;                     // final answer
    }
};