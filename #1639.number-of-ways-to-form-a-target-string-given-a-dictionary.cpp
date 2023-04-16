class Solution {
public:
    int numWays(vector<string>& words, string target) {
        
        vector<vector<int>> count;
        int size = words[0].size();
        count.resize(size, vector<int>(26));
        for (auto &w:words) {
            for (int x = 0; x < size; x++) {
                count[x][w[x]-'a']++;
            }
        }

        vector<vector<long long>> dp;
        long long mod = (long long)1e9+7;
        auto last=target.back() - 'a';
        dp.resize(2,vector<long long>(size));
        dp[1][size-1]=count[size-1][last];
        for (int x = size - 2; x >= 0; x--) {
            dp[1][x] = (count[x][last] + dp[1][x+1]) % mod;
        }
        
        int start = size - 2;
        target.pop_back();
        while (target.size()) {
            auto last = target.back() - 'a';
            for (int x = start; x >= 0; x--) {
                dp[0][x] = (count[x][last] * dp[1][x + 1] + dp[0][x + 1]) % mod;
            }
    
            start--;
            dp[1] = dp[0];
            dp[0].clear();
            dp[0].resize(size, 0);
            target.pop_back();
        }
        return dp[1][0] % mod;
    }
};
