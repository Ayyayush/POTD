#include <bits/stdc++.h>
using namespace std;

void brute() // 🚀 Brute Approach
{
    /*
        APPROACH: Prefix + Total Sum Update
        Time Complexity: O(n)
        Space Complexity: O(1)
    */

    int n;
    cin >> n; // taking input
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i]; // input array

    int totalSum = 0;
    for (int x : nums)
        totalSum += x; // total array sum

    int currSum = 0;
    int count = 0;

    for (int i = 0; i < n - 1; i++) // iterate till 2nd last index
    {
        currSum += nums[i];  // prefix sum till i
        totalSum -= nums[i]; // suffix sum after i

        if ((totalSum - currSum) % 2 == 0) // diff even -> valid partition
            count++;
    }

    cout << count; // output result
}

void better() // 🚀 Better Approach
{
    /*
        APPROACH: Precompute prefix[] and suffix[] arrays
        Time Complexity: O(n)
        Space Complexity: O(n)
    */
    vector<int> nums = {10, 10, 3, 7, 6};
        int n=nums.size();

    vector<int> left(n), right(n);

    int sum = 0;

    for (int i = 0; i < n; i++) // build prefix sum array
    {
        sum += nums[i];
        left[i] = sum; // left[i] = sum of 0..i
    }

    sum = 0;
    for (int i = n - 1; i >= 0; i--) // build suffix sum array
    {
        sum += nums[i];
        right[i] = sum; // right[i] = sum of i..n-1
    }

    for (int i = 0; i < n; i++) // build prefix sum array
    {
        cout << left[i] <<" "<< right[i + 1]<<endl;
    }

    int count = 0;
    for (int i = 0; i < n - 1; i++) // check partitions at each i
    {
        int diff = left[i] - right[i + 1]; // difference of prefix & suffix
        if (diff % 2 == 0)                 // even difference → valid
            count++;
    }

    cout << count; // output result
}

int main()
{
    better();
    return 0;
}
