#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Time Complexity: O(N * M)                  // M = max(heights) - min(heights)
    // Space Complexity: O(1)                      // extra space nahi lag raha

    int n;                                         // no. of towers
    cin >> n;

    vector<int> heights(n), cost(n);               // input heights aur cost arrays
    for (int i = 0; i < n; i++) cin >> heights[i];
    for (int i = 0; i < n; i++) cin >> cost[i];

    int ans = INT_MAX;

    int lo = *min_element(heights.begin(), heights.end());      // sabse choti height
    int hi = *max_element(heights.begin(), heights.end());      // sabse badi height

    for (int target = lo; target <= hi; target++)               // har possible height par check karo
    {
        int currCost = 0;

        for (int i = 0; i < n; i++)                             // har tower ke liye cost add karo
        {
            currCost += abs(heights[i] - target) * cost[i];
        }

        ans = min(ans, currCost);                               // minimum cost track karo
    }

    cout << ans << endl;
}

void better()
{
    // Time Complexity: O(N * log(maxH))          // binary search se height find karenge
    // Space Complexity: O(1)                      // extra space nahi lag raha

    int n;                                         // no. of towers
    cin >> n;

    vector<int> heights(n), cost(n);               // input heights aur cost arrays
    for (int i = 0; i < n; i++) cin >> heights[i];
    for (int i = 0; i < n; i++) cin >> cost[i];

    auto getCost = [&](int target) -> long long    // lambda function to calculate cost for given height
    {
        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            total += 1LL * abs(heights[i] - target) * cost[i];
        }
        return total;
    };

    int lo = *min_element(heights.begin(), heights.end());      // sabse choti height
    int hi = *max_element(heights.begin(), heights.end());      // sabse badi height

    while (hi - lo > 2)                                         // ternary search kyunki convex function hai
    {
        int mid1 = lo + (hi - lo) / 3;
        int mid2 = hi - (hi - lo) / 3;

        if (getCost(mid1) < getCost(mid2))
            hi = mid2;                                          // right half discard karo
        else
            lo = mid1;                                          // left half discard karo
    }

    long long ans = LLONG_MAX;
    for (int target = lo; target <= hi; target++)               // last few values check karo
    {
        ans = min(ans, getCost(target));
    }

    cout << ans << endl;
}

int main()
{
    brute();
    better();
    return 0;
}
