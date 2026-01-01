#include <bits/stdc++.h> // Sabhi standard C++ libraries ko include kar deta hai
using namespace std;     // Standard namespace use karne ke liye (std:: likhne ki zarurat nahi)

#define endl '\n'               // endl ko newline character '\n' se define kiya gaya hai (zyada fast hota hai)
#define int long long           // Har jagah 'int' ko 'long long' maana jaayega (large values ke liye)
const int MOD = 1e9 + 7;        // Modulo constant (competitive programming me common hai)
const int INF = LLONG_MAX >> 1; // Infinity ke equivalent ek bada number (overflow se bachne ke liye half kiya gaya)

void naive()
{
    // o(n^3)
    // jab bhi 0 mile toh uss row ke starting se leke end tak -1 kar do
    // uss column ke starting se leke end tak -1 kar do
    // jab elk baar sabkuch ho jaye toh -1 ko 0 bana do
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> temp = matrix; // original matrix ko copy kar liya

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int k = 0; k < n; k++)
                {
                    temp[i][k] = 0; // pura row zero kar diya
                }
                for (int k = 0; k < m; k++)
                {
                    temp[k][j] = 0; // pura column zero kar diya
                }
            }
        }
    }

    matrix = temp; // final result temp mein store hai

    cout << "Modified Matrix:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void brute() // O(N^2)
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    vector<int> vecrow, veccolumn;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 0)
            {
                vecrow.push_back(i);
                veccolumn.push_back(j);
            }
        }
    }

    // Row-wise zero
    for (int i = 0; i < vecrow.size(); i++)
    {
        for (int col = 0; col < n; col++)
        {
            matrix[vecrow[i]][col] = 0;
        }
    }

    // Column-wise zero
    for (int i = 0; i < veccolumn.size(); i++)
    {
        for (int row = 0; row < m; row++)
        {
            matrix[row][veccolumn[i]] = 0;
        }
    }

    // Output
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void better()
{
    // hume bas itna jaana h ki kis row mein elt 0 h bas usko store karenge
    // baad mein unn values ko leke 0 bnayenge
    // ek row naam ka vector row size ka  ...jisme sab false
    // ek column naam ka vector column size ka ...jisme sab false
    // traverse krte time jis postion pe 0 mile usko row aur column vector mein true karo
    // 2D matrix ko ab firr se traverse karenge
    // jis postition pe honge uske according row aur column vector ko dekhnge
    // agar true hua toh 0 bnate hue chalenge
    // ye mere better approach se milta julta h

    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<bool> row(m, false); // row[i] true hoga agar us row mein koi 0 mila
    vector<bool> col(n, false); // col[j] true hoga agar us column mein koi 0 mila

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = true; // mark kar diya row
                col[j] = true; // mark kar diya column
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] || col[j])
            { // agar row ya column mark hai toh cell 0 banado
                matrix[i][j] = 0;
            }
        }
    }

    cout << "Modified Matrix:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void optimal() // Constant space approach
{

    // ab hum traverse karenge 
    // har elt jo hume mile bta sake ki khi wo impacted hai ki nhi 
     // maan lo mat[i][j] hume 0 mila toh ab
     // mat[i][0]   ko 0 mark kar denge
     // mat [0][j] ko 0 mark kar denge
     // ab isse hoga ye ki inplace 0 bna payega
     // jiase jaise 0 milega first row ya column mein uss row ya column ko 0 bnate chalenge 
     // ab kya karenge ki har elt pe puchneg ki uska first row ya column impacted h kya
     // agar hai impacted toh 0 bnate chalenge
     // but aisa krne se kbhi kbhi ye problmec hogi ki 
     // jis row[i][0] ko 0 bnaya usme row ke agle elts bhi first elt 0 dekh kar 0 bnanne lagenge
     // toh aisa karenge traversal ke time ki first row aur first column ko chor ke traverse karenge 
     // mtlb 1,1  se traversal start hoga ...par checking mein 0,0 valid h 

// Conclusion to avoid corner case
// Travewrse 1st row and 1st column to check impacted
// 2nd traversal mein 1st row aur 1st column ko exclude karo 
// Finally if 1st row or col ......impacted then 0 
    int m, n;
    cin >> m >> n;                             // matrix ka size input lo
    vector<vector<int>> matrix(m, vector<int>(n));

    for(int i = 0; i < m; i++)                 // matrix input lo
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    bool firstRowImpacted = false;
    bool firstColImpacted = false;

    // check karo agar pehli row mein koi zero hai
    for (int col = 0; col < n; col++) {
        if (matrix[0][col] == 0) {
            firstRowImpacted = true;
            break;
        }
    }

    // check karo agar pehli column mein koi zero hai
    for (int row = 0; row < m; row++) {
        if (matrix[row][0] == 0) {
            firstColImpacted = true;
            break;
        }
    }

    // first row & column ko marker ke roop mein use karo
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;             // row marker
                matrix[0][j] = 0;             // column marker
            }
        }
    }

    // markers ke base par zero set karo
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // agar first row impacted thi toh usse bhi zero karo
    if (firstRowImpacted) {
        for (int col = 0; col < n; col++) {
            matrix[0][col] = 0;
        }
    }

    // agar first column impacted thi toh usse bhi zero karo
    if (firstColImpacted) {
        for (int row = 0; row < m; row++) {
            matrix[row][0] = 0;
        }
    }

    // final matrix print karo
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}



signed main()
{
    ios::sync_with_stdio(false); // Fast input/output ke liye syncing disable kar rahe hain
    cin.tie(NULL);               // cin ko cout se untie kar rahe hain taaki input/output aur fast ho jaye
    brute();

    return 0; // Program successful terminate ho raha hai
}
