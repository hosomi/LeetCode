class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        int size = arr.size();
        vector<int> dp = arr;
        for (int i = 1; i < size; i++) {
            dp[i] ^= dp[i-1];
        }
        
        int left;
        int right;
        vector<int> results;
        for (vector<int>& query : queries) {
            left = query[0];
            right = query[1];
            int result = dp[right];
            if (left > 0) {
                result ^= dp[left - 1];
            }
            results.push_back(result);
        }
        return results;
    }
};
