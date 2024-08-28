class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        v = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        n = grid2.size();
        m = grid2[0].size();
        result = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid1[i][j] && grid2[i][j]) {
                    dfs(i, j, grid2, 0);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1) {
                    dfs(i, j, grid2, ++result);
                }
            }
        }

        return result-1;
    }

private:
    int n;
    int m;
    int result;
    vector<pair<int, int>> v;

    void dfs(int i, int j, vector<vector<int>>& gg, int result) {

        if (i >= 0 && j >= 0 
            && i < n && j < m
            && gg[i][j] == 1) {
            gg[i][j] = result;

            for (auto it: v) {
                dfs(i + it.first, j + it.second, gg, result);
            }
        }
    }
};
