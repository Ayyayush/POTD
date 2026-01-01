#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(1)     (kyunki built-in multiplication)
    // Space Complexity: O(1)

    string num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    long long n1 = stoll(num1);         // string ko long long mein convert karo
    long long n2 = stoll(num2);         // string ko long long mein convert karo

    long long product = 1LL * n1 * n2;  // multiplication kar lo

    cout << "Product is: " << to_string(product) << endl;    // string form mein print
}

int main()
{
    brute();
    return 0;
}
