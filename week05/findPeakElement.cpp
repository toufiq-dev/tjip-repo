class Solution {
public:
    // TC: O(log n) where, n = |nums|
    // SC: O(1)
    int findPeakElement(vector<int>& nums) {
        int L = 0;
        int R = nums.size() - 1;

        while(L < R) {
            int mid = L + (R - L) / 2;
            if(nums[mid] < nums[mid + 1])
                L = mid + 1;
            else R = mid;
        }

        return L;
    }
};