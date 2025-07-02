class Solution {
public:
    int possibleStringCount(string word, int k) {

        int n = word.size();
        long long ans = 1L;
        vector<int> cnt;
        for (int i = 0; i < n; i ++) {
            int j = i + 1;
            if (word[i] != word[j]) {
                cnt.push_back(1);
                continue;
            }

            while (j < n && (word[i] == word[j])) {
                j ++;
            }
            cnt.push_back(j - i);
            ans = (ans * (j - i)) % MOD;
            i = j - 1;
        }

        int m = cnt.size();
        if (m >= k) {
            return (int)ans;
        }

        vector<int> dp(k, 0);
        dp[0] = 1;
        vector<int> pfxSum(k + 1, 1);
        pfxSum[0] = 0;
        for (int x : cnt) {
            for (int i = 0; i < k; i ++) {
                if (i >= x) {
                    dp[i] = (pfxSum[i] - pfxSum[i - x] + MOD) % MOD;
                } else {
                    dp[i] = pfxSum[i];
                }
            }

            for (int i = 0; i < k; i ++) {
                pfxSum[i + 1] = (pfxSum[i] + dp[i]) % MOD;
            }
        }

        for (int x : dp) {
            ans = (ans - x + MOD) % MOD;
        }
        return ans;
    }

private:
    const int MOD = 1e9 + 7;
};
