#include <bits/stdc++.h>
using namespace std;

void brute() 
{
    // Time Complexity: O(9 * n * sqrt(9)) → ≈ O(n*sqrt(9)*10^n) for all n-digit numbers
    // Space Complexity: O(1)

    const long long mod = 1e9 + 7;            	// Modulo constant
    long long count = 0;                      	// Good numbers ko count karne ke liye

    int n;
    cin >> n;                                  	// User se n-digit input lena hai

    for (long long i = pow(10, n - 1); i < pow(10, n); i++)  	// n-digit numbers ke liye loop
    {
        bool isgood = true;                   	// Assume karte hain ki number good hai
        string str = to_string(i);            	// Number ko string mein convert kar rahe hain

        for (long long j = 0; j < str.size(); j++)  	// Har digit ke liye check karenge
        {
            if (j % 2 == 0)                   	// Even index par hona chahiye even digit
            {
                if ((str[j] - '0') % 2 != 0)  	// Agar odd digit aayi to good nahi hai
                {
                    isgood = false;
                    break;
                }
            }
            else                              	// Odd index par hona chahiye prime digit
            {
                long long num = str[j] - '0';
                if (num <= 1) 
                {
                    isgood = false;          	// 0 aur 1 prime nahi hote
                    break;
                }
                for (long long k = 2; k * k <= num; k++) 
                {
                    if (num % k == 0) 
                    {
                        isgood = false;      	// Agar factor mila to prime nahi hai
                        break;
                    }
                }
                if (!isgood) break;
            }
        }

        if (isgood) 
        {
            count = (count + 1) % mod;        	// Count badhate waqt modulo lagao
        }
    }

    cout << count << endl;                    	// Final count print karo
}


void optimal()
{
    // Time Complexity: O(log n)       			// Kyunki fast exponentiation O(log n) mein hota hai
    // Space Complexity: O(log n) recursion stack	// Kyunki recursive fast power use kar rahe hain

    const int M = 1e9 + 7;        				// Modulo constant
    long long n; cin >> n;         				// Input string length

    function<int(long long, long long)> findPower = [&](long long a, long long b) -> int {
        if (b == 0) return 1;    				// Base case: power 0 ka matlab 1

        long long half = findPower(a, b / 2);   	// Recursive call
        long long result = (half * half) % M;  	// Square kar ke modulo

        if (b % 2 == 1)                         	// Agar odd power hai to ek baar aur multiply
            result = (result * a) % M;

        return result;
    };

    long long evenPos = (n + 1) / 2;     			// Even indices ke positions (0-based)
    long long oddPos = n / 2;           			// Odd indices ke positions

    long long ans = (1LL * findPower(5, evenPos) * findPower(4, oddPos)) % M;

    cout << ans << endl;                			// Final answer print karo
}


int main() 
{
    brute();
    return 0;
}
