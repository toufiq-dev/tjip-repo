class Solution {
public:
    // Brute-force
    // TC: O(N)
    // SC: O(N)
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> frequency;

        for(int i = 0; i < nums.size(); ++i) {
            if(frequency.count(nums[i]) == 0) frequency[nums[i]];

            frequency[nums[i]]++;
        }

        for(auto x : frequency) {
            if(x.second > floor(nums.size() / 2)) return x.first;
        }

        return -1;
    }

    // Optimal solution
    // TC: O(N)
    // SC: O(1)
    int majorityElement2(vector<int>& nums) {
        int candidate = -1, votes = 0;

        // find majority candidate
        for(int i = 0; i < nums.size(); ++i) {
            if(votes == 0) {
                candidate = nums[i];
                votes = 1;
            } else {
                if(nums[i] == candidate) {
                    votes++;
                } 
                else 
                    votes--;
            }
        }
        
        // find if majority candidate appears more than ⌊n / 2⌋ times.
        int count = 0;

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == candidate)
                count++;
        }

        if(count > floor(nums.size() / 2)) 
            return candidate;

        return -1;
    }

};
