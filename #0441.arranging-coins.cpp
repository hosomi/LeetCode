class Solution {
public:
    int arrangeCoins(int n) {

        int col = std::ceil(std::sqrt(2) * std::sqrt(n));
        while ((col + 1) * (col / 2.0) > n) {
            col--;
        }
        return col;
    }
};
