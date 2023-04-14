class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int size = s.size();
        vector<vector<int>> result(size, vector(size, 0));
        for (int i = size - 1; i >= 0; i--) {
            for (int j = i; j < size; j++) {
                if (i == j) {
                    result[i][j] = 1;
                } else if(i+1 == j) {
                    result[i][j] = (s[i] == s[j]) ? 2 : 1;
                } else if (i+1 < j) {
                    result[i][j] =
                        std::max({result[i+1][j-1]
                            + ((s[i] == s[j]) ? 2 : 0),
                            result[i+1][j],
                            result[i][j-1]});
                }
            }
        }
        return result[0][size - 1];
    }
};
