class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        
        vector<pair<int, pair<int, int>>> pos;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                pos.push_back(
                    make_pair(grid[i][j], make_pair(i, j)));
            }
        }

        std::sort(pos.begin(), pos.end());
        vector<vector<int>> seq(row, vector<int>(col, 1));
        vector<int> rowDiff = { -1, 0, 0, +1 };
        vector<int> colDiff = { 0, -1, +1, 0 };
        int mod = 1e9 + 7;
        int result = 0;
        for (int i = 0; i <pos.size(); i++) {
            int currVal = pos[i].first;
            int currRow = pos[i].second.first;
            int currCol = pos[i].second.second;
            result = (result + seq[currRow][currCol]) % mod;
            for (int j = 0; j < 4; j++) {
                int adjRow = currRow + rowDiff[j];
                int adjCol = currCol + colDiff[j];
                if (adjRow < 0 || adjCol < 0
                    || adjRow >= row || adjCol >= col) {
                    continue;
                }

                if (grid[adjRow][adjCol] > grid[currRow][currCol]) {
                    seq[adjRow][adjCol] =
                        (seq[adjRow][adjCol] + seq[currRow][currCol]) % mod;
                }
            }
        }
        return result;
    }
};
