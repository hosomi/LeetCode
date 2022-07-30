class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {

        int size = grid.size();
        vector<pair<int, int>> areas = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int max = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j]) {
                    max += 2;
                    for (pair<int, int> area : areas) {
                        int first = i + area.first;
                        int second = j + area.second;
                        int col = 0;
                        if (first >= 0 && first < size && second >= 0 && second < size) {
                            col = grid[first][second];
                        }
                        max += std::max(grid[i][j] - col, 0);
                    }
                }
            }
        }
        return max;
    }
};
