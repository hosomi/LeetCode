class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        std::sort(prices.begin(), prices.end());

        int size = prices.size();
        for (int i = 0; i< size - 1; i++) {
            if ((prices[i] + prices[i + 1]) <= money) {
                return money - (prices[i] + prices[i + 1]);
            } 
        }
        return money;
    }
};
