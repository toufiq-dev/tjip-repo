class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    int maxProfit(vector<int>& prices) {
        int lowest = INT_MAX;
        int profit = 0;

        for(int i = 0; i < prices.size(); ++i) {
            lowest = min(lowest, prices[i]);
            profit = max(profit, prices[i] - lowest);
        }

        return profit;
    }
};
