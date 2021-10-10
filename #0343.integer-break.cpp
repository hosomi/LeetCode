class Solution {
public:
    int integerBreak(int n) {

        int result[n + 1];
        std::memset(result, -1, sizeof(result));
        result[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i - 1; ++j) {
                result[i] = std::max(result[i], result[i - j] * j);
                result[i] = std::max(result[i], (i - j) * j);
            }
        }
        return result[n];
    }
};
