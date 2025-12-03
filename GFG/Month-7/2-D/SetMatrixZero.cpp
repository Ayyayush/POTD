#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // 💡 Approach: Naive approach using vectors to store all 0 positions and updating rows/columns later
    // ⏱️ T.C = O(n * m * (r + c)) where r = number of 0-rows, c = number of 0-cols
    // 🧠 S.C = O(r + c)

    int m, n;                     
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for(int i = 0; i < m; i++)         
        for(int j = 0; j < n; j++)     
            cin >> matrix[i][j];

    vector<int> vecrow, veccolumn;

    for (int i = 0; i < m; i++)        
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                vecrow.push_back(i);            // 0 found → mark row
                veccolumn.push_back(j);         // 0 found → mark column
            }
        }
    }

    for (int i = 0; i < vecrow.size(); i++)
    {
        for (int col = 0; col < n; col++)
        {
            matrix[vecrow[i]][col] = 0;         // zero full row
        }
    }

    for (int i = 0; i < veccolumn.size(); i++)
    {
        for (int row = 0; row < m; row++)
        {
            matrix[row][veccolumn[i]] = 0;      // zero full column
        }
    }
}

void better()
{
    // 💡 Approach: Use two boolean arrays to mark which rows/cols to zero
    // ⏱️ T.C = O(n * m)
    // 🧠 S.C = O(n + m)

    int m, n;                       
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for(int i = 0; i < m; i++)         
        for(int j = 0; j < n; j++)     
            cin >> matrix[i][j];

    vector<bool> row(m, false), col(n, false);

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] == 0)
            {
                row[i] = true;            // mark row
                col[j] = true;            // mark col
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(row[i] || col[j])
            {
                matrix[i][j] = 0;         // set to 0 if marked
            }
        }
    }
}

void optimal()
{
    // 💡 Approach: Use 1st row and 1st column as marker space
    // ⏱️ T.C = O(n * m)
    // 🧠 S.C = O(1)

    int m, n;                       
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for(int i = 0; i < m; i++)         
        for(int j = 0; j < n; j++)     
            cin >> matrix[i][j];

    bool firstRowImpacted = false;
    bool firstColImpacted = false;

    // Check first row
    for (int col = 0; col < n; col++) {
        if (matrix[0][col] == 0)
            firstRowImpacted = true;
    }

    // Check first col
    for (int row = 0; row < m; row++) {
        if (matrix[row][0] == 0)
            firstColImpacted = true;
    }

    // Use 1st row and col to mark
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Zero based on markers
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    // Handle 1st row
    if (firstRowImpacted) {
        for (int col = 0; col < n; col++)
            matrix[0][col] = 0;
    }

    // Handle 1st col
    if (firstColImpacted) {
        for (int row = 0; row < m; row++)
            matrix[row][0] = 0;
    }
}

int main()
{
    // Test functions here
    return 0;
}
