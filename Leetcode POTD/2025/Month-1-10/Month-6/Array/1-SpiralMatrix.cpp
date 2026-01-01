#include <bits/stdc++.h>            
using namespace std;                

#define endl '\n'                    // endl ko newline character '\n' se define kiya gaya hai (zyada fast hota hai)
#define int long long               // Har jagah 'int' ko 'long long' maana jaayega (large values ke liye)
const int MOD = 1e9 + 7;             // Modulo constant (competitive programming me common hai)
const int INF = LLONG_MAX >> 1;     // Infinity ke equivalent ek bada number (overflow se bachne ke liye half kiya gaya)

void brute()
{
    vector<vector<int>> nums = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13,14, 15, 16}
    };

    // first column left h ...last column right h 
    // ek top variable lenge jo first row ko point karega
    // down variable last row ko point karega 
    // top ke saare elts print ho jaye firr  top++ kar do
    // jis column mein khtm hua niche aake ussi column ke elt ko print karna h toh same col
    // firr ussi last ke column ko bas print karte rahenge  last row se ek pehle tak
    // last row mein piche se aage print karenge ..right -- krke 
    // firr last row ka sab print ho jaye firr down -- karenge 
    // firr same process repeat hona shuru hoga bas jo row column ho chuka h 
    // wo wapas se traverse nhi hoga 
    // har traversal mein ek chiz const hogi 
    // jis uss traversal ke baad change/shift krna hoga 
    // 4 directions hi h right,down,left,up 
    // directions naame ka varibale le lenge 
    // dir 0 h mtlb right ..1 h mtlb down
    // 2 hai mtlb left ... 3 mtlb up 
    // jab dir 3 ho jaye toh firr se usko 0 kar denge 

    int m = nums.size();               // rows
    int n = nums[0].size();            // columns

    int top = 0;                       // topmost row index
    int bottom = m - 1;                // bottommost row index
    int left = 0;                      // leftmost column index
    int right = n - 1;                 // rightmost column index

    int dir = 0;                       // 0->right, 1->down, 2->left, 3->up

    vector<int> result;               // final result store hoga yahan

    while (top <= bottom && left <= right)     // jab tak valid boundaries hain
    {
        if (dir == 0) // move left to right on top row
        {
            for (int i = left; i <= right; i++)
                result.push_back(nums[top][i]);
            top++;     // top row ho gayi, ab neeche move karo
        }
        else if (dir == 1) // move top to bottom on right column
        {
            for (int i = top; i <= bottom; i++)
                result.push_back(nums[i][right]);
            right--;   // right column ho gayi, ab left shift karo
        }
        else if (dir == 2) // move right to left on bottom row
        {
            for (int i = right; i >= left; i--)
                result.push_back(nums[bottom][i]);
            bottom--;  // bottom row ho gayi, ab upar jao
        }
        else if (dir == 3) // move bottom to top on left column
        {
            for (int i = bottom; i >= top; i--)
                result.push_back(nums[i][left]);
            left++;    // leftmost column ho gayi, ab right shift
        }

        dir = (dir + 1) % 4;   // direction ko cycle karo
    }

    // output result to check
    for (auto x : result)
        cout << x << " ";
    cout << endl;
}


signed main()
{
    ios::sync_with_stdio(false);     // Fast input/output ke liye syncing disable kar rahe hain
    cin.tie(NULL);                   // cin ko cout se untie kar rahe hain taaki input/output aur fast ho jaye
    brute();

    return 0;                        // Program successful terminate ho raha hai
}
