class Solution {
public:
    // TC: O(N*M), where N = |s|, and M = max(|sources[i]|) 
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        for (int i = 0; i < indices.size(); ++i) {

            int idx = indices[i];
            string source = sources[i];

            if (s.substr(idx, source.size()) == source) {
                s.replace(idx, source.size(), targets[i]);

                for (int j = i + 1; j < indices.size(); ++j) {
                    if (indices[j] > idx) {
                        indices[j] += targets[i].size() - source.size();
                    }
                }
            }
        }

        return s;
    }
};