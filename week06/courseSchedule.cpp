class Solution {
public:
    // TC: O(V + E) where, V = numCourses E = |prerequisites|
    // SC: O(V + E)  
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for (auto prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int visitedNodes = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visitedNodes++;

            for (auto& neighbor : adj[node]) {
                --indegree[neighbor];
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return visitedNodes == numCourses;
    }
};