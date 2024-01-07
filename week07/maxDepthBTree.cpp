class Solution {
public:
    // TC: O(n), n = |node|
    // TC: O(h), h = height of tree
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};