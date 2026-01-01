#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Approach: Push pairs (i, -i) into array until n/2 times, 
    // if n is odd then add 0 at the end.
    // T.C. = O(n)       (because loop runs n/2 times)
    // S.C. = O(n)       (array of size n is used)

    int n = 5;                                      // hardcoded input
    vector<int> arr;                                // answer vector

    for (int i = 1; i <= n / 2; i++)                // loop till n/2
    {
        arr.push_back(i);                           // add positive i
        arr.push_back(-i);                          // add negative i
    }

    if (n % 2 != 0)                                 // if odd size
    {
        arr.push_back(0);                           // add 0
    }

    cout << "Brute Output: ";
    for (int x : arr) cout << x << " ";             // print result
    cout << endl;
}




void better()
{
    // Approach: Fill elements from both ends using two pointers.
    // T.C. = O(n)       (loop runs n/2 times)
    // S.C. = O(n)       (array of size n is used)

    int n = 6;                                      // hardcoded input
    vector<int> arr(n);                             // answer vector
    int elt = 1;                                    // element to place
    int i = 0, j = n - 1;                           // two pointers

    while (i < j)                                   // fill until pointers meet
    {
        arr[i] = elt;                               // left side positive
        arr[j] = -elt;                              // right side negative
        elt++;                                      // next element
        i++;                                        // move left pointer
        j--;                                        // move right pointer
    }

    if (n % 2 != 0)                                 // if odd size
    {
        arr[n / 2] = 0;                             // middle = 0
    }

    cout << "Better Output: ";
    for (int x : arr) cout << x << " ";             // print result
    cout << endl;
}

int main()
{
    brute();
    better();
    return 0;
}
