class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        int size = prices.size();
        for (int i = 0; i < size; i++) {
            int j;
            for (j = i+1; j < size; j++) {
                if (prices[j] <= prices[i]) {
                    break;
                }
            }

            if (j < size && prices[j] <= prices[i]) {
                prices[i] -= prices[j];
            }
        }
        return prices;
    }
};
