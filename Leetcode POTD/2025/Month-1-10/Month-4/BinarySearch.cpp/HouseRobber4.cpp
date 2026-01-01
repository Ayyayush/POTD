#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // T.C: O(n^2), S.C: O(n)
    int n;
    cin >> n; // Number of elements input le rahe hain
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Array ka input le rahe hain
    }

    int k;
    cin >> k; // k ka input le rahe hain
    vector<int> vec;
    long long sum, maxelt = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 2; j < nums.size(); j++)
        {
            if (j < nums.size())
            {
                maxelt = max(nums[i], nums[j]); // Max element nikal rahe hain
            }
            vec.push_back(maxelt); // Vector me store kar rahe hain
        }
    }

    auto it = min_element(vec.begin(), vec.end()); // Minimum element nikal rahe hain
    cout << *it << endl;                           // Answer print kar rahe hain
}



// Approach-1 (Better - Recursion + Memoization)
// T.C: O(n*k), S.C: O(n*k)
void better()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<vector<int>> t(n + 1, vector<int>(k + 1, -1));
    function<int(int, int)> solve = [&](int i, int k)
    {
        if (k == 0)
            return 0;
        if (i >= n)
            return INT_MAX;
        if (t[i][k] != -1)
            return t[i][k];
        int take = max(nums[i], solve(i + 2, k - 1));
        int not_take = solve(i + 1, k);
        return t[i][k] = min(take, not_take);
    };
    cout << solve(0, k) << endl;
}



// Approach-2 (Optimal - Binary Search on Answer)
// T.C: O(n*log(maxC)), S.C: O(1)
void optimal()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int l = *min_element(begin(nums), end(nums)); // Minimum element find kar rahe hain
    int r = *max_element(begin(nums), end(nums)); // Maximum element find kar rahe hain
    int result = r;

    auto isPossible = [&](int mid)
    {
        int house = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= mid)
            {
                house++;
                i++; // Adjacent house skip kar rahe hain
            }
        }
        return house >= k;
    };

    while (l <= r)
    {
        int mid = l + (r - l) / 2; // Mid calculate kar rahe hain
        if (isPossible(mid))
        {
            result = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << result << endl;
}

int main()
{
    brute();   // Brute force function call kar rahe hain
    better();  // Better approach call kar rahe hain
    optimal(); // Optimal approach call kar rahe hain
    return 0;
}