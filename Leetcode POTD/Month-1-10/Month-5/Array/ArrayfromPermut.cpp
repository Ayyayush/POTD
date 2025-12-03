#include <bits/stdc++.h>
using namespace std;

void brute()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements (0 to n-1): ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> ans(n);

    // har i ke liye, ans[i] = nums[nums[i]]
    for (int i = 0; i < n; i++)
    {
        ans[i] = nums[nums[i]];
    }

    // Output the final array
    cout << "Resultant array: ";
    for (int val : ans)
        cout << val << " ";
    cout << endl;
}

void better()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements (0 to n-1): ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Step 1: Encode new values using old + new combo
    for (int i = 0; i < n; i++)
    {
        nums[i] = nums[i] + (nums[nums[i]] % n) * n;
    }

    // Step 2: Extract new values by dividing with n
    for (int i = 0; i < n; i++)
    {
        nums[i] = nums[i] / n;
    }

    // Output final array
    cout << "Resultant array: ";
    for (int val : nums)
        cout << val << " ";
    cout << endl;
}

int main()
{
    buildArray();
    return 0;
}
