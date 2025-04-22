====================
Question:
  description: |
    You are given a list of non-overlapping intervals sorted by their start time, and a new interval.
    Your task is to insert the new interval into the list while maintaining the order and merging any overlapping intervals.

====================
Approach:
  steps:
    - Initialize an empty result list `ans`.
    - Traverse the given intervals:
        - Add all intervals that end before the new interval starts (no overlap).
        - Merge all intervals that overlap with the new interval by updating the start and end.
        - Add the merged new interval.
        - Add the remaining intervals that start after the new interval ends.

====================
Dry Run:
  input:
    intervals: [[1,2], [3,5], [6,7], [8,10], [12,16]]
    newInterval: [4, 8]
  steps:
    - First loop: Add [1,2], [3,5] overlaps with [4,8], so skip
    - Second loop: Merge [3,5], [6,7], [8,10] into newInterval → becomes [3,10]
    - Add merged interval: [3,10]
    - Remaining: Add [12,16]
    - Final result: [[1,2], [3,10], [12,16]]

====================
Variables (Renamed for Readability):
  - ans: result list to store the final merged intervals
  - i: index to loop through intervals
  - n: total number of intervals
  - intervals: existing sorted, non-overlapping intervals
  - newInterval: the new interval to insert and possibly merge

====================
Final Code (Readable):
  code: |
    class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            vector<vector<int>> result;
            int i = 0;
            int n = intervals.size();

            // Add all intervals that come before the newInterval
            while (i < n && intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]);
                i++;
            }

            // Merge overlapping intervals with newInterval
            while (i < n && intervals[i][0] <= newInterval[1]) {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                i++;
            }

            // Add the merged newInterval
            result.push_back(newInterval);

            // Add the remaining intervals
            while (i < n) {
                result.push_back(intervals[i]);
                i++;
            }

            return result;
        }
    };
