class Solution:
    def eraseOverlapIntervals(self, intervals):
        if not intervals:
            return 0

        # Sort intervals by end time (GREEDY KEY)
        intervals.sort(key=lambda x: x[1])

        count = 0                      # number of intervals to remove
        prev_end = intervals[0][1]     # end of last chosen interval

        for i in range(1, len(intervals)):
            # If overlap exists
            if intervals[i][0] < prev_end:
                count += 1             # remove current interval
            else:
                prev_end = intervals[i][1]  # keep current interval

        return count
