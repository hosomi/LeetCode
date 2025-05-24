class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {

        vector<int> ans;
        for (int i = 0, n = words.size(); i < n; ++i) {
            for (int j = 0, m = words[i].length(); j < m; ++j) {
                if (words[i][j] == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
