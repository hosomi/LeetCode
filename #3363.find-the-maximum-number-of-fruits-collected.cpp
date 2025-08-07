class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {

        int n = fruits.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }
        
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        dp1[n - 1] = fruits[n - 1][0];
        for (int col = 1; col < n; ++col) {
            auto prev = dp1;
            dp1.assign(n, -1);
            for (int x = n / 2 + n % 2; x < n; ++x) {
                for (int dx = -1; dx <= 1; ++dx) {
                    int prevRow = x + dx;
                    if (prevRow < 0 || prevRow >= n || prev[prevRow] < 0) {
                        continue;
                    }

                    dp1[x] = max(dp1[x], prev[prevRow] + fruits[x][col]);
                }
            }
        }

        dp2[n - 1] = fruits[0][n - 1];
        for (int row = 1; row < n; ++row) {
            auto prev = dp2;
            dp2.assign(n, -1);
            for (int y = n / 2 + n % 2; y < n; ++y) { 
                for (int dy = -1; dy <= 1; ++dy) {
                    int prevCol = y + dy;
                    if (prevCol < 0 || prevCol >= n || prev[prevCol] < 0) {
                        continue;
                    }
                    dp2[y] = max(dp2[y], prev[prevCol] + fruits[row][y]);
                }
            }
        }
        return ans + dp1.back() + dp2.back();
    }
};
