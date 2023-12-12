class Solution {
public:
    // TC: O(nlog n) where, n = |intervals|
    // SC: O(n)
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;
        for(auto &interval : intervals) {
            events.push_back({interval[0], +1});
            events.push_back({interval[1], -1});
        }
        sort(events.begin(), events.end());

        int max_room = 0, curr_no_rooms = 0;
        for(auto &event: events) {
            curr_no_rooms += event.second;
            max_room = max(curr_no_rooms, max_room);
        }

        return max_room;
    }
};