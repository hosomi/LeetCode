class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        int size = img1.size();
        int max = 0;
        for (int i = -(size - 1); i <= size - 1; ++i) {
            for (int j = -(size - 1); j <= size - 1; ++j) {
                int temp = 0;
                for (int k = std::max(0, -i); k < std::min(size, size - i); ++k) {
                    for (int l = std::max(0, -j); l < std::min(size, size - j); ++l) {
                        temp += img1[k + i][l + j] * img2[k][l];
                    }
                }
                max = std::max(max, temp);
            }
        }
        return max;
    }
};
