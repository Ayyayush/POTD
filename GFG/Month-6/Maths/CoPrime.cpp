#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Approach: Brute Force with GCD check
    // T.C. = O(N^2), S.C. = O(1)

    int n;                                       // input size of the array
    cin >> n;

    vector<int> arr(n);                          // input array
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int count = 0;                               // count of co-prime pairs

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int gcd = __gcd(arr[i], arr[j]);     // find gcd of arr[i] and arr[j]
            if (gcd == 1)
                count++;                         // if gcd == 1, they are co-prime
        }
    }

    cout << count << endl;                       // print total co-prime pairs
}

int main()
{
    brute();
    return 0;
}
