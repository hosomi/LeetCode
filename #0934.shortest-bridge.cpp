class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        stack<pair<int, int>> st;
        bool done = false;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    st.push({i, j});
                    grid[i][j] = 2;
                    done = true;
                    break;
                }
            }

            if (done) {
                break;
            }
        }
        
        while (!st.empty()) {
            auto top = st.top();
            st.pop();
            int x = top.first;
            int y = top.second;
            vector<pair<int, int>> directions = {
                {x - 1, y}, 
                {x + 1, y}, 
                {x, y + 1},
                {x, y - 1}
            };
            for (auto d:directions) {
                int x_new = d.first;
                int y_new = d.second;
                if (x_new >= 0 && x_new < row && y_new >= 0
                    && y_new < col && grid[x_new][y_new] == 1) {
                    st.push({x_new, y_new});
                    grid[x_new][y_new] = 2;
                }
            }
                
        }
        
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    q.push({{i, j}, -1});
                }
            }
        }
        
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            int count = top.second;
            int x = top.first.first;
            int y = top.first.second;
            vector<pair<int, int>> directions = {
                {x - 1, y}, 
                {x + 1, y}, 
                {x, y + 1},
                {x, y - 1}
            };
            for (auto d: directions) {
                int x_new = d.first;
                int y_new = d.second;
                if (x_new >= 0 && x_new < row
                    && y_new >= 0 && y_new < col) {
                    if (grid[x_new][y_new] == 0) {
                        q.push({{x_new, y_new}, count+1});
                        grid[x_new][y_new] = 1;
                    } else if (grid[x_new][y_new] == 2) {
                        return count + 1;
                    }
                }
            }
        }
        return -1;
    }
};
