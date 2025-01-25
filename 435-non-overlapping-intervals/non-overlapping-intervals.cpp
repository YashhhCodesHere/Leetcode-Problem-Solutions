class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals based on the end times
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int result = 0;  // To count the number of intervals removed
        int prevEnd = intervals[0][1];  // Keep track of the end of the previous interval

        // Step 2: Iterate through the intervals to check overlaps
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) {
                // If the current interval overlaps, increment result (remove the interval)
                result++;
            } else {
                // Otherwise, update the end time to the current interval's end
                prevEnd = intervals[i][1];
            }
        }

        return result;  // Return the total number of intervals removed
    }
};
