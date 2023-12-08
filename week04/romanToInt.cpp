class Solution {
public:
    // TC: O(1)
    // SC: O(1)
    int romanToInt(string s) {
        unordered_map<string, int> roman;
        roman = {
            {"I", 1},
            {"V", 5},
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000},
        };

        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            string current = s.substr(i, 1);
            string next = s.substr(i + 1, 1);
            int digit = roman[current];
            int nextDigit = roman[next];
            
            if(digit < nextDigit) {
                digit = nextDigit - digit;
                ++i;
            }

            sum += digit;
        }

        return sum;
    }
};
