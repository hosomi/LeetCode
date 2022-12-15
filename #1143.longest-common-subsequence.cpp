class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int row =text1.length();
        int col = text2.length();
        vector<vector<int>> v(row + 1,vector<int>(col+1));
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                v[i][j] = text1[i-1] == text2[j-1] ?
                    v[i - 1][j-1] + 1
                    : std::max(v[i - 1][j], v[i][j - 1]);
            }
        }
        return v[row][col];
    }
};
