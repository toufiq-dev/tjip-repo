class Solution {
public:
    // TC: O(n^2), where n = |points|
    // SC: O(n)
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> pointSet;  
        int result = INT_MAX;

        for (const auto& point : points) {
            pointSet.insert(point[0] * 40001 + point[1]);
        }

        for (const auto& p1 : points) {
            for (const auto& p2 : points) {
                if (p1[0] != p2[0] && p1[1] != p2[1]) {  
                    if (pointSet.count(p1[0] * 40001 + p2[1]) && pointSet.count(p2[0] * 40001 + p1[1])) {
                        int area = abs((p1[0] - p2[0]) * (p1[1] - p2[1]));
                        result = min(result, area);
                    }
                }
            }
        }

        return result == INT_MAX ? 0 : result;
    }
};