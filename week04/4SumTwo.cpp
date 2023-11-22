class Solution {
public:
    // TC: O(n^2), where n is the length of input arrays
    // SC: O(n^2)
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> pair_sum;
        for (int i : nums1) {
            for (int j : nums2) {
                pair_sum[i + j]++;
            }
        }
        cout << pair_sum[-2];
        int count = 0;
        for (int i : nums3) {
            for (int j : nums4) {
                if (pair_sum.count(-(i + j)))   
                    count += pair_sum[-(i + j)];
            }
        }

        return count;
    }
};