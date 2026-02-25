#include <bits/stdc++.h>
using namespace std;

/**
 * Problem : Sort Integers by The Number of 1 Bits
 * Platform: LeetCode
 *
 * Company Tags :
 * Amazon, Google, Microsoft
 */

/*
-------------------------------------------------
Approach 1 : Brute Force
Idea      : For every element, manually count set bits
            using repeated division by 2.
            Store (bitCount, value) and sort.
T.C       : O(n log n * log value)
S.C       : O(n)
-------------------------------------------------
*/
void brute()
{
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    vector<pair<int, int>> bitvector;

    for (int i = 0; i < arr.size(); i++)
    {
        int num = arr[i];
        int bits = 0;

        while (num > 0)
        {
            bits += (num % 2);
            num /= 2;
        }

        bitvector.push_back({bits, arr[i]});
    }

    sort(bitvector.begin(), bitvector.end());

    for (int i = 0; i < arr.size(); i++)
        arr[i] = bitvector[i].second;

    cout << "Brute Output : ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

/*
-------------------------------------------------
Approach 2 : Better
Idea      : Use built-in __builtin_popcount()
            to count set bits faster.
T.C       : O(n log n)
S.C       : O(n)
-------------------------------------------------
*/
void better()
{
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    vector<pair<int, int>> bitvector;

    for (int i = 0; i < arr.size(); i++)
    {
        int bits = __builtin_popcount(arr[i]);
        bitvector.push_back({bits, arr[i]});
    }

    sort(bitvector.begin(), bitvector.end());

    for (int i = 0; i < arr.size(); i++)
        arr[i] = bitvector[i].second;

    cout << "Better Output : ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

/*
-------------------------------------------------
Approach 3 : Optimal
Idea      : Same as better; this is the optimal
            approach accepted in interviews.
T.C       : O(n log n)
S.C       : O(n)
-------------------------------------------------
*/
void optimal()
{
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    vector<pair<int, int>> bitvector;

    for (int i = 0; i < arr.size(); i++)
    {
        bitvector.push_back({__builtin_popcount(arr[i]), arr[i]});
    }

    sort(bitvector.begin(), bitvector.end());

    for (int i = 0; i < arr.size(); i++)
        arr[i] = bitvector[i].second;

    cout << "Optimal Output : ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main()
{
    brute();
    better();
    optimal();
    return 0;
}

/*
-------------------------------------------------
JavaScript Optimal (for interview reference)

arr.sort((a, b) => {
    let diff = a.toString(2).split('1').length -
               b.toString(2).split('1').length;
    return diff === 0 ? a - b : diff;
});

-------------------------------------------------
Python Optimal (for interview reference)

arr.sort(key=lambda x: (bin(x).count('1'), x))

-------------------------------------------------
*/