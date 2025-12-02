#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

void brute()    
{
    // T.C. => O(n * logn), S.C. => O(1)
    // Approach: Brute force all consecutive triplets and find max LCM

    int n;
    cin >> n;

    long long maximum = 0;

    for (long long i = 1; i <= n - 2; i++) {
        long long a = i;
        long long b = i + 1;
        long long c = i + 2;

        long long lcm_ab = lcm(a, b);                   // pehle do ka LCM
        long long lcm_abc = lcm(lcm_ab, c);             // fir uska c ke saath

        maximum = max(maximum, lcm_abc);                // update max
    }

    cout << maximum << endl;
}

void better()    
{
    // T.C. => O(1), S.C. => O(1)
    // Approach: Use property that max LCM lies among top 4 elements only

    int n;
    cin >> n;

    long long ans = 0;

    if (n < 3) {
        cout << n << endl;
        return;
    }

    // Try top 3 values (n, n-1, n-2)
    ans = max(ans, lcm(lcm(n, n - 1), n - 2));

    // Try (n, n-1, n-3)
    if (n > 3) ans = max(ans, lcm(lcm(n, n - 1), n - 3));

    // Try (n, n-2, n-3)
    if (n > 3) ans = max(ans, lcm(lcm(n, n - 2), n - 3));

    cout << ans << endl;
}

void optimal()    
{
    // T.C. => O(1), S.C. => O(1)
    // Approach: Pure math-based greedy method using product idea
    
    int n;
    cin >> n;

    if (n < 3) {
        cout << n << endl;
        return;
    }

    if (n & 1) {
        // Odd n => (n * (n-1) * (n-2)) gives max LCM
        cout << 1LL * n * (n - 1) * (n - 2) << endl;
    }
    else if (n % 3 != 0) {
        // Even but not divisible by 3 => skip even pair (n-2)
        cout << 1LL * n * (n - 1) * (n - 3) << endl;
    }
    else {
        // Even and divisible by 3 => skip n
        cout << 1LL * (n - 1) * (n - 2) * (n - 3) << endl;
    }
}

int main()
{
    brute();
    better();
    optimal();
    return 0;
}
