/*
primlaity is checking ki number prime hai ya composoite

methods::=
brute
square root
sieve of erasthoneses
*/

#include <bits/stdc++.h> // Sabhi standard C++ libraries ko include kar deta hai
using namespace std;     // Standard namespace use karne ke liye (std:: likhne ki zarurat nahi)

#define endl '\n'               // endl ko newline character '\n' se define kiya gaya hai (zyada fast hota hai)
#define int long long           // Har jagah 'int' ko 'long long' maana jaayega (large values ke liye)
const int MOD = 1e9 + 7;        // Modulo constant (competitive programming me common hai)
const int INF = LLONG_MAX >> 1; // Infinity ke equivalent ek bada number (overflow se bachne ke liye half kiya gaya)

void brute()
{
    // using simple for loop
}

void better()
{
    // using square root method
}

void optimal()
{
    // seive of erasthoneses
    int n;
    cin >> n; // User se number input liya

    vector<bool> primes(n + 1, true); // Initially sabko prime maana
    primes[0] = primes[1] = false;    // 0 aur 1 prime nahi hote

    for (int i = 2; i * i <= n; i++) // i*i tak loop chalayenge for optimization
    {
        if (primes[i]) // Agar i prime hai
        {
            for (int j = i * i; j <= n; j += i) // i ke multiples ko mark kar do false
            {
                primes[j] = false;
            }
        }
    }

    for (int i = 0; i <= n; i++) // Ab prime number print kar rahe hain
    {
        if (primes[i])
        {
            cout << i << " is a prime number" << endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false); // Fast input/output ke liye syncing disable kar rahe hain
    cin.tie(NULL);               // cin ko cout se untie kar rahe hain taaki input/output aur fast ho jaye
    optimal();

    return 0; // Program successful terminate ho raha hai
}
