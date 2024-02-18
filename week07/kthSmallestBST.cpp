class Solution {
public:
    // TC: O(n), n = |node|
    // TC: O(h), h = height of tree
    int counter, result;
    void inorderDFS(TreeNode* root, int k) {
        if(root == nullptr) return;
        inorderDFS(root -> left, k);
        ++counter;
        if(counter == k) result = root -> val;
        inorderDFS(root -> right, k); 
    }
    int kthSmallest(TreeNode* root, int k) {
        inorderDFS(root, k);
        return result;
    }
};