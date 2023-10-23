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
