class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        
        vector<vector<long long>> v(m + 1, vector<long long>(n + 1));
        for (auto x : prices) {
            v[x[0]][x[1]] = std::max(v[x[0]][x[1]], (long long)x[2]);
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                v[i][j] = std::max(v[i][j], v[i-1][j]);
                v[i][j] = std::max(v[i][j], v[i][j - 1]);
                for (int k = 1; k < i; ++k) {
                    v[i][j] = std::max(v[i][j], v[k][j] + v[i - k][j]);
                }

                for (int k = 1; k < j; ++k) {
                    v[i][j] = std::max(v[i][j], v[i][k] + v[i][j - k]);
                }
            }
        }
        return v[m][n];
    }
};
