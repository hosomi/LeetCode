class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        int n = grid.size();
        int m = grid[0].size();
        vector<int>one_D(n * m);
        for (int i = 0; i < n * m; i++) {
            one_D[i] = grid[i / m][i % m];
        }

        std::sort(one_D.begin(), one_D.end());

        int t = one_D[(n * m) / 2];
        int ans = 0;
        for (int i = 0; i < n * m; i++) {
            if (std::abs(one_D[i] - t) % x != 0) {
                return -1;
            } else {
                ans += std::abs(one_D[i] - t) / x;
            }
        }
        return ans;   
    }
};
