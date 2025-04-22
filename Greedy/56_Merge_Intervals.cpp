====================
Question:
  description: |
    Given an array of intervals where each interval is represented as [start, end],
    merge all overlapping intervals and return a list of non-overlapping intervals that cover all the intervals in the input.

====================
Approach:
  steps:
    - Sort the intervals based on their starting time.
    - Create a list to store the merged intervals.
    - Start by adding the first interval to the result list.
    - Iterate through each interval:
        - If the current interval starts before or at the end of the last merged interval, merge them.
        - Otherwise, add the current interval as a new entry in the result.

====================
Dry Run:
  input: [[1,3], [2,6], [8,10], [15,18]]
  sorted_intervals: [[1,3], [2,6], [8,10], [15,18]]
  steps:
    - Initialize merged = [[1, 3]]
    - [2,6] overlaps with [1,3] → merge to [1,6]
      merged = [[1,6]]
    - [8,10] does not overlap with [1,6] → add it
      merged = [[1,6], [8,10]]
    - [15,18] does not overlap with [8,10] → add it
      merged = [[1,6], [8,10], [15,18]]

====================
Variables (Renamed for Readability):
  - mergedIntervals: stores the final merged intervals
  - currentInterval: the interval currently being examined
  - lastMerged: the last interval in mergedIntervals
  - intervals: input list of intervals, sorted by start time

====================
Final Code (Readable):
  code: |
    class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            vector<vector<int>> mergedIntervals;

            // Step 1: Sort intervals by start time
            sort(intervals.begin(), intervals.end());

            // Step 2: Start with the first interval
            mergedIntervals.push_back(intervals[0]);

            // Step 3: Process each interval
            for (int i = 1; i < intervals.size(); i++) {
                vector<int>& lastMerged = mergedIntervals.back();
                vector<int>& currentInterval = intervals[i];

                if (currentInterval[0] <= lastMerged[1]) {
                    // Merge overlapping intervals
                    lastMerged[1] = max(lastMerged[1], currentInterval[1]);
                } else {
                    // No overlap, add current interval
                    mergedIntervals.push_back(currentInterval);
                }
            }

            return mergedIntervals;
        }
    };
