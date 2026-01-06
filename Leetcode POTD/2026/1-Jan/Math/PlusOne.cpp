#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------
Approach: Brute Force (Convert to Number)
Time Complexity: O(n)
Space Complexity: O(n)
--------------------------------------------------
*/
void brute()
{
    vector<int> nums;
    int n; 
    cin >> n;
    nums.resize(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    // Convert digits to number (may overflow for large n)
    long long number = 0;
    for(int i = 0; i < n; i++)
        number = number * 10 + nums[i];

    number += 1;                                   // add one

    vector<int> ans;
    while(number > 0)
    {
        ans.push_back(number % 10);
        number /= 10;
    }

    reverse(ans.begin(), ans.end());

    for(int x : ans)
        cout << x << " ";
}

/*
--------------------------------------------------
Approach: Better (Extra Array Carry Handling)
Time Complexity: O(n)
Space Complexity: O(n)
--------------------------------------------------
*/
void better()
{
    vector<int> nums;
    int n;
    cin >> n;
    nums.resize(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans(nums.begin(), nums.end());

    int carry = 1;                                 // initial +1

    for(int i = n - 1; i >= 0; i--)
    {
        int sum = ans[i] + carry;                  // digit + carry
        ans[i] = sum % 10;                         // current digit
        carry = sum / 10;                          // carry forward
    }

    if(carry == 1)
        ans.insert(ans.begin(), 1);                // extra digit

    for(int x : ans)
        cout << x << " ";
}

/*
--------------------------------------------------
Approach: Optimal (In-Place Carry Propagation)
Time Complexity: O(n)
Space Complexity: O(1)
--------------------------------------------------
*/
void optimal()
{
    vector<int> nums;
    int n;
    cin >> n;
    nums.resize(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int i = n - 1;

    // Case: single digit [9]
    if(n == 1 && nums[i] == 9)
    {
        nums[0] = 1;
        nums.push_back(0);
    }
    else
    {
        while(i >= 0)
        {
            if(nums[i] == 9)
            {
                nums[i] = 0;                       // reset 9
                int j = i - 1;

                // propagate carry across 9s
                while(j >= 0 && nums[j] == 9)
                {
                    nums[j] = 0;
                    j--;
                }

                if(j >= 0)
                    nums[j] += 1;                  // safe increment
                else
                    nums.insert(nums.begin(), 1);  // all digits were 9
            }
            else
            {
                nums[i] += 1;                      // simple increment
            }
            break;                                 // only one operation needed
        }
    }

    for(int x : nums)
        cout << x << " ";
}

int main()
{
    // Call the version you want
    // brute();
    // better();
    optimal();

    return 0;
}
