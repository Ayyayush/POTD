#include <bits/stdc++.h>
using namespace std;

bool subsetSumUtil(vector<int> &arr, int idx, int sum)
{
    if (sum == 0)
        return true; // Agar sum 0 ho gaya, to subset mil gaya
    if (idx == arr.size() || sum < 0)
        return false; // Agar index out of range ya sum negative ho gaya

    // Element ko include karte hain ya ignore karte hain
    return subsetSumUtil(arr, idx + 1, sum - arr[idx]) || subsetSumUtil(arr, idx + 1, sum);
}

void brute()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2}; // Given array
    int sum = 9;                            // Target sum

    if (subsetSumUtil(arr, 0, sum))
        cout << "Subset exists\n";
    else
        cout << "Subset does not exist\n";
}

int main()
{
    brute();
    return 0;
}
