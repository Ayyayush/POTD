#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(n + log_k(n!))
    // Space Complexity: O(1)
    // 🔍 Approach: Factorial Calculation + Highest Power of k dividing factorial

    int n, k;
    cout << "Enter value of n: ";
    cin >> n;                                                             // user input for n
    cout << "Enter value of k: ";
    cin >> k;                                                             // user input for k

    long long prod = 1;
    for (int i = 1; i <= n; i++)                                          // n! calculate kar rahe hain
    {
        prod *= i;
    }

    int highestpower = 1, count = 0;

    for (long long i = 1; i <= prod; i *= k)                              // loop chalayenge k^0, k^1, k^2 ... jab tak divide kar raha ho
    {
        if (prod % i == 0)                                                // agar n! % k^x == 0 hai, toh update karenge power
        {
            highestpower = count;
        }

        if (i > prod / k) break;                                          // overflow avoid karne ke liye check
        count++;
    }

    cout << "Maximum power of " << k << " that divides " << n << "! is: " << highestpower << endl;
}

int main()
{
    brute();
    return 0;
}
