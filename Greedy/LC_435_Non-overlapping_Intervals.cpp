EraseOverlappingIntervals:
  question: >
    Given an array of intervals where intervals[i] = [start_i, end_i],
    return the minimum number of intervals you need to remove to make
    the rest of the intervals non-overlapping.

  approach: 
    type: Greedy
    steps:
      - Sort all intervals based on their end time in ascending order.
      - Initialize a counter `cnt` to count non-overlapping intervals.
      - Track the end time of the last non-overlapping interval with `prevend`.
      - Iterate over each interval:
          - If current interval’s start >= prevend, it's non-overlapping → count it.
          - Update `prevend` to current interval’s end.
      - Return total_intervals - cnt to get the number of intervals to remove.

  dry_run:
    input: [[1,2], [2,3], [3,4], [1,3]]
    sorted_intervals: [[1,2], [2,3], [1,3], [3,4]]
    steps:
      - interval: [1,2]
        condition: "1 >= INT_MIN"
        action: "non-overlapping"
        cnt: 1
        prevend: 2
      - interval: [2,3]
        condition: "2 >= 2"
        action: "non-overlapping"
        cnt: 2
        prevend: 3
      - interval: [1,3]
        condition: "1 < 3"
        action: "overlapping"
        cnt: 2
        prevend: 3
      - interval: [3,4]
        condition: "3 >= 3"
        action: "non-overlapping"
        cnt: 3
        prevend: 4
    result:
      total_intervals: 4
      non_overlapping: 3
      to_remove: 1

  code_explanation:
    - "The compare function is static so it can be used with std::sort."
    - "std::sort is used to sort the intervals by their end times."
    - "A loop counts the non-overlapping intervals based on current start and previous end."
    - "The difference between total and non-overlapping gives the minimum to remove."

  code_snippet: |
    class Solution {
    public:
        static bool compare(const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        }

        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(), compare);

            int cnt = 0;
            int n = intervals.size();
            int prevend = INT_MIN;

            for (int i = 0; i < n; i++) {
                if (intervals[i][0] >= prevend) {
                    cnt++;
                    prevend = intervals[i][1];
                }
            }
            return n - cnt;
        }
    };
