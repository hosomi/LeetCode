class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {

        vector<vector<int>> lr(n, vector<int>(n, 1));
        vector<vector<int>> tb(n, vector<int>(n, 1));
        for (auto& m : mines) {
            lr[m[0]][m[1]] = 0, tb[m[0]][m[1]] = 0;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (lr[i][j] == 0) {
                    continue;
                }
                lr[i][j] = 1 + (j > 0 ? lr[i][j - 1] : 0);
                tb[i][j] = 1 + (i > 0 ? tb[i - 1][j] : 0);
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (lr[i][j] == 0) {
                    continue;
                }
                lr[i][j] = std::min(lr[i][j], 1 + (j + 1 < n ? lr[i][j + 1] : 0));
                tb[i][j] = std::min(tb[i][j], 1 + (i + 1 < n ? tb[i + 1][j] : 0));
            }
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result = std::max(result, std::min(lr[i][j], tb[i][j]));
            }
        }
        return result;
    }
};
