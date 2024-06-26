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

