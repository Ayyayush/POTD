#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Problem: Find the Original Array from Prefix XOR
// Link: https://leetcode.com/problems/find-the-original-array-from-prefix-xor/
//
// Given a prefix XOR array `pref`, find the original array `arr` such that:
// pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]
//
// Example:
// Input: pref = [5,2,0,3,1]
// Output: arr = [5,7,2,3,2]
/////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Brute (Prefix XOR Inversion - using direct formula understanding)
// Logic: Agar hum array ke prefix XOR ko jaante hain:
//        pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]
//        To original element nikalne ke liye:
//        arr[i] = pref[i] ^ pref[i-1]  (for i > 0)
//        arr[0] = pref[0]
// Ye directly inverse operation hai XOR ke property ka.
// T.C. => O(n)
// S.C. => O(1)
/////////////////////////////////////////////////////////////////////////////////////////////////////

void brute()
{
    vector<int> pref = {5, 2, 0, 3, 1};                          // Example input
    int n = pref.size();
    vector<int> arr(n);

    arr[0] = pref[0];                                            // Pehla element same hota hai
    for (int i = 1; i < n; i++)
    {
        arr[i] = pref[i] ^ pref[i - 1];                          // XOR property se reverse karo
    }

    cout << "Original Array (Brute): ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Optimal (Same as brute since O(n) hi best possible hai)
// Logic: XOR associative aur reversible hai.
//        Isliye direct formula arr[i] = pref[i] ^ pref[i-1] lagakar hi best solution milta hai.
// T.C. => O(n)
// S.C. => O(1)
/////////////////////////////////////////////////////////////////////////////////////////////////////

void optimal()
{
    vector<int> pref = {5, 2, 0, 3, 1};
    int n = pref.size();
    vector<int> result(n);

    result[0] = pref[0];                                         // First element same hi rehta hai
    for (int i = 1; i < n; i++)
    {
        result[i] = pref[i] ^ pref[i - 1];                       // Reverse XOR to find arr[i]
    }

    cout << "Original Array (Optimal - XOR): ";
    for (int x : result)
        cout << x << " ";
    cout << endl;
}

int main()
{
    brute();
    optimal();
    return 0;
}
