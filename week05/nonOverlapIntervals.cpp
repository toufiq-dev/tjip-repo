class Solution {
public:
    // TC: O(n logn) where n = |intervals|
    // SC: O(1)
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });

        int last_ending = INT_MIN / 2;
        int max_non_overlapping_intervals = 0;
        for(auto &interval : intervals) {
            int start = interval[0], end = interval[1];
            if(start < last_ending)
                continue;

            last_ending = end;
            ++max_non_overlapping_intervals;
        }

        return intervals.size() - max_non_overlapping_intervals;
    }
};