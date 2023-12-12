class Solution {
public:
    // TC: O(log n)
    // SC: O(1)
    int firstBadVersion(int n) {
        int L = 1, R = n;
        while(L < R) {
            int mid = L + (R - L) / 2;
            if(!isBadVersion(mid)) 
                L = mid + 1;
            else 
                R = mid;
        }

        return L;
    }
};