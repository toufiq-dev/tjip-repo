#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        // TC: O(N ^ 2)
        // SC: O(N)
        vector<vector<int>> threeSum(vector<int>& nums) {
            // step1: sort the array
            sort(nums.begin(), nums.end());

            vector<vector<int>> triplets;

            // step2: for each element in array apply two-sum
            for(int i = 0; i < nums.size(); ++i) {
                int a = nums[i];

                // for every a(prefix), find b, c form  
                // suffix such that, b + c == -a
                int L = i + 1;
                int R = nums.size() - 1;
                int target = -a;

                while(L < R) {
                    if(nums[L] + nums[R] < target)
                        L++;
                    else if (nums[L] + nums[R] > target) 
                        R--;
                    else {
                        // remove duplicates
                        while(L < R && nums[L] == nums[L + 1])
                            L++;
                        while(L < R - 1 && nums[R] == nums[R - 1])
                            R--;

                        triplets.push_back({nums[i], nums[L], nums[R]});
                        L++;
                        R--;
                    }                        
                }

                while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                    i++;
            }

            return triplets;
        }
};

int main() {
    vector<int> arr = {-1,0,1,2,-1,-4};

    Solution sln;

    vector<vector<int>> ans = sln.threeSum(arr);

    for(auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
    such that, i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.

 

    Example 1:

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
*/