#include <bits/stdc++.h>
using namespace std;

#define endl '\n'                    // endl ko '\n' se replace kiya gaya hai kyunki yeh zyada fast hota hai
#define int long long               // Har jagah pe 'int' ko 'long long' maana jaayega (bade input handle karne ke liye)
const int MOD = 1e9 + 7;             // Modulo constant (often used in competitive programming to avoid overflow)
const int INF = LLONG_MAX >> 1;     // LLONG_MAX ko half kiya gaya hai (overflow se bachne ke liye)


// 🔁 Recursive function with memoization
int recurMemo(int index, int canBuy, int remainingTransactions, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    // 🧱 BASE CASE:
    if (index == prices.size() || remainingTransactions == 0)
        return 0;

    if (dp[index][canBuy][remainingTransactions] != -1)
        return dp[index][canBuy][remainingTransactions];

    int profit = 0;

    if (canBuy)
    {
        // 🔽 Option 1: Buy karo
        int buy = -prices[index] + recurMemo(index + 1, 0, remainingTransactions, prices, dp);

        // 🔼 Option 2: Kuch na karo
        int skip = recurMemo(index + 1, 1, remainingTransactions, prices, dp);

        profit = max(buy, skip);    // Maximum profit choose karo
    }
    else
    {
        // 🔼 Option 1: Sell karo
        int sell = prices[index] + recurMemo(index + 1, 1, remainingTransactions - 1, prices, dp);

        // 🔼 Option 2: Kuch na karo
        int skip = recurMemo(index + 1, 0, remainingTransactions, prices, dp);

        profit = max(sell, skip);   // Maximum profit choose karo
    }

    return dp[index][canBuy][remainingTransactions] = profit;     // Memoize result
}


// 🔍 Function: better()
// Yeh function "Buy and Sell Stock V" problem ke base logic ka explanation likhne ke liye banaya gaya hai.
// Recursive + DP approach ka base plan yahaan explain kiya gaya hai.

void better()
{
    // ✅ PROBLEM: Buy and Sell Stock V (At most k transactions allowed)

    // 💡 Example situation:
    // prices = [3, 2, 6, 5, 0, 3], k = 2
    // Hum maximum 2 transactions kar sakte hain (ek transaction = buy + sell)
    // Ek din pe buy aur sell dono ek saath nahi kar sakte
    // Aur jis din pe sell kiya usi din dobara buy shuru nahi kar sakte

    // 🔁 Har din ke liye 3 options honge:
    // 1. Kuch bhi na karein (Do Nothing)
    // 2. Buy karein
    // 3. Sell karein

    // 🔄 Recursion likhenge har din ke liye saare choices explore karne ke liye

    // 🤔 3 cheezein track karna zaroori hai:
    // - index (hum kis din pe hain)
    // - remainingTransactions (abhi aur kitne transaction kar sakte hain)
    // - ongoingStatus (currently koi transaction chal raha hai ya nahi)

    // 🔢 ongoingStatus ke 3 states ho sakte hain:
    // 0 → No transaction in progress (Free state)
    // 1 → Buy ho chuka hai, ab sell karna possible hai
    // 2 → Invalid state (agar kisi logic mein define kiya ho, usually not needed)

    // 🧱 BASE CASE:
    // Agar last index pe pahuch gaye toh:
    // - Agar koi transaction chal raha hai, toh use close kar sakte hain (sell kar ke)
    // - Agar koi transaction nahi chal raha toh kuch nahi karna (profit = 0)

    // 🧩 PLAN:
    // Har step pe recursion se sare options explore karenge aur max profit choose karenge
    // DP ka use karke overlapping subproblems avoid karenge

    // 🔢 INPUT le rahe hain prices array ka
    int n, k;
    cin >> n >> k;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];             // Price of stock on day i
    }

    // 📦 3D DP Table: dp[index][canBuy][remainingTransactions]
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));

    // 🎯 Start from index 0, canBuy = 1 (matlab buy allowed hai), remainingTransactions = k
    int maxProfit = recurMemo(0, 1, k, prices, dp);

    // 📤 Output final result
    cout << "Maximum Profit with at most " << k << " transactions = " << maxProfit << endl;
}


signed main()
{
    ios::sync_with_stdio(false);     // Fast I/O: C++ stream ko C stream se unsync kar diya
    cin.tie(NULL);                   // cin ko cout se untie kar diya (taaki fast ho jaye)

    better();                        // better() function call kar rahe hain (currently logic explanation only)

    return 0;                        // Program safalta se terminate ho gaya
}
