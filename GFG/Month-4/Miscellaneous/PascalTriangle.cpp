#include <bits/stdc++.h>
using namespace std;

long long factorial(int n)                            // ✅ Return type long long for large values
{
    long long fact = 1;
    for (int i = n; i >= 1; i--)
    {
        fact *= i;
    }
    return fact;
}

void pandc()
{
    int n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;

    if (r > n)
    {
        cout << "Invalid input! r should be <= n\n";
        return;
    }

    long long nCr = factorial(n) / (factorial(r) * factorial(n - r));
    long long nPr = factorial(n) / factorial(n - r);

    cout << "nCr (Combination): " << nCr << endl;
    cout << "nPr (Permutation): " << nPr << endl;
}

void pascaltriangle()
{
    int n;
    cout << "Enter number of rows for Pascal's Triangle: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        // Print spaces for triangle formatting
        for (int space = 0; space < n - i - 1; space++)
            cout << " ";

        // Print values using nCr
        for (int j = 0; j <= i; j++)
        {
            long long val = factorial(i) / (factorial(j) * factorial(i - j));   // Binomial coefficient
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
   // pandc();              // Combination & Permutation demo
    pascaltriangle();     // Pascal's Triangle demo
    return 0;
}
