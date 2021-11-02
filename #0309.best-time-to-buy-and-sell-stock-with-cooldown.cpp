class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int size = prices.size();
        if (size == 0) {
            return 0;
        }

        vector<int> buy(size + 1, 0);
        vector<int> sell(size + 1, 0);
        prices.insert(prices.begin(), 0);
        buy[1] = - prices[1];
        for(int i = 2; i <= size; i++){
            buy[i] = std::max(buy[i - 1], sell[i - 2] - prices[i]);
            sell[i] = std::max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        return sell[size];
    }
};
