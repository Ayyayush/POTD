#include <bits/stdc++.h>
using namespace std;


// Adobe,Google

// 🔹 T.C. = O(n)       (Recursive depth = n)
// 🔹 S.C. = O(n)       (Recursive call stack)
int factorial(int n)
{
    if(n == 0 || n == 1) return 1;                      // ✅ Correct base case
    return n * factorial(n - 1);
}

// 🔹 T.C. = O(n) for factorial(n) + O(r) + O(n - r) => O(n)
// 🔹 S.C. = O(n) from recursive calls
int combination(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));   // ✅ nCr formula
}

// 🔹 T.C. = O(n^3)            → nested loop: O(n^2), and each combination(): O(n)
// 🔹 S.C. = O(1)              → except recursive stack in factorial
void pascal(int n)
{
    for(int row = 0; row <= n; row++)
    {
        for(int col = 0; col <= row; col++)
        {
            cout << combination(row, col) << " ";
        }
        cout << endl;
    }
}

// 🔹 T.C. = O(n^2)             → Each value computed in O(1) using formula
// 🔹 S.C. = O(1)               → No recursion, no extra space
void betterpascal(int n)
{
    for (int row = 0; row <= n; row++)
    {
        long long val = 1;

        for (int col = 0; col <= row; col++)
        {
            cout << val << " ";

            val = val * (row - col) / (col + 1);   // 🔁 Pascal Identity
        }
        cout << endl;
    }
}


/**
 * Optimal Approach
 * for(int i=0;i<numrows;i++)
 * {
 * vector<int>arr(i+1,1)
 * aise 1st aur last col already 0 se filled h 
 * for(int j=1;j<i;j++)
 * {
 * result[i][j]=result[i-1][j]+result[i-1][j-1];
 * }
 * }
 * 
 * return result;
 * 
 * 
 * toh maan lo 4c2 pucha
 * 4th row 2nd col mein jao
 * wha jo value h whi daal do 
 * pascal triangle ka application btaya h maths playlist mein 
 * number of ways to arrange array to get bst krke 
 * 
 */

// Adobe, Google

// 🔹 T.C. = O(n^2)                     → Har row ke liye har column compute kar rahe hain O(1) me
// 🔹 S.C. = O(n^2)                     → Final pascal triangle ko store karne ke liye
void optimal()
{
    int numRows;
    cin >> numRows;

    vector<vector<int>> result(numRows);               // 🔸 Final triangle banane ke liye outer vector

    for (int i = 0; i < numRows; i++)
    {
        result[i] = vector<int>(i + 1, 1);             // 🔸 Har row me i+1 elements aur sab 1 se bhar do

        for (int j = 1; j < i; j++)                    // 🔸 1st aur last elements already 1 hain
        {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];   // 🔸 Pascal Identity
        }
    }

    // 🔹 Output print karo
    for (auto row : result)
    {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main()
{
    optimal();       // 🔹 Call optimal approach
    return 0;
}
