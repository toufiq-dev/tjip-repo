#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = 1;
        int maxProfit = 0;

        while(j < prices.size()) {
            if(prices[i] < prices[j]) {
                maxProfit += prices[j] - prices[i];
                i++;
                j++;
            } else {
                i++;
                j++;
            }
        }

        return maxProfit;
    }
};

int main() {
    vector<int> stock_prices = {1,2,3,4,5};

    Solution* sln = new Solution();

    int ans = sln -> maxProfit(stock_prices);

    cout << ans << endl;

    return 0;
}