#include <bits/stdc++.h>
using namespace std;

/* =========================================================
   APPROACH: Brute Force (Nested Loops)
   Time Complexity: O(n^2)
   Space Complexity: O(1)
   ========================================================= */
void brute()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        if (count == 1)
        {
            cout << arr[i];
            return;
        }
    }
}

/* =========================================================
   APPROACH: Better (Hashing using map)
   Time Complexity: O(n log n)
   Space Complexity: O(n)
   ========================================================= */
void better()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int> freq;

    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    for (auto it : freq)
    {
        if (it.second == 1)
        {
            cout << it.first;
            return;
        }
    }
}

/* =========================================================
   APPROACH: Optimal (XOR)
   Time Complexity: O(n)
   Space Complexity: O(1)
   ========================================================= */
void optimal()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int xorr = 0;

    for (int i = 0; i < n; i++)
        xorr = xorr ^ arr[i];     // XOR cancels duplicate numbers

    cout << xorr;
}

/* ================= MAIN FUNCTION ================= */
int main()
{
    optimal();      // change to brute() or better() if needed
    return 0;
}
