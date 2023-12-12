class Solution {
public:
    // TC: O(n logn) where, n = |sticks|
    // SC: O(n)
    int connectSticks(vector<int>& sticks) {
        if(sticks.size() == 1) return 0;

        priority_queue <int, vector<int>, greater<int>> min;
        for(auto &stick : sticks) {
          min.push(stick);
        }

        int min_cost = 0;
        while(min.size() > 1) {
          int first = min.top();
          min.pop();
          int second = min.top();
          min.pop();
          min_cost += first + second;
          min.push(first + second);
        }

        return min_cost;
    }
};