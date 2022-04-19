class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {

        int result = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    result = std::max(result, grid[i][j] + dfs(grid, i, j));
                }
            }
        }
        return result;
    }

private:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    int dfs(vector<vector<int>>& grid, int i, int j){
        int ans = 0;
        int org = grid[i][j];
        grid[i][j] = 0;
        
        for(auto& direction : directions){
            int x = direction[0], y = direction[1];
            if(i + x >= 0 && j + y >= 0 && i + x < grid.size() 
               && j + y < grid[0].size()
               && grid[i+x][j+y] != 0) {
                ans = max(ans, grid[i+x][j+y] + dfs(grid, i + x, j + y));
            }
        }
        grid[i][j] = org;
        return ans;
    }
};
