class Solution {
public:
    int maxNiceDivisors(int primeFactors) {

        if (primeFactors == 1) {
            return 1;
        }

        long long b = primeFactors / 3;
        long long a = primeFactors - b * 3;
        long long mod = 1e9 + 7;
        if (a == 1) {
            a = 2;
            b--;
        } else if (a == 2) {
            a = 1;
        }
        return pow_mod(2, a, mod) * pow_mod(3, b, mod) % mod;
    }

private:
    long long pow_mod(long long x, long long y, int mod) {
    
        long long a = x % mod;
        long long result = 1;
        while (y) {
            if (y & 1) {
                result = (result * a) % mod;
            }
            a = (a * a) % mod;
            y >>= 1;
        }
        return result;
    }
};
