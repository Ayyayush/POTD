#include <bits/stdc++.h>
using namespace std;

void optimal()
{
    /*
        Approach Name  : Column-wise Lexicographical Check
        Time Complexity: O(n * m)    where n = number of strings, m = length of each string
        Space Complexity: O(1)
    */

    int n;
    cin >> n;                                      // number of strings

    vector<string> strs(n);
    for(int i = 0; i < n; i++)
    {
        cin >> strs[i];                            // input strings
    }

    int m = strs[0].size();                        // number of columns
    int count = 0;                                 // number of columns to delete

    for(int col = 0; col < m; col++)               // iterate column-wise
    {
        for(int row = 0; row < n - 1; row++)       // check adjacent rows
        {
            if(strs[row][col] > strs[row + 1][col]) // column not sorted
            {
                count++;                           // mark column for deletion
                break;                             // move to next column
            }
        }
    }

    cout << count;                                 // output result
}

int main()
{
    optimal();
    return 0;
}
