class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        
        long long dp[100000 + 1] = {0};
        dp[zero]++;
        dp[one]++;
        int l = zero < one ? zero : one;
        for (int i = l + 1; i <= high; i++) {
            if ((i-zero ) > 0) {
                dp[i] += (dp[i - zero] % long(pow(10, 9) + 7));
            }

            if ((i - one) > 0) {
                 dp[i] += (dp[i - one] % long(pow(10, 9) + 7));
            }
        }

        long long sum = 0;
        for (int i = low; i <= high; i++) {
            sum += dp[i];
        }
        return sum % (int(pow(10, 9)) + 7);
    }
};
