class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

        int n = box.size();
        int m = box[0].size();
        vector<vector<char>> results(m, vector<char> (n, '.'));
        for (int i = 0; i < n; i++) {
            int ind = m - 1;
            for (int j = m - 1; j >= 0; j--) {
                if (box[i][j] == '#') {
                    results[ind][n - i - 1] = '#';
                    ind--;
                } else if(box[i][j] == '*') {
                    results[j][n - i - 1] = '*';
                    ind = j - 1;
                }
            }
        }
        return results;
    }
};
