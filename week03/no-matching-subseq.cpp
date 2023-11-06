class Solution {
    // TC: O(|s| + |word| * logs)
    // SC: O(1)
private:
    vector<int> index_of[26];
    bool isSubSeq(string &s, string &ref) {
        int last = -1;
        for(int i = 0; i < ref.size(); i++) {
            int ord = ref[i] - 'a';
            int next = upper_bound(index_of[ord].begin(), index_of[ord].end(), last) - index_of[ord].begin();
            if(next == index_of[ord].size()) return false;
            last = index_of[ord][next];
        }
        return true;
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        for(int i = 0; i < s.size(); i++) {
            index_of[s[i] - 'a'].push_back(i);
        }

        int count = 0;
        for(auto &word : words) {
            count += isSubSeq(s, word);
        }

        return count;
    }
};