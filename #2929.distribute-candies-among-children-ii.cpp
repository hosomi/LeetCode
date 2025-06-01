class Solution {
public:
    long long distributeCandies(int n, int limit) {
        
        long long res = (n + 2) * 1ll * (n + 1) / 2;
        long long x = max(0, n - limit - 1 + 2);
        long long x2 = max(0ll, n - 2ll * limit - 2 + 2);        
        long long x3 = max(0ll, n - 3ll * limit - 3 + 2);
        long long ex = 3ll * x * (x - 1) / 2 - (3 * x2 * (x2 - 1) / 2) + x3 * (x3 - 1) / 2;
        res -= ex;
        return res;
    }
};
