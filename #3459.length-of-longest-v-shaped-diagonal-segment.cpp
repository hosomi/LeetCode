class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {

        m = grid[0].size();
        n = grid.size();
        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int x = 0; x < 4; x++) {
                        ans = max(ans, 1 + solve(i, j, x, 0, grid));
                    }
                }
            }
        }
        return ans;  
    }

private:
    int dp[505][505][5][3];
    int m;
    int n;  
    vector<vector<int>> dir = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    bool valid(int i,int j) {

        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int solve(int r, int c, int d, int turn, vector<vector<int>>& grid) {

        if (!valid(r, c)) {
            return 0;
        }

        if (dp[r][c][d][turn] !=-1) {
            return dp[r][c][d][turn];
        }

        int elem = grid[r][c];
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (valid(nr ,nc) && elem == 1 && grid[nr][nc] == 0) {
                continue;
            }

            if (valid(nr, nc) && grid[nr][nc] != 1 && grid[nr][nc] != elem) {
                if (turn == 0 && (d + 1) % 4 == i) {
                    ans = max(ans, 1 + solve(nr, nc, i, 1, grid));  
                }
                if (i == d) {
                    ans = max(ans ,1 + solve(nr, nc, i, turn, grid));
                }
            }
        }
        return dp[r][c][d][turn] = ans;
    }
};
