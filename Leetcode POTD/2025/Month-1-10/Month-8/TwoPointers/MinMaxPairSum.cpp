#include <bits/stdc++.h>
using namespace std;





// ✅ Approach: Better (Sort + Two Pointer)
// T.C : O(n log n)                 	// Due to sorting
// S.C : O(1)                       	// In-place two-pointer scan
void better()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());				// Sort the array

    int result = 0;
    int i = 0, j = n - 1;

    while (i < j)
    {
        result = max(result, nums[i] + nums[j]);	// Track max pair sum
        i++;
        j--;
    }

    cout << result << endl;
}

int main()
{
    // brute();
    better();
    return 0;
}
