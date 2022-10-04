class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {

        int size1 = s1.size();
        int size2 = s2.size();
        vector<vector<int>> result(size1 + 1, vector(size2 + 1, 0));
        for (int i = 0; i <= size1; i++) {
            for (int j = 0; j <= size2; j++) {
                if (i == 0 && j == 0){
                    result[i][j] = 0;
                } else if(j == 0) {
                    result[i][j] = result[i - 1][j] + s1[i - 1];
                } else if (i == 0) {
                    result[i][j] = result[i][j - 1] + s2[j - 1];
                } else if (s1[i-1] == s2[j - 1]) {
                    result[i][j] = result[i - 1][j - 1];
                } else {
                    result[i][j] = std::min(
                        result[i - 1][j] + s1[i - 1],
                        result[i][j - 1] + s2[j - 1]
                    );
                }
            }
        }
        return result[size1][size2];
    }
};
