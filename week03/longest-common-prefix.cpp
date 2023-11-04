class Solution {
public:
    // TC: O(N) where N is total number of characters in all the strings
    // SC: O(1)
    string longestCommonPrefix(vector<string>& strs) {
        auto prefix = strs[0];
        
        for (auto &str : strs) {
            int i = 0;
            while (i < prefix.size() && i < str.size() && prefix[i] == str[i]) {
                i++;
            }
            prefix = prefix.substr(0, i); 
            if (prefix.empty()) {
                break; 
            }
        }
        
        return prefix;
    }
};
