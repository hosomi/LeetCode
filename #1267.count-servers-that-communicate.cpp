class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        unordered_map<int, int> rows;
        unordered_map<int, int> cols;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }
        
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]
                    && (rows[i] > 1 || cols[j] > 1)) {
                    res++;                    
                }
            }
        }
        return res;
    }
};
