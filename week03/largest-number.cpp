class Solution {
private:
    static bool compare(int a, int b) {
        string _a = to_string(a);
        string _b = to_string(b);

        return _a + _b > _b + _a;
    }
public:
    // TC: O(n * log(n)), where n = no. of elements in the nums array.
    // SC: O(n)
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(), nums.end(), compare);

        for (auto num : nums) {
            ans += to_string(num);
            cout << num;
        }

        int i = 0;
        while (i < ans.size() - 1 && ans[i] == '0') i++; 

        return ans.substr(i);
    }
};
