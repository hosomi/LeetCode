class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> bord = {
            {{0, -1}, {0, 1}},
            {{-1, 0}, {1, 0}},
            {{0, -1}, {1, 0}},
            {{0, 1}, {1, 0}},
            {{0, -1}, {-1, 0}},
            {{-1, 0}, {0, 1}}
        };
        queue<vector<int>> q;
        q.push({0,0});
        vector<vector<bool>> result =
            vector<vector<bool>>(row, vector<bool>(col, false));
        while (!q.empty()) {
            vector<int> index = q.front(); q.pop();
            int i = index[0];
            int j = index[1];
            int ij = grid[i][j] -1;
            result[i][j] = true;
            
            for (vector<int>& b : bord[ij]) {
                int k = i + b[0];
                int l = j + b[1];
                if (k < 0 || k >= row || l < 0 || l >= col || result[k][l]) {
                    continue;
                }
                int kl = grid[k][l] -1;
                for (vector<int>& b2 : bord[kl]) {
                    if (k + b2[0] == i && l + b2[1] == j) {
                        q.push({k, l});
                    }
                }
            }
        }
        return result[row-1][col-1];
    }
};
