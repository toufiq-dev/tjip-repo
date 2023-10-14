#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    void moveZeroes(vector<int>& nums) {
        int nonZeroIndex = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[nonZeroIndex]);
                nonZeroIndex++;
            }
        }
    }
};

int main() {
    vector<int> arr = {0,1,0,3,12};

    Solution sln;
    sln.moveZeroes(arr);

    for(auto x : arr) {
        cout << x << " ";
    }

    return 0;
}