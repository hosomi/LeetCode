class Solution {
public:
    int countOrders(int n) {

        long modulo = 1e9+7;
        long result = 1;
        for (int i = 1; i <= n; i++) {
            result = result * (2 * i - 1) * i % modulo;
        }
        return (int)result;
    }
};
