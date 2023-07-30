class Solution {
public:
    int strangePrinter(string s) {
        
        int size = s.size();
        dp.resize(size, vector<int>(size));
        return strangePrinter(s, 0, size - 1);
    }

private:
    vector<vector<int>> dp;
    int strangePrinter(string &s,
        int left, int right) {

        if (left > right) {
            return 0;
        }

        if (dp[left][right]) {
            return dp[left][right];
        }

        int result = 1 + strangePrinter(s, left + 1, right);
        for (int i = left + 1; i <= right; i++) {
            if (s[i] == s[left]) {
                result = std::min(result,
                    strangePrinter(s, left + 1, i - 1) +
                    strangePrinter(s, i, right));
            }
        }
        return dp[left][right] = result;
    }
};
