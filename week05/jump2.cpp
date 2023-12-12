class Solution {
public:
    // TC: O(n), n = |nums|
    // SC: O(1)
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;

        int total_jump = 0;
        int max_jump = 0;
        int curr_end = 0;
        for(int i = 0; i < nums.size() - 1; ++i) {
            max_jump = max(max_jump, nums[i] + i);
            if(i == curr_end) {
                ++total_jump;
                curr_end = max_jump;
            }
        }

        return total_jump;
    }
};