#include <bits/stdc++.h>
using namespace std;

/*
============================================================
APPROACH NAME: Insert + Sort + Merge Intervals
Time Complexity: O(N log N)
Space Complexity: O(N)

WHY THIS APPROACH:
- Insert the new interval into the list
- Sort intervals by starting time
- Merge overlapping intervals in one pass

This works even if the new interval overlaps with multiple intervals.
============================================================
*/
void optimal()
{
    int n;
    cin >> n;                                    // number of existing intervals

    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i = 0; i < n; i++)
        cin >> intervals[i][0] >> intervals[i][1];

    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];     // new interval to insert

    /*
    STEP 1: Insert the new interval into the list
    Now the problem becomes a standard "merge intervals" problem
    */
    intervals.push_back(newInterval);

    /*
    STEP 2: Sort intervals based on starting time
    Sorting is required so that overlapping intervals come together
    */
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b)
         {
             return a[0] < b[0];
         });

    vector<vector<int>> merged;                  // result array

    /*
    STEP 3: Merge overlapping intervals
    */
    for(auto &interval : intervals)
    {
        /*
        Case 1:
        - If merged is empty
        - OR current interval does NOT overlap with last merged interval
        */
        if(merged.empty() || merged.back()[1] < interval[0])
        {
            merged.push_back(interval);          // safe to add as it is
        }
        else
        {
            /*
            Case 2:
            Overlapping interval found
            Merge by extending the end time
            */
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }

    /*
    OUTPUT RESULT
    */
    for(auto &it : merged)
    {
        cout << it[0] << " " << it[1] << endl;
    }
}

int main()
{
    optimal();
    return 0;
}


class Solution:
    def insert(self, intervals, newInterval):
        # STEP 1: Insert the new interval
        intervals.append(newInterval)

        # STEP 2: Sort intervals based on starting time
        intervals.sort(key=lambda x: x[0])

        merged = []

        # STEP 3: Merge overlapping intervals
        for interval in intervals:
            # If merged is empty OR no overlap with last interval
            if not merged or merged[-1][1] < interval[0]:
                merged.append(interval)
            else:
                # Overlapping case → merge intervals
                merged[-1][1] = max(merged[-1][1], interval[1])

        return merged

