class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int size = prices.size();
        if (size <= 1) {
            return 0;
        }

        int result;
        vector<int>moneys;
        moneys.push_back(0);
        int money = prices[0];
        for (int i = 1; i < size -1; ++i) {
            moneys.push_back(std::max(moneys[i-1], prices[i] - money));
            money = std::min(money, prices[i]);
        }

        money = prices.back();
        result = moneys.back();
        for (int i = size - 2; i >= 0; --i) {
            result = std::max(result, money - prices[i] + moneys[i]);
            money = std::max(money, prices[i]);
        }
        return result;
    }
};
