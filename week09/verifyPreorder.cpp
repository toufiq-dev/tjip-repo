class Solution {
public:
    // TC: O(N), N = |preorder| 
    // SC: O(N)
    bool verifyPreorder(vector<int>& preorder) {
        int currIdx = 0;
        constructBST(preorder, currIdx);
        return currIdx == preorder.size(); 
    }
private:
    void constructBST(vector<int> &preorder, int &currIdx, int v_min = INT_MIN, int v_max = INT_MAX) {
        if (currIdx == preorder.size()) return;
        int v = preorder[currIdx];
        if (v <= v_min || v >= v_max) return;
        currIdx++;
        constructBST(preorder, currIdx, v_min, v);
        constructBST(preorder, currIdx, v, v_max);
    }
};