class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int size = prices.size();
        int cash = 0;
        int price = -prices[0];
        for (int i = 1; i < size; i++) {
            cash = std::max(cash, price + prices[i] - fee);
            price = std::max(price, cash - prices[i]);
        }
        return cash;
    }
};
