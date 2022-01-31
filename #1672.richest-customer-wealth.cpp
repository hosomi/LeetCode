class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        int row = accounts.size();
        int col = accounts[0].size();
        int result = 0;
        for (int i = 0; i < row; i++) {
            int max = 0;
            for (int j = 0; j < col; j++) {
                max += accounts[i][j];
            }
            result = std::max(result, max);
        }
        return result;
    }
};
