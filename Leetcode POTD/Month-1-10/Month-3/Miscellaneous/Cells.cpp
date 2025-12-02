#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // T.C : O(n), S.C : O(1)   --> Loop chalega n tak, isliye O(n) time lagega. Space constant hai.
    int n;
    cin >> n;
    int t = 1;
    long long cells = 1;

    while (t <= n)
    {
        cells += (4 * (t - 1)); // Har step pe 4*(t-1) cells badh rahe hain.
        t++;
    }

    cout << cells << endl;
}

void optimal()
{
    // T.C : O(1), S.C : O(1)   --> Direct formula use ho raha hai, isliye time constant hai.
    int n;
    cin >> n;
    cout << 1 + (2 * (long long)(n - 1) * n) << endl; // Formula: 1 + 2*(n-1)*n
}

int main()
{
    return 0;
}
