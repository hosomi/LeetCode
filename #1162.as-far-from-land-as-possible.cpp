class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>> q;
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j=0; j < col; j++) {
                if (grid[i][j] == 1) {
                    q.push({i,j});
                    count++;
                }
            }
        }

        if (count == 0 || count == row * col) {
            return -1;
        }

        int level = 0;
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (q.size() != 0) {
            int size = q.size();
            while (size-->0) {
                pair<int,int> rvtx = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int r = rvtx.first + dir[i][0];
                    int c = rvtx.second + dir[i][1];
                    if (r >= 0 && c >= 0
                        && r < row
                        && c < col
                        && grid[r][c] == 0) {
                        q.push({r,c});
                        grid[r][c]=1;
                    }
                }
            }
            level++;
        }
        return level-1;  
    }
};
