class Solution {
public:
    int superPow(int a, vector<int>& b) {

        int result = 1;
        for (int i = 0; i < b.size(); i++) {
            result = (long)pow(result, 10) * pow(a, b[i]) % MOD;
        }
        return result;
    }

private:
    const int MOD = 1337;
    int pow(int base, int exp) {

        int result = 1;
        while (exp > 0) {
            if (exp & 1) {
                result = (long)result * base % MOD;
            }
            exp >>= 1;
            base = (long)base * base % MOD;
        }
        return result;
    }
};
