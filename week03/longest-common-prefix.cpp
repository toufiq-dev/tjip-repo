class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    string prefix = strs[0];
    for (const string &str : strs) {
      string new_prefix = "";
      for (int i = 0; i < min(prefix.size(), str.size()); i++) {
        if (prefix[i] == str[i]) {
          new_prefix += prefix[i];
        } else {
          break;
        }
      }
      
      prefix = new_prefix;
    }

    return prefix;
  }
};
