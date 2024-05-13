class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int base = pow(2, m - 1);
        vector<int> flips(n, 0);
        for (int i = 0; i < n; ++ i) {
            flips[i] = !grid[i][0];
        }

        int result = base * n;
        for (int i = 1; i < m; ++i) {
            int cnt = 0;
            base /= 2;
            for (int j = 0; j < n; ++ j) {
                if (flips[j]) {
                    grid[j][i] = !grid[j][i];
                }
                cnt += grid[j][i];
            }
            result += base * std::max(cnt, n - cnt);
        }
        return result;
    }
};
