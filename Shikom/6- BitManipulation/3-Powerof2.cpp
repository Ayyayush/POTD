#include <bits/stdc++.h>
using namespace std;

/*
🟩 PROBLEM: Check if a number is a Power of 2
*/

/*---------------------------------------------------------
                🟦 BRUTE FORCE APPROACH
  Approach: Keep multiplying 2 until we reach or exceed n
  Time Complexity: O(log n)               // repeatedly multiply
  Space Complexity: O(1)
---------------------------------------------------------*/
void brute() 
{
    long long n;
    cin >> n;                               // input

    long long x = 1;
    while (x < n) 
    {
        x *= 2;                              // multiply until >= n
    }

    if (x == n) cout << "YES\n";
    else cout << "NO\n";
}

/*---------------------------------------------------------
                🟩 BETTER APPROACH
   Approach: Repeatedly divide by 2 (works only for integers)
   Time Complexity: O(log n)                 // dividing repeatedly
   Space Complexity: O(1)
---------------------------------------------------------*/
void better() 
{
    long long n;
    cin >> n;

    if (n <= 0) 
    {
        cout << "NO\n"; 
        return;
    }

    while (n % 2 == 0) 
    {
        n /= 2;                               // keep dividing by 2
    }

    if (n == 1) cout << "YES\n";
    else cout << "NO\n";
}

/*---------------------------------------------------------
                🟩 OPTIMAL APPROACH
   Approach Name: Bit Manipulation  
   Concept: A power of 2 has only ONE set bit.
   Condition: (n & (n - 1)) == 0  
   Time Complexity: O(1)
   Space Complexity: O(1)
---------------------------------------------------------*/
void optimal() 
{
    long long n;
    cin >> n;

    if (n > 0 && (n & (n - 1)) == 0)          // (n & n-1) clears last set bit
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    return 0;
}
