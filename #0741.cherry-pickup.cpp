class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int size = grid.size();
        vector<vector<int>> v1(size, vector<int>(size, INT_MIN));
        v1[0][0] = grid[0][0];
        int i1;
        int i2;
        int cherry;
        for (int i = 1; i <= 2 * (size - 1); ++i) {
            vector<vector<int>> v2(size, vector<int>(size, INT_MIN));
            for (int j = 0; j < size; ++j) {
                for (int k = 0; k < size; ++k) {
                    i1 = i - j;
                    i2 = i - k;
                    if (i1 < 0 || i1 >= size || i2 < 0 || i2 >= size) {
                        continue;
                    }

                    if (grid[j][i1] == -1 || grid[k][i2] == -1) {
                        continue;
                    }

                    cherry = grid[j][i1];
                    if (j != k) {
                        cherry += grid[k][i2];
                    }
                    
                    cherry += std::max({
                        (j - 1 >= 0 && k - 1 >= 0) ? v1[j - 1][k - 1] : INT_MIN,
                        v1[j][k], (j - 1 >= 0) ? v1[j - 1][k] : INT_MIN, 
                        (k - 1 >= 0) ? v1[j][k - 1] : INT_MIN 
                    }); 
                    v2[j][k] = cherry;
                }
            }
            std::swap(v1, v2);
        }
        return std::max(v1[size - 1][size - 1], 0);
    }
};
