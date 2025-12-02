#include <bits/stdc++.h>
using namespace std;

void better()
{
    string digits;
    cin >> digits; // Input le rahe hain string digits ke form mein
    int n = digits.size();
    vector<int> dp(n + 1, -1); // DP array initialize kiya -1 se

    function<int(int)> solve = [&](int i)
    {
        if (i == n)
            return 1; // Agar pura string process ho gaya to ek valid way mila
        if (digits[i] == '0')
            return 0; // Agar '0' aaya to uska koi decoding nahi ho sakta
        if (dp[i] != -1)
            return dp[i]; // Agar pehle se solve ho chuka hai to direct return karo

        int one = solve(i + 1); // Ek digit ko consider karke solve kar rahe hain
        int two = 0;
        if (i != n - 1 && (digits[i] == '1' || (digits[i] == '2' && digits[i + 1] <= '6')))
            two = solve(i + 2); // Do digits ko ek saath consider karke solve kar rahe hain

        return dp[i] = one + two; // DP array mein result store kar diya
    };

    cout << solve(0) << endl; // Final result print kar diya
}

int main()
{
    better();
    return 0;
}
