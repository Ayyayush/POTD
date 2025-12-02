#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // ✅ T.C = O(n^3)      (3 nested loops)
    // ✅ S.C = O(1)        (no extra space)

    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    int totalSum = 0;

    for (int i = 0; i < n; i++)                             // loop for start index
    {
        for (int j = i; j < n; j++)                         // loop for end index
        {
            int subSum = 0;
            for (int k = i; k <= j; k++)                    // loop to calculate sum of subarray [i...j]
            {
                subSum += arr[k];
            }
            totalSum += subSum;                             // add that subarray's sum to total
        }
    }

    cout << "Brute: " << totalSum << endl;
}

void better()
{
    // ✅ T.C = O(n^2)      (2 nested loops)
    // ✅ S.C = O(1)        (no extra space)

    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    int totalSum = 0;

    for (int i = 0; i < n; i++)                             // start of subarray
    {
        int subSum = 0;
        for (int j = i; j < n; j++)                         // extend subarray till end
        {
            subSum += arr[j];                               // add current element
            totalSum += subSum;                             // accumulate subarray sum
        }
    }

    cout << "Better: " << totalSum << endl;
}

void optimal()
{
    // ✅ Approach: Element Contribution Formula
    // ✅ T.C = O(n)         (single loop)
    // ✅ S.C = O(1)         (no extra space)

    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    int totalSum = 0;

    for (int i = 0; i < n; ++i)
    {
        int contribution = arr[i] * (i + 1) * (n - i);       // ith element ka kitni subarrays me contribution hoga
        totalSum += contribution;
    }

    cout << "Optimal: " << totalSum << endl;
}

int main()
{
    brute();
    better();
    optimal();
    return 0;
}
