class Solution {
public:
    // TC: O(n), here n = |nums|
    // SC: O(logn)
    TreeNode* BSTBuilder(vector<int> &nums, int L, int R) {
        if(L > R) return nullptr;
        int M = L + (R - L) / 2;
        return new TreeNode(nums[M], BSTBuilder(nums, L, M - 1), BSTBuilder(nums, M + 1, R));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BSTBuilder(nums, 0, nums.size() - 1);
    }
};