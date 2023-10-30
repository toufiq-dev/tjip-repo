class Solution {
public:
    // TC: O(n * k * log(k)), where n is the number of input strings and k is the average length of strings.
    // SC: O(N) where, N = length of result + groups
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> groups;

        for(auto &str : strs) {
            string key_str = str;
            sort(key_str.begin(), key_str.end());
            groups[key_str].push_back(str);
        }

        for(auto &group : groups) {
            result.push_back(group.second);
        }

        return result;
    }
};