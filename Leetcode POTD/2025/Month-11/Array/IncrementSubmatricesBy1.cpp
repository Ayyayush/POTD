/**
 * Increment Submatrices by 1
 * 
 * Problem:
 * Aapko ek n x n matrix banana hai (sab zero). 
 * Har query mein 4 values milti hain: r1, c1, r2, c2
 * Aapko is rectangular submatrix ke sab cells ko +1 karna hota hai.
 * 
 * Example:
 * n = 3
 * queries = {{0,0,1,1}, {1,1,2,2}}
 * 
 * Output matrix:
 * 1 1 0
 * 1 2 1
 * 0 1 1
 */

#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // -------------------------------
    // Hardcoded input for demo
    // -------------------------------
    int n = 3;                                     // matrix size

    vector<vector<int>> queries = {
        {0, 0, 1, 1},
        {1, 1, 2, 2}
    };

    // ---------------------------------------------------------
    // Step 1: Create n x n matrix filled with 0
    // ---------------------------------------------------------
    vector<vector<int>> nums(n, vector<int>(n, 0));

    // ---------------------------------------------------------
    // Step 2: Har query ko process karna hai
    // ---------------------------------------------------------
    for (int i = 0; i < queries.size(); i++)
    {
        int r1 = queries[i][0];
        int c1 = queries[i][1];
        int r2 = queries[i][2];
        int c2 = queries[i][3];

        // Submatrix ko +1 karna hai
        for (int row = r1; row <= r2; row++)
        {
            for (int col = c1; col <= c2; col++)
            {
                nums[row][col] += 1;               // increment cell
            }
        }
    }

    // ---------------------------------------------------------
    // Step 3: Final matrix print karna
    // ---------------------------------------------------------
    cout << "Final Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    brute();
    return 0;
}
