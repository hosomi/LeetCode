class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        vector<int> result(col, 0);
        for (int i = 0; i < col; i++) {
            result[i] = i;
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (result[j] != -1) {
                    if (grid[i][result[j]] == 1) {
                        if (result[j] != col - 1 && grid[i][result[j] + 1] == 1) {
                            result[j]++;
                        } else {
                            result[j] = -1;
                        }
                    } else if (grid[i][result[j]] == -1) {
                        if (result[j] != 0 && grid[i][result[j] - 1] == -1) {
                            result[j]--;
                        } else {
                            result[j] = -1;
                        }
                    }
                }   
            }
        }
        return result;
    }
};
