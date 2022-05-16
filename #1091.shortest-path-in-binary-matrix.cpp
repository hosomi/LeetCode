class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int size = grid.size() -1;
        std::queue<int> q;
        q.push(0);
        if (grid[0][0] == 1 || grid[size][size] == 1) {
            return -1;
        }

        grid[0][0] = 1;
        while (q.size() > 0) {
            int cur = q.front();
            q.pop();
            int i = cur & (1 << 7) - 1;
            int j = cur >> 7;
            if (i == size && j == size) {
                return grid[size][size];
            }
            
            for (int k = std::max(i - 1, 0); k <= std::min(i + 1, size); k++) {
                for (int l = std::max(j - 1, 0); l <= std::min(j + 1, size); l++) {
                    if (grid[k][l] == 0) {
                        grid[k][l] = grid[i][j] + 1;
                        q.push(k + (l << 7));
                    }
                }
            }
        }
        return -1;
    }
};
