class Solution {
public:
    int divide(int dividend, int divisor) {
        assert(divisor != 0);
        if(dividend == -2147483648 && divisor == -1) {
            return 2147483647;
        }
        bool rev = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long result = 0;
        while(a >= b) {
            long long c = b;
            for(int i=0; a >= c; ++i, c <<= 1) {
                a -= c;
                result += (1 << i);
            }
        }
        return rev ? (-result) : (result);
    }
};
