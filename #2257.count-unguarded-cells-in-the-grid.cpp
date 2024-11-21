class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

        auto arr = vector(m, vector<int>(n, 0));
        for (const auto& w : walls) {
            arr[w[0]][w[1]] = -1;
        }
        
        for (const auto& g : guards) {
            arr[g[0]][g[1]] = -1;
            for (int i = g[0] - 1; i >= 0 && !(arr[i][g[1]] & 1); --i) {
                arr[i][g[1]] |= 1;
            }
            for (int i = g[0] + 1; i < m && !(arr[i][g[1]] & 1); ++i) {
                arr[i][g[1]] |= 1;
            }
            for (int i = g[1] - 1; i >= 0  && !(arr[g[0]][i] & 2); --i) {
                arr[g[0]][i] |= 2;
            }
            for (int i = g[1] + 1; i < n  && !(arr[g[0]][i] & 2); ++i) {
                arr[g[0]][i] |= 2;
            }
        }
        return accumulate(arr.begin(), arr.end(), 0, [](int r, const auto& v) {
            return r + count(v.begin(), v.end(), 0);
        });
    }
};
