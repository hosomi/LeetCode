class Solution {
public:
    int totalMoney(int n) {

        int d = n / 7;
        int r = n % 7;
        return 28 * d + 7 * (d - 1) * d / 2
            + r* (2 * (d + 1) + r - 1) / 2;
    }
};
