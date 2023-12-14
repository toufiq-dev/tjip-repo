class Solution {
public:
    // TC: O(n) where, n = |TreeNode|
    // TC: O(n)
    TreeNode* replaceValueInTree(TreeNode* root) {
        root -> val = 0;
        queue<TreeNode*> Q; 
        vector<TreeNode*> buffer;
        Q.push(root);

        while(!Q.empty()) {
            int n = Q.size();
            int sum = 0;
            buffer.clear();
            while(n--) {
                auto u = Q.front(); Q.pop();
                buffer.push_back(u);
                if(u -> left) {Q.push(u -> left); sum += u -> left -> val;}
                if(u -> right) {Q.push(u -> right); sum += u -> right -> val;}
            }
            for(auto &u : buffer) {
                int sibling_sum = 0;
                if(u -> left) sibling_sum += u -> left -> val;
                if(u -> right) sibling_sum += u -> right -> val;
                if(u -> left) u -> left -> val = sum - sibling_sum;
                if(u -> right) u -> right -> val = sum - sibling_sum;
            }
        }

        return root;
    }
};