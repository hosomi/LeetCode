class Solution {
public:
    int maxCoins(vector<int>& piles) {

        std::sort(piles.begin(), piles.end());

        int size = piles.size();
        int piles3 = size / 3;
        int result = 0;
        for (int i = size - 2; i >= piles3; i -= 2) {
            result += piles[i];
        }
        return result;
    }
};
