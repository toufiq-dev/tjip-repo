#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    int singleNumber(vector<int>& nums) {
        int num = 0;

        for(int i = 0; i < nums.size(); i++) {
            num ^= nums[i];
        }

        return num;
    }
};

int main() {
    vector<int> arr = {4,1,2,1,2};

    Solution sln;

    int ans = sln.singleNumber(arr);

    cout << ans;

    return 0;
}