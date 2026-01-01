#include <bits/stdc++.h>
using namespace std;

void Xmatrix()
{
    int n, m;                                   // Rows aur columns ke liye variables
    cin >> n >> m;                              // Matrix ke rows aur columns ki input le rahe hain

    vector<vector<int>> grid(n, vector<int>(m)); // 2D vector define kar rahe hain matrix ke liye

    // Matrix input le rahe hain
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> grid[i][j];
        }
    }

    int f = 0; // Flag to check if matrix is not an X-matrix

    // Check diagonals and off-diagonals
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (i == j || i + j == m - 1) 
            {
                // Diagonal elements should not be 0
                if (grid[i][j] == 0) 
                {
                    f = 1;
                    break;
                }
            } 
            else 
            {
                // Non-diagonal elements should be 0
                if (grid[i][j] != 0) 
                {
                    f = 1;
                    break;
                }
            }
        }
        if (f == 1) break; // Exit loop if condition fails
    }

    if (f > 0)
        cout << "false" << endl; // Matrix is not an X-matrix
    else
        cout << "true" << endl; // Matrix is an X-matrix
}

int main()
{
    Xmatrix();
    return 0;
}
