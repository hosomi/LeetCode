class Solution {
public:
    double myPow(double x, int n) {

        bool isPow = n < 0;
        double result = 1;
        n = abs(n);
        for (int i = 31; i >= 0; i--) {
            result = result * result;
            if (n & 1 << i) {
                result = result * x;
            }
        }

        if (isPow) {
            result = 1/result;
        }
        return result;
    }
};
