#include <bits/stdc++.h>
using namespace std;

void brute()          // ascending
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> grid[i][j];
        }
    }

    map<int, vector<int>> diagonals; // Har ek diagonal ke elements ko store karne ke liye map

    // Har ek diagonal ke elements collect karna
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            diagonals[i - j].push_back(grid[i][j]);
        }
    }

    // Har ek diagonal ko sort karna
    for (auto &p : diagonals)
    {
        sort(p.second.begin(), p.second.end());
    }

    // Sorted elements wapas grid me dalna
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            grid[i][j] = diagonals[i - j].back();
            diagonals[i - j].pop_back();
        }
    }


    /*   for(int i = m-1; i>=0; i--) {
                for(int j = n-1; j>=0; j--) {
         */

    // Output sorted matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}


void better() 
{

}


void optimal()
{
    
}
int main()
{
    better();
    return 0;
}
