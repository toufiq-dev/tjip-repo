#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        // TC: O(N ^ 3)
        // SC: O(N)
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            // step1: sort the array
            sort(nums.begin(), nums.end());
            vector<vector<int>> quadruplets;

            // step2: apply three sum on each element
            for(int i = 0; i < nums.size(); ++i) {
                for(int j = i + 1; j < nums.size(); ++j) {
                    int a = nums[i] + nums[j];
                    int L = j + 1;
                    int R = nums.size() - 1;
                    long long newTarget = static_cast<long long>(target) - a;

                    while(L < R) {
                        if(nums[L] + nums[R] < newTarget)
                            L++;
                        else if(nums[L] + nums[R] > newTarget) 
                            R--;
                        else {
                            while(L + 1 < R && nums[L] == nums[L + 1])
                                L++;
                            while(L < R - 1 && nums[R] == nums[R - 1])
                                R--;

                            quadruplets.push_back({nums[i], nums[j], nums[L], nums[R]});
                            L++;
                            R--;
                        }
                    }
                    
                    while(j + 1 < nums.size() && nums[j] == nums[j + 1])
                        j++;
                }

                while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                    i++;
            }

            return quadruplets;
        }
};

int main() {
    vector<int> arr = {1,0,-1,0,-2,2};
    int target = 0;

    Solution sln;

    vector<vector<int>> ans = sln.fourSum(arr, target);

    for(auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
    Given an array nums of n integers, 
    return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target
    You may return the answer in any order.

    Example 1:
    Input: nums = [1,0,-1,0,-2,2], target = 0
    Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/
