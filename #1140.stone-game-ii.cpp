class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        
        memset(dp, -1, sizeof(dp));
        return helper(0, true, 1, piles);
    }

private:
    int dp[101][203][2];

    int helper(int node, int player,
        int m, vector<int>&piles) {

        int size = piles.size();
        if (node >= size) {
            return 0;
        }
        
        if (dp[node][m][player] != -1) {
            return dp[node][m][player];
        }

        if (player) {
            int take = 0;
            int result = INT_MIN;
            for (int i = node ; i < node + 2 * m and i < size; i++ ) {
                take += piles[i];
                result = std::max(result,
                    take + helper(i+1, !player, std::max(m, i-node + 1), piles)); 
            }
            return dp[node][m][player] = result;
        }

        int take = 0;
        int result = INT_MAX;
        for (int i = node ; i < node + 2 * m and i < size; i++) {
            result = std::min(result,
                helper(i + 1, !player, std::max(m, i - node + 1), piles));
        }
        return dp[node][m][player] = result;
    }
};
