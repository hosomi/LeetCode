class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int result = 0;
        int buy = INT_MAX;
        int cash = 0;
        for (int price : prices) {
            cash = max(cash, price - buy);
            buy = min(buy, price);
            result = max(result, cash);
        }
        return result;
    }
};
