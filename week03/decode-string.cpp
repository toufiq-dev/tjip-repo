class Solution {
public:
    // TC: O(|s|) 
    // SC: O(|s|) 
    string decodeString(string s) {
        stack<pair<string, int>> stk;
        stk.push({"", 1});
        auto times = 0;

        for(auto &c : s) {
            if (isdigit(c)) {
                times = (times * 10) + (c - '0');
            }
            else if (c == '[') {
                stk.push({"", times});
                times = 0;
            }
            else if (c == ']') {
                auto repeat = stk.top().second;
                auto str = stk.top().first;
                stk.pop();

                while(repeat--) {
                    stk.top().first += str;
                }
            }
            else {
                stk.top().first.push_back(c);
            }
        }

        return stk.top().first;
    }
};