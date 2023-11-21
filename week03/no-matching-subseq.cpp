class Solution {
    // TC: O(|s| + W log|s|) where, W = total number of chars in all strings from words.
    // SC: O(1)
private:
    vector<int> index_of[26];
    bool isSubSeq(string &ref) {
        int last_index = -1;
        for(int i = 0; i < ref.size(); i++) {
            int ord = ref[i] - 'a';
            int next_index = upper_bound(index_of[ord].begin(), index_of[ord].end(), last_index) - index_of[ord].begin();
            if(next_index == index_of[ord].size()) return false;
            last_index = index_of[ord][next_index];
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
            count += isSubSeq(word);
        }

        return count;
    }
};