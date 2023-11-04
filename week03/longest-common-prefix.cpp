class Solution {
public:
  // TC: O(m * n) where m = |strs|, n = |prefix| / |str|
  // SC: O(n) where n = longest commong prefix
  string longestCommonPrefix(vector<string>& strs) {
    auto prefix = strs[0];

    for (auto &str : strs) {
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
