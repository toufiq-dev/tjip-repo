class Solution {
public:
    // TC: O(N * 2 ^ N)
    // SC: O(N * 2 ^ N)
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        backtrack(result, curr, 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string curr, int open, int close,
                   int max) {
        if (curr.length() == max * 2) {
            result.push_back(curr);
            return;
        }

        if (open < max)
            backtrack(result, curr + "(", open + 1, close, max);
        if (close < open)
            backtrack(result, curr + ")", open, close + 1, max);
    }
};