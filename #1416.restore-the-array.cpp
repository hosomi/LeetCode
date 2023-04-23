class Solution {
public:
    int numberOfArrays(string s, int k) {
        
        int size = s.size();
        int maxsize = to_string(INT_MAX).size();
        int maxmin = std::min((int)to_string(k).size(), maxsize);
        int mod = 1e9 + 7;
        vector<int> dp(size, 0);
        for (int i = 0; i < size; i++) {
            for (int j = i; j >= 0 && (i-j+1) <= maxmin; j--) {
                if (s[j] == '0') {
                    continue;
                }

                string sub = s.substr(j, i - j + 1);
                if (sub.size() == maxsize && sub[0] != '1') {
                    continue;
                }

                if (stoi(sub) > k) {
                    continue;
                }

                dp[i] += (j > 0) ? dp[j - 1] : 1;
                dp[i] %= mod;
            }
        }
        return dp[size - 1];
    }
};
