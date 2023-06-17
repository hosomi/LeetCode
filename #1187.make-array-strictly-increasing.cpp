class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {

        sort(begin(arr2), end(arr2));
        auto res = dfs(arr1, arr2, 0, 0, true);
        return res >= max_val ? -1 : res;
    }

private:
    short dp[2001][2001][2] = {};
    short max_val = 2002;
    
    short dfs(vector<int>& arr1, vector<int>& arr2,
        int i, int j, bool prev_t) {

        if (i >= arr1.size()) {
            return 0;
        }

        int prev = prev_t ? i == 0 ? INT_MIN : arr1[i - 1] : arr2[j];
        j = upper_bound(begin(arr2) + j, end(arr2), prev) - begin(arr2);
        if (dp[i][j][prev_t] == 0) {
            dp[i][j][prev_t] = max_val;
            if (j < arr2.size()) {
                dp[i][j][prev_t] = dfs(arr1, arr2, i + 1, j, false) + 1;
            }

            if (prev < arr1[i]) {
                dp[i][j][prev_t] = std::min(dp[i][j][prev_t],
                    dfs(arr1, arr2, i + 1, j, true));
            }
        }
        return dp[i][j][prev_t];
    }
};
