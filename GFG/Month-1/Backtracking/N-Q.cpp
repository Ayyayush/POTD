#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;
vector<string> board;
int n;

// Function to check ki queen ko iss position pe rakhna safe hai ya nahi
bool isSafe(int row, int col)
{
    // Check karo same column mein koi queen hai ya nahi
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false; // Agar queen mil gayi, toh safe nahi hai
        }
    }

    // Check karo left diagonal pe koi queen hai ya nahi
    int i = row, j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j--;
    }

    // Check karo right diagonal pe koi queen hai ya nahi
    i = row, j = col;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j++;
    }

    return true; // Agar koi bhi attack nahi ho raha, toh safe hai
}


// Backtracking ka function jo solutions find karega
void solve(int row)
{
    // Base case: Agar saari rows fill ho gayi, toh ek valid configuration mil gayi
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    // Har column pe queen rakhne ki koshish karo
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 'Q'; // Queen rakh do
            solve(row + 1); // Next row ke liye recursion call karo
            board[row][col] = '.'; // Backtracking, queen hata do
        }
    }
}


// Function to solve N-Queens problem
vector<vector<string>> solveNQueens(int queens)
{
    n = queens;
    ans.clear(); // Solutions store karne ke liye
    board.assign(n, string(n, '.')); // Empty board initialize karo
    solve(0); // Recursive function call karo
    return ans;
}


int main()
{
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    // Print karo saare solutions
    for (auto board : solutions)
    {
        for (auto row : board)
        {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
