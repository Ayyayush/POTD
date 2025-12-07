#include <bits/stdc++.h>
using namespace std;

void brute()     // Approach: Checking every number     T.C = O(N)     S.C = O(1)
{
    int low, high;
    cin >> low >> high;                    // input inside function (your preference)

    int count = 0;                         // count odds

    for(int i = low; i <= high; i++)       // loop from low to high
    {
        if(i % 2 != 0)                     // odd check
            count++;                       // increment
    }

    cout << count << endl;                 // output  
}

void better()    // Approach: Odd count using math but with conditions     T.C = O(1)     S.C = O(1)
{
    int low, high;
    cin >> low >> high;                    // input

    int count = 0;                         

    count += (high - low) / 2;             // half of the numbers are odd approx      (complex line)      // divides the range size by 2 giving approximate odd count

    if(low % 2 != 0 && high % 2 != 0)      // both odd
        count++;                            // add 1

    else if(low % 2 != 0 || high % 2 != 0) // one is odd
        count++;                            // add 1

    cout << count << endl;                 
}

void optimal()   // Approach: Pure Mathematical Formula     T.C = O(1)     S.C = O(1)
{
    int low, high;
    cin >> low >> high;                    // input

    // count of odds = (high+1)/2 - low/2      (complex line)
    // Explanation: number of odds till X is (X+1)/2, so subtract for range

    int result = (high + 1) / 2 - low / 2;  

    cout << result << endl;                
}

int main()
{
    // call whichever you want to test
    // brute();
    // better();
    optimal();

    return 0;
}
