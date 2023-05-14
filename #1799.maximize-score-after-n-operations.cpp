class Solution {
public:
    int maxScore(vector<int>& nums) {
        
        memset(dp,-1, sizeof(dp));
        size = nums.size();
        return find(nums, 1, 0);
    }

private:
    int size;
    int dp[10][1<<15];
    int find(vector<int>&nums, int index, int mask) {

        if (index > size / 2) {
            return 0;
        }

        if (dp[index][mask] != -1) {
            return dp[index][mask];
        }

        int val = INT_MIN;
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                int m = (1 << i) + (1 << j);
                if ((mask & m) == 0) {
                    val = std::max(val, index * (__gcd(nums[i], nums[j]))
                        + find(nums, index + 1, mask | m));
                }
            }
        }
        return dp[index][mask] = val;
    }
};
