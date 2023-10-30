class Solution {
public:
    // TC: O(N) here, N = |s| + |t| 
    // TC: O(1) 
    bool isAnagram(string s, string t) {
        vector<int> fs(256, 0);
        for(auto &c : s) {
            ++fs[c];
        }

        vector<int> ft(256, 0);
        for(auto &c : t) {
            ++ft[c];
        }

        return fs == ft;
    }
};