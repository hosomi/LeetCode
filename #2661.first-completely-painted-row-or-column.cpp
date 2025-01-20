class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
        int len = arr.size();
        vector<int>rowFreq(m, 0);
        vector<int>colFreq(n, 0);
        unordered_map<int, pair<int, int>> map;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                map[mat[i][j]] = {i, j};
            }
        }

        for (int i = 0; i < len; i++) {
            auto[row, col] = map[arr[i]];
            rowFreq[row]++;
            colFreq[col]++;
            if (rowFreq[row] ==n || colFreq[col] == m) {
                return i;
            }
        }
        return -1;
    }
};
