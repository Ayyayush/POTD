#include <bits/stdc++.h>
using namespace std;

/*
-----------------------------------------
recursive() -> optional: can be implemented using recursion + memo
-----------------------------------------
Yeh function implement kiya ja sakta hai agar tum recursion + memoization se
saare possible distributions nikalna chahte ho.

Parameters honge:
- index (kaunsa child dekh rahe ho)
- remaining candies
- current distribution

Har step pe 0 se limit tak iterate karo and recursion call karo next child ke liye.
Agar 3 children ho chuke aur remaining == 0 hai, toh valid configuration count karo.
*/

/*
-----------------------------------------
brute() -> Triple nested loop (O(n^3))
-----------------------------------------
Ye sabse basic method hai jisme hum teeno children (ch1, ch2, ch3) ke liye
0 se lekar `limit` tak values check karte hain. Saath hi ensure karte hain ki
unka sum `n` ke barabar ho.

Time Complexity: O(limit^3)
Space Complexity: O(1)
*/

void brute()
{
    int n, limit;
    cin >> n >> limit;

    int count = 0;

    // ch1, ch2, ch3 ko 0 se lekar limit tak values dene hain
    for (int ch1 = 0; ch1 <= min(limit, n); ch1++)
    {
        for (int ch2 = 0; ch2 <= min(limit, n - ch1); ch2++)
        {
            for (int ch3 = 0; ch3 <= min(limit, n - ch1 - ch2); ch3++)
            {
                // agar teeno ka sum == n hai, toh valid configuration hai
                if (ch1 + ch2 + ch3 == n)
                    count++;
            }
        }
    }
    cout << count << endl;
}

/*
-----------------------------------------
better() -> Optimized by eliminating inner loop
-----------------------------------------
Is version mein hum ch3 ko explicitly n - ch1 - ch2 se calculate karte hain
taaki ek loop kam ho jaaye.

Time Complexity: O(limit^2)
Space Complexity: O(1)
*/

void better()
{
    int n, limit;
    cin >> n >> limit;

    int count = 0;

    // ch1 aur ch2 fix kar ke, ch3 ko n - ch1 - ch2 se nikal lo
    for (int ch1 = 0; ch1 <= min(limit, n); ch1++)
    {
        for (int ch2 = 0; ch2 <= min(limit, n - ch1); ch2++)
        {
            int ch3 = n - ch1 - ch2;

            // agar ch3 bhi valid limit ke andar hai, toh count++
            if (ch3 >= 0 && ch3 <= limit)
                count++;
        }
    }

    cout << count << endl;
}

/*
-----------------------------------------
optimal() -> Stars and Bars + Inclusion-Exclusion (Mathematical Approach)
-----------------------------------------
Is version mein hum combinatorics ka use karte hain.

Total ways without limit:
  - Choose 3 non-negative integers x, y, z such that x + y + z = n
  - Formula: C(n+2, 2)

Lekin limit bhi hai, toh:

1. Total = C(n + 2, 2)
2. Subtract un cases ko jahan koi ek child > limit
   - 3 * C(n - (limit + 1) + 2, 2)
3. Add back cases jahan do children > limit (double subtract avoid karne ke liye)
   - 3 * C(n - 2*(limit + 1) + 2, 2)
4. Ignore cases where all 3 children > limit, kyunki n ≤ 3 * limit hamesha

Final formula:
ans = C(n+2, 2)
      - 3 * C(n - (limit + 1) + 2, 2)
      + 3 * C(n - 2*(limit + 1) + 2, 2)

Time Complexity: O(1)
Space Complexity: O(1)
*/

void optimal()
{
    // T.C. = O(1)      // S.C. = O(1)

    long long n, m;
    cin >> n >> m;     // n = total candies, m = max candies ek child ko mil sakti hai

    // Agar teeno children ko max m candies dene ke baad bhi n satisfy nahi hota
    // to koi valid distribution possible hi nahi hoga
    if (3 * m < n)
    {
        cout << 0 << endl;
        return;
    }

    // Step 1: Total ways to distribute n candies among 3 children without any limit
    // Ye standard combinatorics ka formula hai: C(n + 2, 2) = (n+2)*(n+1)/2
    long long total = ((n + 2) * (n + 1)) / 2;

    // Step 2: Ab subtract karo un cases ko jahan kisi child ko m se zyada milta hai
    // Ek child ko m se zyada mila toh uske paas kam se kam (m+1) candies hongi
    // Toh n - (m+1) candies bache do baaki ke liye
    long long a = n - (m + 1);
    if (a >= 0)
        a = ((a + 2) * (a + 1)) / 2;   // C(a+2, 2) ways
    else
        a = 0;

    // Step 3: Subtract double counted cases jahan do children limit cross karte hain
    // i.e., each got at least (m+1) candies → total at least 2*(m+1) candies use ho chuki
    long long b = n - 2 * (m + 1);
    if (b >= 0)
        b = ((b + 2) * (b + 1)) / 2;
    else
        b = 0;

    // Step 4: Add back cases where all 3 children cross the limit
    // i.e., sabke paas kam se kam (m+1) candies
    long long c = n - 3 * (m + 1);
    long long cWays = 0;
    if (c >= 0)
        cWays = ((c + 2) * (c + 1)) / 2;

    // Final Inclusion-Exclusion Formula:
    // total valid = total - 3*a + 3*b - cWays
    total = total - 3 * a + 3 * b - cWays;

    cout << total << endl;
}



void optimal()
{
    // T.C. = O(limit)       // S.C. = O(1)

    int n, limit;
    cin >> n >> limit;     // n = total candies, limit = max ek child ko mil sakta hai

    long long ways = 0;

    /*
        Hum 3 children ko candies dene wale hain
        Loop se child1 ko fix karenge (i candies denge), baaki bache hue (n-i) ko ch2 aur ch3 ke beech divide karenge
    */

    // child1 ko min se max possible candies assign karne ke liye range find karenge
    int minCh1 = max(0, n - 2 * limit);    // ch2 aur ch3 dono ko max limit tak dena h, to ch1 ko kam se kam ye dena padega
    int maxCh1 = min(n, limit);            // ch1 ko max limit tak hi de sakte ho

    for (int i = minCh1; i <= maxCh1; i++) // child1 ko i candies dekar fix kar rahe hain
    {
        int N = n - i;                    // ab bache hue candies ch2 aur ch3 ke liye hain

        // ch2 ko bhi 0 to limit ke beech hi de sakte hain
        int minCh2 = max(0, N - limit);   // ch3 ko kam se kam 0 aur max limit tak dena padega
        int maxCh2 = min(N, limit);       // ch2 ko bhi max limit tak hi dena chahiye

        // jitni bhi valid values ch2 ke liye hain, utni hi valid combinations banenge
        ways += maxCh2 - minCh2 + 1;
    }

    cout << ways << endl;
}

int main()
{
    optimal();
    return 0;
}
