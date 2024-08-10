class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        
        int n = grid.size();
        vector<vector<vector<bool>>> adj(n, 
            vector<vector<bool>>(n, vector<bool>(4, 0)));
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    if (!adj[i][j][k]) {
                        result++;
                        trav(grid, adj, i, j, k, n);
                    }
                }
            }
        }
        return result;
    }

private:
    void trav(vector<string> &grid,
        vector<vector<vector<bool>>> &adj,
        int i, int j, int k, int &n) {

        if (i < 0 || j < 0 || i >= n || j >=n || k >= 4
            || adj[i][j][k]) {
            return;
        }

        adj[i][j][k] = 1;
        trav(grid
            ,adj
            ,i + (k + 1) % 2 * (k - 1)
            ,j + k % 2 *(2 - k)
            ,(k + 2) % 4, n
        );

        if (grid[i][j] != '/') {
            trav(grid, adj, i, j, (int)(4 + k + pow(-1, k)) % 4, n);
        }
        if (grid[i][j] != '\\') {
            trav(grid, adj, i, j, (int)(4 + k - pow(-1, k)) % 4, n);
        }
    }

};
