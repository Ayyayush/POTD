#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(n^2)     // 2 nested loops laga rahe hain
    // Space Complexity: O(1)      // extra space nahi le rahe

    int n; cin >> n;             // vector size input lo
    vector<int> nums(n);        
    for(int i = 0; i < n; i++) cin >> nums[i];   // vector elements input lo

    int lower, upper;
    cin >> lower >> upper;      // lower aur upper limit input lo

    long long count = 0;        
    for(int i = 0; i < nums.size() - 1; i++)     
    {
        for(int j = i + 1; j < nums.size(); j++) 
        {
            int sum = nums[i] + nums[j];
            if(sum >= lower && sum <= upper)     
            {
                count++;                          
            }
        }
    }

    cout << count << endl;       // output the final count
}

void better()
{
        // Time Complexity: O(n log n)       // kyunki sort + lower_bound + upper_bound O(log n) mein lagta hai har iteration mein
    // Space Complexity: O(1) extra      // koi extra space use nahi ho raha (in-place sort and operations)

    int n, lower, upper;
    cin >> n >> lower >> upper;                         // input lene ka part
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];         // array input

    long long result = 0;
    sort(nums.begin(), nums.end());                     // array ko sort karna zaroori hai binary search ke liye

    for (int i = 0; i < n; i++)
    {
        // lower bound wale pairs count karna
        int idx = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin() - 1;
        int x = idx - i;

        // upper bound wale pairs count karna
        idx = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin() - 1;
        int y = idx - i;

        result += (y - x);                              // valid pairs ko add kar diya
    }

    cout << result << endl;                             // final answer print karna
}
int main()
{
    brute();
    return 0;
}
