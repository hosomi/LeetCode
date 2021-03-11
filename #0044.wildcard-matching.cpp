class Solution {
public:
    bool isMatch(string s, string p) {

        int ssize = s.size();
        int psize = p.size();
        vector<vector<bool>> result(ssize+1, vector(psize+1, false));
        result[ssize][psize] = true;
        bool isMatch;
        for (int i = ssize; i >= 0; i--) {
            for (int j = psize - 1; j >= 0; j--) {
                isMatch = (i < ssize) && (p[j] == s[i] || p[j] == '?' || p[j] == '*');
                
                result[i][j] = p[j] == '*' ? 
                    (isMatch && result[i+1][j]) || result[i][j+1] : 
                    isMatch && result[i+1][j+1];
            }
        }

        return result[0][0];
    }
};
