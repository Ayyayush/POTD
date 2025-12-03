#include <bits/stdc++.h>
using namespace std;



/*
maan lo 3*3 ka grid h 
direction h left ,right ,up down
maan lo pehle box mein koi bhi color daala firr aage badh gya 
iss approach mein problem ye h ki immmense possibilties banti h 
maan lo humne pehle row ka pattern decid ekr liya jaise R,G,B 
isse hume ye pata chal jaygteva ki mniche wale row mein kaun sa rakhna h kaunn sa nhi rakhna h 
so pehle decid ekaro ki pehle row ki kitni possibnilities h i.e::=
rgb,rbg,brg,bgr,grb,gbr  == 6 posibilities
direct == 3 charcters hai toh 3*2*1 =6     == combinations
given max rows ==5 ,  max column==1000
rowwise  ki jageh pehle columnwie  fix kr dete h ..kyunki row chota h 
3 steps mein solve hoga ab
1>
finding column states
hum columnwise isliye chal rhe h left to right...
....kyunki rows max to max 5 h toh string ka length max 5 hoga columnwise
length=no of rows
columnstates={rgb,....}
void generatestates(currstate,l,previous)
{
if(length==no of row)
{
columnstates.push_back(currstack);
return;
}

}
)
}



2>

for(char ch: {'R','G','B'}
{
if(ch==prevcolor)}
{
continue;
generatestates(currstate+ch,l+1,ch)



3>
solve(int prevstate,int remaincols)
{
if(remaincols==0)
{
return 1;        // we found 1 way
string prevstate=columnstates[previdx];
}
}


*/
class Solution {
public:
    vector<vector<int>> t;					// Memoization table
    vector<string> columnStates;			// Valid column states
    const int MOD = 1e9 + 7;

    // Function to generate all valid vertical column patterns of height m
    void generateColumnStates(string currentColumn, int rowsRemaining, char prevColor) {
        if (rowsRemaining == 0) {
            columnStates.push_back(currentColumn);				// valid column ban gaya
            return;
        }

        for (char color : {'R', 'G', 'B'}) {
            if (color == prevColor) continue;					// same color avoid karo vertically
            generateColumnStates(currentColumn + color, rowsRemaining - 1, color);
        }
    }

    // Recursive DP function to count ways for remainingCols given prevColumnIdx
    int solve(int remainingCols, int prevColumnIdx, int m) {
        if (remainingCols == 0) return 1;						// base case: sab columns fill ho gaye

        if (t[remainingCols][prevColumnIdx] != -1)				// memoization check
            return t[remainingCols][prevColumnIdx];

        int totalWays = 0;
        string prevColumn = columnStates[prevColumnIdx];

        for (int nextColumnIdx = 0; nextColumnIdx < columnStates.size(); nextColumnIdx++) {
            string nextColumn = columnStates[nextColumnIdx];

            bool valid = true;
            for (int r = 0; r < m; r++) {
                if (prevColumn[r] == nextColumn[r]) {			// adjacent horizontal cells match na ho
                    valid = false;
                    break;
                }
            }

            if (valid) {
                totalWays = (totalWays + solve(remainingCols - 1, nextColumnIdx, m)) % MOD;
            }
        }

        return t[remainingCols][prevColumnIdx] = totalWays;
    }

    int colorTheGrid(int m, int n) {
        columnStates.clear();									// har test ke liye clear
        generateColumnStates("", m, '#');						// '#' = koi pehla color nahi

        int numPatterns = columnStates.size();
        t.assign(n, vector<int>(numPatterns, -1));				// DP table initialize

        int result = 0;
        for (int i = 0; i < numPatterns; i++) {
            result = (result + solve(n - 1, i, m)) % MOD;		// pehle column ke liye har valid option try karo
        }

        return result;
    }
};

void brute()
{
    int m, n;
    cin >> m >> n;

    Solution obj;
    cout << obj.colorTheGrid(m, n) << endl;
}

int main()
{
    brute();
    return 0;
}
