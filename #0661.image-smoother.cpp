class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int row = img.size();
        int col = img[0].size();
        vector<pair<int,int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1}, {0, 0}, {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };
        vector<int> v;
        int sum = 0;
        int count = 0;
        vector<vector<int>> result(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                sum = 0;
                count = 0;
                for (auto dir : dirs) {
                    int k = i + dir.first;
                    int l = j + dir.second;
                    if (k >= 0 && k < row
                      && l >= 0 && l < col) {
                        sum += img[k][l];
                        count++;
                    }
                }
                result[i][j] = sum/count;
            }
        }
        return result;
    }
};
