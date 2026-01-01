#include <bits/stdc++.h>
using namespace std;
void brute()
{
    // using nested loops
}

// Approach-1: Classic Sliding Window
// T.C : O(n), because j aur i ek-ek baar chalte hain
// S.C : O(1), koi extra space nahi
void better()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k;
    cin >> k;

    int maxE = *max_element(nums.begin(), nums.end());      // array ka maximum element
    int i = 0, j = 0;
    long long result = 0;
    int countMax = 0;

    while (j < n)
    {
        if (nums[j] == maxE)
            countMax++;                                     // window me maximum element mila

        while (countMax >= k)                               // jab tak window me k ya usse jyada max mil raha ho
        {
            result += (n - j);                              // jitne bhi subarrays end ho rahe j pe wo sab valid hain
            if (nums[i] == maxE)
                countMax--;                                 // window se ek max element hata diya
            i++;
        }

        j++;
    }

    cout << result << endl;
}


// Approach-2: Without Sliding Window (maxIndices tracking)
// T.C : O(n), ek hi loop
// S.C : O(n), maxIndices vector use hua
void optimal()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k;
    cin >> k;

    int maxE = *max_element(nums.begin(), nums.end());      // array ka maximum element
    long long result = 0;

    vector<int> maxIndices;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == maxE)
            maxIndices.push_back(i);                        // har max element ka index store kiya

        int size = maxIndices.size();
        if (size >= k)
        {
            int last_i = maxIndices[size - k];              // wo index jahan se valid subarrays start ho sakte hain
            result += (last_i + 1);                         // 0 se last_i tak sab valid subarray start hain
        }
    }

    cout << result << endl;
}



int main()
{
    better();
    return 0;
}