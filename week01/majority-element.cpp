#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    // TC: O(N)
    // SC: O(N)
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> frequency;

        for(int i = 0; i < nums.size(); i++) {
            if(frequency.count(nums[i]) == 0) frequency[nums[i]];

            frequency[nums[i]]++;
        }

        for(auto x : frequency) {
            if(x.second > floor(nums.size() / 2)) return x.first;
        }

        return -1;
    }
};

int main() {
    vector<int> arr = {6,6,6,7,7};

    Solution sln;

    int ans = sln.majorityElement(arr);

    cout << ans << endl;

    return 0;
}