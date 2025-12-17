#include <bits/stdc++.h>
using namespace std;

/* =========================================================
   APPROACH: Brute Force (Using Temporary Variable)
   Time Complexity: O(1)
   Space Complexity: O(1)
   ========================================================= */
void brute()
{
    int a, b;
    cin >> a >> b;

    int temp = a;        // store value of a
    a = b;               // assign b to a
    b = temp;            // assign temp to b

    cout << a << " " << b;
}

/* =========================================================
   APPROACH: Better (Using Addition & Subtraction)
   Time Complexity: O(1)
   Space Complexity: O(1)
   ========================================================= */
void better()
{
    int a, b;
    cin >> a >> b;

    a = a + b;           // sum of a and b
    b = a - b;           // b becomes original a
    a = a - b;           // a becomes original b

    cout << a << " " << b;
}

/* =========================================================
   APPROACH: Optimal (Bit Manipulation using XOR)
   Time Complexity: O(1)
   Space Complexity: O(1)
   ========================================================= */
void optimal()
{
    int a, b;
    cin >> a >> b;

    a = a ^ b;           // step 1: store XOR of a and b in a
    b = a ^ b;           // step 2: b becomes original a
    a = a ^ b;           // step 3: a becomes original b

    cout << a << " " << b;
}

/* ================= MAIN FUNCTION ================= */
int main()
{
    optimal();           // change to brute() or better() if needed
    return 0;
}
