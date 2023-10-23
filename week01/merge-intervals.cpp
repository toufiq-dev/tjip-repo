#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            unordered_map<int, int> seen;

            for(auto x : intervals) {
                seen[x[1]];
            }

            
        }
};

int main() {
    vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};

    Solution sln;

    vector<vector<int>> ans = sln.merge(arr);

    for(auto x : ans) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}