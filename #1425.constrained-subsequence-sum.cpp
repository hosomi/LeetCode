class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {

        int size = nums.size();
        vector<int>dp(size ,0);
        for (int i=0;i< size; i++) {
            dp[i]=nums[i];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>>pq;
        pq.push({dp[0],0});
        int result = dp[0];
        for (int i = 1; i < size; i++) {
            while (!pq.empty() && pq.top().second < i - k) {
                pq.pop();
            }

            dp[i] = std::max(dp[i], nums[i] + pq.top().first);
            pq.push({dp[i], i});
            result = std::max(result, dp[i]);
        }
        return result;
    }
};
