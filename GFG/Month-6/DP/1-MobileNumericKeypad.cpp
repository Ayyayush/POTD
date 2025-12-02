#include <bits/stdc++.h>
using namespace std;

#define endl '\n'               // endl ko newline character '\n' se define kiya gaya hai (zyada fast hota hai)
#define int long long           // Har jagah 'int' ko 'long long' maana jaayega (large values ke liye)
const int MOD = 1e9 + 7;        // Modulo constant (competitive programming me common hai)
const int INF = LLONG_MAX >> 1; // Infinity ke equivalent ek bada number (overflow se bachne ke liye half kiya gaya)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define u unordered_map<int, int>
#define f(i, n) for (int i = 0; i < n; i++)

void brute()
{
    /**
     * hume ek integer diya h keypad pe
     * kisi bhi number ke up down left aur right ko press kr skt eh
     * diagonal press karna aalowed nhi h
     * sabse pehle toh current button ko press kar skte h
     * firr ab total dekhne h kitne ko kr skta h
     * aur # press nhi kar skte
     * firr uske toal subseq nikalne h
     * maan  lo n==1 toh ...ek hi baar kr skt eh press
     * toh har button i.e 0-10  ek baar kr skt eh khud ko toh   total =10
     *
     * maan lo  n==2
     * ek button max 4 ko kar skta h
     * kitne combination unique subsequences aayenge dekhte h
     * maan lo 1 h toh uske left aur above toh h nhi bas right down h 2 and 4
     * toh wo bas 1 ke sath 2 ya 4 press kar skt h i.e two combinations
     * 0 bhi bas aise hi 8 i.e above ko press kar skta h
     * toh  aise  hi saare combinations ko dekhne pe answer aayega 36
     *
     *
     * saare directions ki condtions
     * up == i-1,j
     * down == i+1,j
     * left == i,j-1
     * right == i,j+1
     *
     *
     * Boundary Condition ..kha kha se aage nhi badh skte
     * i==3 && (j==0 || j==2)
     * i<0 || i>=4
     * j<0 || j>=3
     * return 0;
     *
     *
     *
     *
     */
}

class Solution
{
public:
    int solve(int i, int j, int n) // ❗ 'count' ko hata diya, aur n ko add kiya parameter mein
    {
        if (i < 0 || i >= 4 || j < 0 || j >= 3 || (i == 3 && (j == 0 || j == 2)))
        {
            return 0; // Invalid position
        }

        if (n == 1) // Base case: ek digit ka number
            return 1;

        int result = 0;

        result += solve(i, j, n - 1)        // Stay on same key
                  + solve(i - 1, j, n - 1)  // Up
                  + solve(i, j - 1, n - 1)  // Left
                  + solve(i, j + 1, n - 1)  // Right
                  + solve(i + 1, j, n - 1); // Down

        return result;
    }

    int getCount(int n)
    {
        int count = 0;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == 3 && (j == 0 || j == 2))
                    continue; // Skip '*' and '#' keys

                count += solve(i, j, n); // Add count from each valid key
            }
        }

        return count;
    }
};








class Solution
{
public:
    int dp[4][3][16];

    int solve(int i, int j, int n)
    {
        // invalid or forbidden cells (* and #)
        if (i < 0 || i >= 4 || j < 0 || j >= 3 ||
            (i == 3 && (j == 0 || j == 2)))
        {
            return 0;
        }

        // base case: sequence length 1 → only the current key
        if (n == 1)
        {
            return 1;
        }

        // return cached result if available
        if (dp[i][j][n] != -1)
        {
            return dp[i][j][n];
        }

        int result = 0;
        // stay in place
        result += solve(i, j, n - 1) +
                  // move up
                  solve(i - 1, j, n - 1) +
                  // move left
                  solve(i, j - 1, n - 1) +
                  // move right
                  solve(i, j + 1, n - 1) +
                  // move down
                  solve(i + 1, j, n - 1);

        // cache and return
        return dp[i][j][n] = result;
    }

    int getCount(int n)
    {
        int count = 0;

        // initialize memo table
        memset(dp, -1, sizeof(dp));
        // iterate over all starting cells
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                count += solve(i, j, n);
            }
        }
        return count;
    }
};

signed main()
{
    ios::sync_with_stdio(false); // Fast input/output ke liye syncing disable kar rahe hain
    cin.tie(NULL);               // cin ko cout se untie kar rahe hain taaki input/output aur fast ho jaye
    brute();

    return 0; // Program successful terminate ho raha hai
}
