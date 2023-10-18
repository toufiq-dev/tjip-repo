mt19937 rng(0);

class Solution {
    private:
        int createPartition(vector<int>& nums, int L, int R) {
            int pivot = nums[R];
            int i = L - 1;

            for(int j = L; j < R; ++j) {
                if(nums[j] <= pivot) {
                    swap(nums[++i], nums[j]);
                }
            }

            // fix pivot's position
            swap(nums[i + 1], nums[R]);
            
            return i + 1;
        }

        void partial_sort(vector<int>& nums, int k) {
            shuffle(nums.begin(), nums.end(), rng);
            int threshold = 2 * log2(nums.size());
            int L = 0, R = nums.size() - 1;

            while(L < R && threshold--) {
                int p = createPartition(nums, L, R);
                if(p < k)
                    L = p + 1;
                else if(p > k)
                    R = p - 1;
                else 
                    break;
            }
        }

        int findKthSmallest(vector<int>& nums, int k) {
            partial_sort(nums, k);

            return nums[k];
        }

    public:
        int findKthLargest(vector<int>& nums, int k) {
            return findKthSmallest(nums, nums.size() - k);
        }
};