#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // APPROACH: Brute Force (3 Loops)
    // T.C: O(n^3)
    // S.C: O(1)

    int n;
    cin >> n;                                         // taking input

    int count = 0;                                    // counter

    for (int i = 1; i <= n; i++)                      // first number
    {
        for (int j = 1; j <= n; j++)                  // second number
        {
            for (int k = 1; k <= n; k++)              // third number
            {
                int s1 = i * i;                       // square of i
                int s2 = j * j;                       // square of j
                int s3 = k * k;                       // square of k

                if (s1 + s2 == s3)                    // check a^2 + b^2 = c^2
                    count++;
            }
        }
    }

    cout << count << endl;                            // print result
}


void better()
{
    // APPROACH: Fix c and loop for a,b only
    // T.C: O(n^2 * sqrt(n)) approx → faster than brute
    // Actually O(n^2)
    // S.C: O(1)

    int n;
    cin >> n;

    int count = 0;

    for (int c = 1; c <= n; c++)                       // fix hypotenuse
    {
        int c2 = c * c;

        for (int a = 1; a <= n; a++)                   // loop for 'a'
        {
            int a2 = a * a;

            int b2 = c2 - a2;                          // b² = c² - a²

            int b = sqrt(b2);                          // get possible b

            if (b >= 1 && b <= n && b * b == b2)       // check valid perfect square
                count++;
        }
    }

    cout << count << endl;
}


void optimal()
{
    // APPROACH: Precompute squares + Use hashing
    // T.C: O(n^2)
    // S.C: O(n)

    int n;
    cin >> n;

    unordered_set<int> squares;                        // store all squares 1²..n²
    for (int i = 1; i <= n; i++)
    {
        squares.insert(i * i);
    }

    int count = 0;

    for (int a = 1; a <= n; a++)                       // loop for a
    {
        for (int b = 1; b <= n; b++)                   // loop for b
        {
            int s = a * a + b * b;                     // a² + b²

            if (squares.count(s))                      // check if c² exists
                count++;
        }
    }

    cout << count << endl;
}


int main()
{
    return 0;
}
