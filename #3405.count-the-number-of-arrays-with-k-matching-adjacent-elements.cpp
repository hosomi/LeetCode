class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        vector<long long> fact(1e5 +5, 1LL);
        for (int i = 1; i < fact.size(); i++) {
            fact[i] = (fact[i-1] * i) % mod;
        }
        return (m * 1LL * (fact[n - 1] * binary(fact[n - 1 - k], mod - 2, mod)
            % mod
            * binary(fact[k], mod - 2, mod) % mod)
            % mod
            * binary(m - 1, n - 1 - k, mod)) % mod;
    }

private:
    const int mod = 1e9 + 7;
    long long binary(long long a, long long b, int m) {
        long long ans = 1;
        while (b) {
            if (b & 1) {
                ans = (ans * a) % m;
            }
            a = (a * a) % m;
            b >>= 1;
        }
        return ans;
    }
};
