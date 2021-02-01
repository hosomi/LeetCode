class Solution {
public:
    string longestPalindrome(string s) {

        int size = s.size();
        string result = "";
        vector<vector<int>> v(2, vector(size+1, 0));
        string s2(s.rbegin(), s.rend());
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {

                if (s[i-1] == s2[j-1]) {
                    v[i%2][j] = v[(i+1)%2][j-1] + 1;
                } else {
                    v[i%2][j] = 0;
                }
                
                if (v[i % 2][j] > result.size() && i + j == v[i % 2][j] + size) {
                    result = s.substr(i-v[i % 2][j], v[i % 2][j]);
                }
            }
        }
        
        return result;
    }
};
