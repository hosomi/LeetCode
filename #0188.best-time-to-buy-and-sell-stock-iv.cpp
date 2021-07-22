class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        if (prices.size() < 2) {
            return 0;
        }

        int size = prices.size();
        int price = 0;
        if (k >= prices.size() / 2) {
            for (int i = 1; i < size; i++) {
                if (prices[i] > prices[i - 1]) {
                    price += prices[i] - prices[i - 1];
                }
            }
            return price;
        }

        vector<int> cursor(k + 1);
        vector<int> cursor2(k + 1);
        size--;
        for (int i = 0; i < size; i++) {
            price = prices[i + 1] - prices[i];
            for (int j = k; j >= 1; j--) {
                cursor[j] = std::max(cursor2[j - 1]
                    + std::max(price, 0), cursor[j] + price);
                cursor2[j] = std::max(cursor2[j], cursor[j]);
            }
        }
        return cursor2.back();
    }
};
