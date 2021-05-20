class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int size = triangle.size();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }

                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                } else if (j == i) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                }
            }
        }
        return *std::min_element(begin(triangle.back()), end(triangle.back()));
    }
};
