#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // TC: O(N)
    // SC: O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for(int i = 0; i < nums.size(); ++i) {
            if(seen.count(target - nums[i])) 
                return {seen[target - nums[i]], i};
            
            seen[nums[i]] = i;
        }

        return {-1, -1};
    }
};

int main() {
    vector<int> arr = {2,7,11,15};
    int target = 9;

    Solution* sln = new Solution();

    vector<int> ans = sln.twoSum(arr, target);

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}