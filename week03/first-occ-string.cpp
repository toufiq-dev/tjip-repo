class Solution {
public:
    // TC: O(min(|haystack|, |needle|))
    // SC: O(1)
    int strStr(string haystack, string needle) {
        int pt1 = 0;
        int pt2 = 0;
        while(pt1 < haystack.size() && pt2 < needle.size()) {
            if(haystack[pt1] == needle[pt2]) {
                ++pt1;
                ++pt2;
                if(pt2 == needle.size()) return pt1 - needle.size();
            }
            else {
                pt1 = pt1 - pt2 + 1;
                pt2 = 0;
            }
        }

        return -1;
    }
};