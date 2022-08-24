class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int rowSize = grid.size();
        int colSize = grid[0].size();
        vector<vector<bool>> visited(rowSize, vector<bool>(colSize, 0));
        stack<vector<int>> stk;
        for (int i = 0; i < rowSize; i++) {
            if (grid[i][0] == 1) {
                visited[i][0] = true;
                stk.push({i, 0});
            }
            
            if (grid[i][colSize - 1] == 1) {
                visited[i][colSize - 1] = true;
                stk.push({i, colSize - 1});
            }
        }
        
        for (int i = 1; i < colSize - 1; i++) {
            if (grid[0][i] == 1) {
                visited[0][i] = true;
                stk.push({0, i});
            }
            
            if (grid[rowSize - 1][i] == 1) {
                visited[rowSize - 1][i] = true;
                stk.push({rowSize - 1, i});
            }
        }
        
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!stk.empty()) {
            vector<int> cur = stk.top(); stk.pop();
            int cur1 = cur[0];
            int cur2 = cur[1];
            
            for (vector<int>& dir : dirs) {
                int next1 = cur1 + dir[0];
                int next2 = cur2 + dir[1];
                if (next1 >= 0 
                    && next1 < rowSize 
                    && next2 >= 0 
                    && next2 < colSize 
                    && !visited[next1][next2] 
                    && grid[next1][next2] == 1) {
                    visited[next1][next2] = true;
                    stk.push({next1, next2});
                }
            }
        }
        
        int result = 0;
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    result++;
                }
            }
        }
        return result;
    }
};
