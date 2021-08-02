class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int size = grid.size();
        if (size == 0) {
            return 0;
        }

        int rowSize = grid[0].size();
        if (rowSize == 0) {
            return 0;
        }

        int result = 0;
        vector<vector<bool>> visited(size, vector<bool>(rowSize));
        vector<int> X{-1, 0, 1, 0};
        vector<int> Y{0, 1, 0, -1};
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < rowSize; ++j) {
                if (grid[i][j] == '0' || visited[i][j]) {
                    continue;
                }
                ++result;
                queue<int> q{{i * rowSize + j}};
                while (!q.empty()) {
                    int t = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int x = t / rowSize + X[k];
                        int y = t % rowSize + Y[k];
                        if (x < 0 || x >= size || y < 0
                            || y >= rowSize || grid[x][y] == '0'
                            || visited[x][y]) {
                            continue;
                        }
                        visited[x][y] = true;
                        q.push(x * rowSize + y);
                    }
                }
            }
        }
        return result;
    }
};
