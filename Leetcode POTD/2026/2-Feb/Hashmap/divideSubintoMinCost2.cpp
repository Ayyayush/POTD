#include <bits/stdc++.h>
using namespace std;

void brute()
{
    /*
     * APPROACH: Sorting (Brute Force)
     * --------------------------------
     * - Predefined points are used (no input)
     * - Compute squared Euclidean distance (x*x + y*y)
     * - Store (distance, index) in vector
     * - Sort vector
     * - Print first k points
     *
     * Time Complexity  : O(N log N)
     * Space Complexity : O(N)
     */

    int k = 2;   // number of closest points

    vector<pair<int,int>> nums = {
        {1, 3},
        {-2, 2},
        {5, 8},
        {0, 1}
    };

    int n = nums.size();

    vector<pair<long long, int>> dist;    // {distance, index}

    for (int i = 0; i < n; i++)
    {
        long long x = nums[i].first;
        long long y = nums[i].second;

        long long d = x*x + y*y;          // squared distance (no sqrt)

        dist.push_back({d, i});
    }

    sort(dist.begin(), dist.end());

    cout << "K Closest Points to Origin:\n";

    for (int i = 0; i < k; i++)
    {
        int idx = dist[i].second;
        cout << nums[idx].first << " " << nums[idx].second << endl;
    }
}

int main()
{
    brute();
    return 0;
}
