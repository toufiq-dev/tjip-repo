class Solution {
public:
    // TC: O(n) n = no. of nodes
    // SC: O(h) h = height of the tree
    bool validateBST(TreeNode* root, TreeNode* l_min, TreeNode* r_max) {
        if(root == nullptr) return true;
        if((l_min && l_min -> val >= root -> val) || (r_max && root -> val >= r_max -> val)) 
            return false;
        
        return validateBST(root -> left, l_min, root) &&
               validateBST(root -> right, root, r_max);
    }
    bool isValidBST(TreeNode* root) {
        return validateBST(root, nullptr, nullptr);
    }
};