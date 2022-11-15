class Solution {
public:
    bool canCross(vector<int>& stones) {

        int size = stones.size();
        if (size == 0) {
            return true;
        }
        set<int> s(stones.begin(), stones.end());
        stones = vector<int>(s.begin(), s.end());
        
        int goal = stones.back();
        

        
        vector<vector<bool>> dp(size, vector<bool>(size + 1, false));
        dp[0][1] = true;
        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                int jump = stones[i] - stones[j];
                if (jump >= size + 1 || !dp[j][jump]) {
                    continue;
                }
                
                if (i == size - 1) {
                    return true;
                }
                
                for (int k = jump - 1; k <= jump + 1; k++) {
                    if (k <= 0) {
                        continue;
                    }

                    dp[i][k] = true;
                }
            }
        }
        
        return false;
    }
};