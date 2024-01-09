class Solution {
public:
    // TC: O(n), n = |node|
    // TC: O(h), h = height of tree
    int merged_path;
    int getMaxChainSum(TreeNode* curr) {
        if(curr == nullptr) return 0;
        int L = getMaxChainSum(curr -> left);
        int R = getMaxChainSum(curr -> right);
        merged_path = max(merged_path, L + R + curr -> val);
        return max(0, max(L, R) + curr -> val);
    }
    int maxPathSum(TreeNode* root) {
        merged_path = INT_MIN / 2;
        getMaxChainSum(root);
        return merged_path;
    }
};