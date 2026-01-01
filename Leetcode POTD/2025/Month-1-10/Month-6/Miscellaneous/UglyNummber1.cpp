#include <bits/stdc++.h>
using namespace std;

void naive()
{
    // number lo aur uske factor check karo auer store karo
    // factors mein agar koi bhi factor 2,3,5 ke alawa prime hua toh not ugly
}

void better()
{
    int n;
    cin >> n;

    if (n <= 0 || n > 1e7)
    {
        cout << "false\n"; // input validation
        return;
    }

    vector<bool> primes(n + 1, true); // n+1 size ka sieve
    primes[0] = primes[1] = false;    // 0 aur 1 prime nahi hote

    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = false; // sieve mark karna
            }
        }
    }

    for (int i = 7; i <= n; i++)
    { // 2,3,5 allowed hote hain, isliye 7 se check karo
        if (primes[i] && n % i == 0)
        {
            cout << "false\n"; // agar koi extra prime factor mila
            return;
        }
    }

    cout << "true\n"; // sirf 2,3,5 ke factors hain
}

void optimal()
{
    int n;
    cin >> n;

    if (n <= 0)
    {
        cout << "false\n"; // zero ya negative number allowed nahi
        return;
    }

    while (n % 2 == 0)
        n /= 2; // 2 se divide karte raho
    while (n % 3 == 0)
        n /= 3; // 3 se divide karte raho
    while (n % 5 == 0)
        n /= 5; // 5 se divide karte raho

    if (n == 1)
        cout << "true\n"; // agar last me 1 bacha to ugly number hai
    else
        cout << "false\n"; // agar kuch aur bacha to prime factor 2,3,5 ke alawa hai
}

int main()
{
    better();
    optimal();
    return 0;
}
