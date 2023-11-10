class Solution {
public:
    // TC: O(N) where N = |s|
    // SC: O(N) where N = |s|
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> bracketMap = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (auto &c : s) {
            if (bracketMap.count(c)) {
                char topElement = stk.empty() ? '#' : stk.top();
                if (topElement != bracketMap[c]) {
                    return false;
                }
                stk.pop();
            } else {
                stk.push(c);
            }
        }

        return stk.empty();
    }
};