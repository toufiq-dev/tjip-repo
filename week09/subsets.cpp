class Solution {
public:
    // TC: O(N * 2^N) N = |nums|
    // SC: O(N * 2^N)
    vector<vector<int>> subsets(vector<int>& nums) {
        subset.clear();
        result.clear();
        gen(nums, 0);
        return result;
    }
private:
    vector<int> subset;
    vector<vector<int>> result;

    void gen(vector<int>& nums, int idx) {
        if (idx >= nums.size()) {
            result.push_back(subset);
            return;
        }

        // left call - include
        subset.push_back(nums[idx]);
        gen(nums, idx + 1);
        subset.pop_back();

        // right call - skip
        gen(nums, idx + 1);
    }
};