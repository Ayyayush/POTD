#include <bits/stdc++.h>
using namespace std;



void better()
{
    int m, n, target;
    cin >> m >> n >> target;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];                                  // matrix input le rahe hain
        }
    }

    // jo target element h usko har row ke last elt se compare krke dekho
    // agar target usse bada h toh next row mein jao
    // nhi toh uss row mein hi h wo element
    // ab uss row mein last se first index ki taraf jao

    int i = 0, j = n - 1;                                          // top-right se search start kar rahe hain

    while (i < m && j >= 0)
    {
        if (matrix[i][j] > target)                                // agar current > target to left jao
        {
            j--;
        }
        else if (matrix[i][j] < target)                           // agar current < target to neeche jao
        {
            i++;
        }
        else
        {
            cout << "True\n";                                     // match mil gaya
            return;
        }
    }

    cout << "False\n";                                            // pura traverse kar liya, nahi mila
}

// Time Complexity: O(m + n)                   // worst case: last row and first column tak jaana padta h
// Space Complexity: O(1)                      // koi extra space nahi use ho rahi


void optimal()
{
    // 2d array ko 1-d ki tarah conceptually socho
    // 1st element l ho gya, last element r ho gya
    // ab usme binary search karo
    int m, n, target;
    cin >> m >> n >> target;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];                                  // matrix input le rahe hain
        }
    }

    int start = 0;
    int end = m * n - 1;                                          // 1D array ke tarah search karne ke liye

    while (start <= end)
    {
        int mid = start + (end - start) / 2;                      // overflow safe mid calculation
        int row = mid / n;                                        // mid ka corresponding row
        int col = mid % n;                                        // mid ka corresponding column

        if (matrix[row][col] > target)
        {
            end = mid - 1;                                        // right half discard karo
        }
        else if (matrix[row][col] < target)
        {
            start = mid + 1;                                      // left half discard karo
        }
        else
        {
            cout << "True\n";                                     // match mil gaya
            return;
        }
    }

    cout << "False\n";                                            // nahi mila to
}

// Time Complexity: O(log(m * n))              // binary search on total elements
// Space Complexity: O(1)                      // koi extra space use nahi ho rahi


int main()
{
    // brute();
    // better();
    optimal();

    return 0;
}
