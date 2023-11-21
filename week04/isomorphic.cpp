class Solution {
public:
    // O(|s|), |s| == |t|
    // O(|s|)
    bool isomorphic(string s, string t) {
        unordered_map<char, char> iso;
        for (int i = 0; i < s.size(); ++i) {
            if (iso.count(s[i]) and iso[s[i]] != t[i]) 
                return false;

            iso[s[i]] = t[i];
        }

        return true;
    }

    bool isIsomorphic(string s, string t) {
       return isomorphic(s, t) and isomorphic(t, s);
    }
};