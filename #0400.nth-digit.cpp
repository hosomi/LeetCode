class Solution {
public:
    int findNthDigit(int n) {

        int len = 1;
        int base = 1;
        while (n > 9L * base * len) {
            n -= 9 * base * len;
            len++;
            base *= 10;
        }

        int cursor = (n - 1)/len + base;
        int digit = 0;
        for (int i = (n - 1) % len; i < len; ++i) {
            digit = cursor % 10;
            cursor /= 10;
        }
        return digit;
    }
};
