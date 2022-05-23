class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        int size = strs.size();
        vector<vector<vector<int>>> result(2, vector<vector<int>>(m + 1, vector(n + 1, 0)));
        for (int i = 0; i < size; i++) {
            int count = std::count(strs[i].begin(), strs[i].end(), '0');
            int diff = strs[i].size() - count;
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (i == 0) {
                        result[i%2][j][k] = (j >= count && k >= diff);
                        continue;
                    }

                    result[i%2][j][k] = std::max(
                        result[(i - 1) % 2][j][k],
                        (j >= count && k >= diff) ? 1 + result[(i - 1) % 2][j - count][k - diff] : 0);
                }
            }
        }
        return result[(size - 1) % 2][m][n];
    }
};
