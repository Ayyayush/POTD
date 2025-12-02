#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<int> temp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(matrix[i][j]);
        }
    }
    sort(temp.begin(), temp.end());
    cout << temp[k - 1] << "\n";  // kth smallest element print karo
}

void optimal()
{
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int low = matrix[0][0];          // smallest element
    int high = matrix[m - 1][n - 1]; // largest element

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int count = 0;
        int row = m - 1, col = 0;

        // Count elements <= mid
        while (row >= 0 && col < n)
        {
            if (matrix[row][col] <= mid)
            {
                count += row + 1;
                col++;
            }
            else
            {
                row--;
            }
        }

        if (count < k)
            low = mid + 1;   // kth element is bigger
        else
            high = mid - 1;  // kth element is smaller or equal
    }

    cout << low << "\n";  // low mein kth smallest element aayega
}

int main()
{
    // brute();
    optimal();

    return 0;
}
