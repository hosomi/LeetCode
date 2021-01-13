class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();
        vector<bool> v(n + 1, false);
        v[n] = true;

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j <= n; ++j) {
                if (v[j] && find(wordDict.begin(), wordDict.end(), s.substr(i, j - i)) != wordDict.end()) {
                    v[i] = true;
                    break;
                }
            }
        }

        return v[0];
    }
};
