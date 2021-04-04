class Solution {
public:
    int mySqrt(int x) {

        constexpr double epsilon = 1e-2;
        double d = x;
        while (d * d - x > epsilon) {
            d = (d + x / d) / 2.0;
        }
        return d;
    }
};
