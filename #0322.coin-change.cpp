class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> result(amount + 1, amount + 1);
        result[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin > i) {
                    continue;
                }
                result[i] = std::min(result[i], result[i - coin] + 1);
            }
        }
        return result[amount] > amount ? - 1 : result[amount];
    }
};
