class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {

        std::sort(events.begin(), events.end());
        int size = events.size();
        vector<vector<int>> dp(size + 1, vector<int> (k + 1, -1));
        return solve(events, k, 0, dp, size);
    }

private:
    int solve(vector<vector<int>> &events, int k,
        int idx, vector<vector<int>>& dp, int size) {
        
        if (idx == size || k == 0) {
            return 0;
        }

        if (dp[idx][k] != -1) {
            return dp[idx][k];
        }

        int result = solve(events, k, idx + 1, dp, size);
        int curr_end = events[idx][1];
        int l = idx + 1;
        int r = size - 1;
        int idx2 = size;
        while(l <= r) {
            int mid = (l + r) / 2;
            if (events[mid][0] > curr_end) {
                idx2 = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return dp[idx][k] = std::max(result,
            events[idx][2] + solve(events, k-1, idx2, dp, size));
    }
};
