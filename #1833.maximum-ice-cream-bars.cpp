class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        std::sort(costs.begin(), costs.end());

        int size = costs.size();
        int i = 0;
		for (i ; i < size; i++) {
            if (coins < costs[i]) {
                return i;
            }
            coins = coins - costs[i];
        }
        return i;
    }
};
