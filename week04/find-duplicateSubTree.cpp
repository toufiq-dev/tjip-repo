class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subtreeCount;  
        unordered_set<TreeNode*> result;  
        postorder(root, subtreeCount, result);
        return vector<TreeNode*>(result.begin(), result.end());
    }

private:
    string postorder(TreeNode* root, unordered_map<string, int>& subtreeCount, unordered_set<TreeNode*>& result) {
        if (!root) return "#";  

        string left = postorder(root->left, subtreeCount, result);
        string right = postorder(root->right, subtreeCount, result);

        string subtree = to_string(root->val) + "," + left + "," + right;

        ++subtreeCount[subtree];

        if (subtreeCount[subtree] == 2) 
            result.insert(root);

        return subtree;
    }
};