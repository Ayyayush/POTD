#include <bits/stdc++.h>
using namespace std;

void brute()
{
    // Approach: Sort karke directly merge karenge
    // T.C. → O(n log n)      S.C. → O(n)

    int n;
    cin >> n;                                     // number of intervals
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> intervals[i][0] >> intervals[i][1];

    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];

    // Pehle newInterval ko add karo
    intervals.push_back({newInterval[0], newInterval[1]});

    // Sort by start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;
    result.push_back(intervals[0]);
    int lastboundary = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= lastboundary)      // merge case
        {
            lastboundary = max(lastboundary, intervals[i][1]);
            result.back()[1] = lastboundary;
        }
        else
        {
            result.push_back(intervals[i]);
            lastboundary = intervals[i][1];
        }
    }

    // Output result
    for (auto &v : result) cout << v[0] << " " << v[1] << "\n";
}

void better()
{
    // Approach: Insert in sorted order without full sort
    // T.C. → O(n)      S.C. → O(n)

    int n;
    cin >> n;                                     // number of intervals
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> intervals[i][0] >> intervals[i][1];

    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];

    vector<vector<int>> result;
    int i = 0;

    // Step 1: Add all intervals before newInterval
    while (i < n && intervals[i][1] < newInterval[0])
    {
        result.push_back(intervals[i]);
        i++;
    }

    // Step 2: Merge overlapping intervals with newInterval
    while (i < n && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);

    // Step 3: Add remaining intervals
    while (i < n)
    {
        result.push_back(intervals[i]);
        i++;
    }

    // Output result
    for (auto &v : result) cout << v[0] << " " << v[1] << "\n";
}

int main()
{
    // Testing dono versions
    brute();
    // better();
    return 0;
}
