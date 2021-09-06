class Solution {
public:
    int countDigitOne(int n) {

        int result = 0;
        for (long long l = 1; l <= n; l *= 10) {
            result += (n / (l * 10)) * l + std::min(std::max(n % (l * 10) - l + 1, 0LL), l);
        }
        return result;
    }
};
