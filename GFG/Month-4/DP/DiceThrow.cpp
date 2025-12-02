#include <bits/stdc++.h>
using namespace std;



void brute()
{
    int m, n, x;
    cin >> m >> n >> x;   // Input le rahe hain

    function<int(int, int, int, int)> solve = [&](int m, int n, int x, int sum) -> int {
        if(n == 0) return (sum == x) ? 1 : 0;   // Base case: agar n dice use ho chuke aur sum x ke equal hai

        int ways = 0;
        for(int i = 1; i <= m; i++)             // Har dice face ko try kar rahe hain
        {
            if(sum + i <= x)                    // Agar sum limit ke andar hai to hi call karo
            {
                ways += solve(m, n - 1, x, sum + i);   // Recursive call with remaining dice
            }
        }
        return ways;
    };

    int ans = solve(m, n, x, 0);                // Initial call
    cout << ans << endl;                        // Answer print karo
}




vector<vector<int>> dp;    // DP table globally bana di for simplicity
int m, n, x;               // Inputs bhi globally define kar diye

int solve(int dice, int sum)
{
    if(dice == 0) return (sum == x);              // Base case
    if(dp[dice][sum] != -1) return dp[dice][sum]; // Memoization check

    int ways = 0;
    for(int face = 1; face <= m; face++)          // 1 se m tak dice ke face try karo
        if(sum + face <= x)                       // Valid sum ke liye hi call karo
            ways += solve(dice - 1, sum + face);  // Recursive call

    return dp[dice][sum] = ways;                  // Store and return
}

void better()
{
    cin >> m >> n >> x;                           // Input le lo

    dp.assign(n + 1, vector<int>(x + 1, -1));     // DP table initialize karo

    cout << solve(n, 0) << endl;                  // Initial call aur answer print
}

// T.C. => O(n * x * m)     (dice * sum * options per dice)

int main()
{
    better();
    return 0;
}
