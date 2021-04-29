class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int leftsize = s1.size();
        int rightsize = s2.size();
        if (leftsize + rightsize != s3.size()) {
            return false;
        }

        vector<vector<bool>> result(2, vector<bool>(rightsize + 1, false));
        for (int i = leftsize; i >= 0; --i) {
            for (int j = rightsize; j >= 0; --j) {
                if (i == leftsize && j == rightsize) {
                    result[i & 1][j] = true;
                    continue;
                }

                if (s1[i] == s3[i + j] && result[(i + 1) & 1][j]) {
                    result[i & 1][j] = true;
                    continue;
                }

                if (s2[j] == s3[i + j] && result[i & 1][j + 1]) {
                    result[i & 1][j] = true;
                    continue;
                }

                result[i & 1][j] = false;
            }
        }
        return result[0][0];
    }
};
