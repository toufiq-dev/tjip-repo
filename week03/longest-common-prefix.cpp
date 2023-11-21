class Solution {
public:
    // TC: O(N) where N is total number of characters in all the strings
    // SC: O(1)
    string longestCommonPrefix(vector<string>& strs) {
        auto prefix = strs[0];

        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                ++j;
            }
            prefix = prefix.substr(0, j); 

            if (prefix.empty()) {
                break; 
            }
        }

        return prefix;
    }
};