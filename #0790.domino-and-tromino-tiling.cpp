class Solution {
public:
    int numTilings(int n) {

        const int mod = 1000000007;
        vector<vector<long>> result(n + 1, vector<long>(2, 0));
        result[0][0] = result[1][0] = 1;
        for (int i = 2; i <= n; ++i) {
            result[i][0] = (result[i-1][0] + result[i-2][0] + 2 * result[i-1][1]) % mod;
            result[i][1] = (result[i-2][0] + result[i-1][1]) % mod;
        }
        return result[n][0];
    }
};
