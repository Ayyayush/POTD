class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });
             
        int prevStart = intervals[0][0];
        int prevEnd = intervals[0][1];
        int count = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= prevStart && intervals[i][1] <= prevEnd) {
                continue;
            } else {
                count++;
                prevStart = intervals[i][0];
                prevEnd = intervals[i][1];
            }
        }

        return count;
    }
};
