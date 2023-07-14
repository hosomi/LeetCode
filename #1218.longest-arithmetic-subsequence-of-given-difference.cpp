class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        int size = arr.size();
        map<int,int> dp;
        dp[arr[0]] = 1;
        int max = 1;
        for (int i = 1 ; i < size ; i++) {
            dp[arr[i]] = (dp[i], dp[arr[i] - difference] + 1); 
            max = std::max(max, dp[arr[i]]);
        }
        return max;
    }
};
