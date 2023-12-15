class Solution {
    // TC: O(n), n = number of employees
    // SC: O(n)
public:
    int maxTime = INT_MIN;
    void DFS(const vector<vector<int>>& adjList, const vector<int>& informTime, int curr, int time) {
        maxTime = max(maxTime, time);

        for (int adjacent : adjList[curr]) {
            DFS(adjList, informTime, adjacent, time + informTime[curr]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                adjList[manager[i]].push_back(i);
            }
        }

        DFS(adjList, informTime, headID, 0);
        return maxTime;
    }
};