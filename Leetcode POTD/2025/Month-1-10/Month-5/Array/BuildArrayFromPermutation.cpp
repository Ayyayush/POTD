#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(n)         // ek loop me saare elements set ho rahe hain
    // Space Complexity: O(n)        // ek extra vector banaya hai answer ke liye

    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // input array
    }

    vector<int> ans(n); // output array

    for (int i = 0; i < n; i++)
    {
        ans[i] = nums[nums[i]]; // nums[nums[i]] store kar rahe hain ans[i] me
    }

    // print the answer
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void better()
{
    // Time Complexity: O(n)         // do passes ho rahe hain (2 loops) => O(n)
    // Space Complexity: O(1)        // koi extra array use nahi kiya, in-place modify kiya

    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // input array
    }

    // Pehle pass me: har element me uske sath nums[nums[i]] ko bhi encode karenge
    for (int i = 0; i < n; i++)
    {
        // nums[i] % n se original value milegi
        // nums[nums[i] % n] se target index ka value milega
        // n * x se us value ko encode kar rahe hain current value ke sath
        nums[i] = nums[i] + n * (nums[nums[i]]%n);
    }

    // Dusre pass me: encoded values ko decode karke final result bana rahe hain
    for (int i = 0; i < n; i++)
    {
        nums[i] = nums[i] / n; // sirf encoded value n*X ko le rahe hain
    }

    // print the answer
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    // brute();   // O(n) time and O(n) space
    better();     // O(n) time and O(1) space
    return 0;
}
