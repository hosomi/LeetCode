class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        if (accumulate(nums.begin(), nums.end(), 0L) == 0) {
            return 0;
        }

        int low = 1;
        int high = queries.size();
        int ans = INT_MAX;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (solve(nums, queries, mid)) {
                ans = std::min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans == INT_MAX? -1 : ans;
    }

private:
    bool solve(vector<int>& nums, vector<vector<int>>& queries, int mid) {

        int n = nums.size();
        vector<int> diff(n + 1);
        for (int i = 0; i < mid; i++) {
            diff[queries[i][0]] += queries[i][2];
            diff[queries[i][1] + 1] -= queries[i][2];
        }

        int currDiff = 0;
        for (int i = 0; i < n; i++) {
            currDiff += diff[i];
            if (currDiff < nums[i]) {
                return false;
            }
        }
        return true;
    }
};
