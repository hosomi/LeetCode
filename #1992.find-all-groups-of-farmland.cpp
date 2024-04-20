class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        int row = land.size();
        int col = land[0].size();
        vector<pair<int,int>> moves{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        auto ok = [&](int i,int j) {
            return i >= 0 && j >= 0 && i < row && j < col;
        };

        vector<vector<bool>> arr1(row, vector<bool>(col));
        vector<int> arr2;
        auto dfs = [&](auto&&dfs, int i, int j) -> void {
            arr1[i][j] = true;
            if (arr2[0] >= i) {
                arr2[0] = i;
                arr2[1] = std::min(arr2[1], j);
            }
            if (arr2[2] <= i){
                arr2[2] = i;
                arr2[3] = std::max(arr2[3], j);
            }
            for (auto [u,v]: moves) {
                int x = i+u, y = j+v;
                if(ok(x,y) && land[x][y] && !arr1[x][y])
                    dfs(dfs,x,y);
            }
        };

        vector<vector<int>> results;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (land[i][j] && !arr1[i][j]) {
                    arr2 = vector<int>{1000, 1000, -1000, -1000};
                    dfs(dfs, i, j);
                    results.push_back(arr2);
                }
            }
        }
        return results;
    }
};
