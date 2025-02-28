class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        string str;
        int i = m;
        int j = n;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                str += str1[i-1];
                i--;j--;
            } else if (dp[i - 1][j] >= dp[i][j - 1]){
                str += str1[i - 1];
                i--;
            } else {
                str += str2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            str += str1[i - 1];
            i--;
        }
        while (j > 0) {
            str += str2[j - 1];
            j--;
        }
        
        int l = 0;
        int r = str.size() - 1;
        while (l < r) {
            auto val = str[r];
            str[r] = str[l];
            str[l] = val;
            l++;
            r--;
        }
        return str;
    }
};
