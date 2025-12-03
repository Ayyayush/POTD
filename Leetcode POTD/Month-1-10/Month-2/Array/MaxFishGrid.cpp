#include <bits/stdc++.h>
using namespace std;

void brute()      // O(N*N)
{
    int m, n, i, j, maxsum = 0;  
    cin >> m >> n;  // Matrix ka size input liya

    vector<vector<int>> grid(m, vector<int>(n, 0));  // 2D matrix initialize kiya

    // Grid input kar rahe hain
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }


    // Maximum fish collect karne ke liye loop chalayenge
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        { 
            int sum = 0;  // Har nayi jagah se sum initialize karna zaroori hai

            if (grid[i][j] > 0)  // Agar current cell me water hai
            {
                sum += grid[i][j];   // Current cell ki fish add kari
                maxsum = max(sum, maxsum);  

                // Right move possible hai kya?
                if (j + 1 < n && grid[i][j + 1] > 0)  
                {
                    sum += grid[i][j + 1];  // Right wale cell ki fish add kari
                    maxsum = max(sum, maxsum);  
                }

                // Down move possible hai kya?
                else if (i + 1 < m && grid[i + 1][j] > 0)
                {
                    sum += grid[i + 1][j];  // Niche wale cell ki fish add kari
                    maxsum = max(sum, maxsum);  
                }
            }
        }
    }

    cout << maxsum << endl;  // Maximum fish sum output kar rahe hain
}


void better()        //O(M*N)
{
    int m, n, i, j, maxsum = 0;
    cin >> m >> n;  // Matrix ka size input liya

    vector<vector<int>> grid(m, vector<int>(n, 0));  // 2D matrix initialize kiya

    // Grid input kar rahe hain
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    // Maximum fish collect karne ke liye loop chalayenge
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        { 
            if (grid[i][j] > 0)  // Agar current cell me water hai
            {
                int sum = 0;  // Har nayi jagah se sum initialize karna zaroori hai
                stack<pair<int, int>> st;
                st.push({i, j});  // Start position push kari



              while (!st.empty())  // poore cluster ko explore krne ke liye 
               {
    auto [x, y] = st.top();   // Top element ko pop karenge (current cell)
    st.pop();                   // Pop the element from stack

    if (grid[x][y] == 0) continue;  // Agar land cell hai, toh skip karo

    sum += grid[x][y];        // Fish collect karo
    grid[x][y] = 0;           // Mark the cell as visited

    // Adjacent cells check karo
    if (y + 1 < n && grid[x][y + 1] > 0) st.push({x, y + 1});
    if (y - 1 >= 0 && grid[x][y - 1] > 0) st.push({x, y - 1});
    if (x + 1 < m && grid[x + 1][y] > 0) st.push({x + 1, y});
    if (x - 1 >= 0 && grid[x - 1][y] > 0) st.push({x - 1, y});
}


                maxsum = max(maxsum, sum);  // Maximum fish update karo
            }
        }
    }

    cout << maxsum << endl;  // Maximum fish sum output kar rahe hain
}







int main()
{
    better();  // Function call kar diya
    return 0;
}
