class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        
        vector<int> dp(books.size() + 1);
        dp[0] = 0;
        dp[1] = books[0][1];
        for (int i = 2; i <= books.size(); i++){
            int th = books[i - 1][0];
            int ht = books[i - 1][1];
            dp[i] = books[i - 1][1] + dp[i - 1];
            int limit = books[i-1][0];
            int max_height = books[i - 1][1];
            for (int j = i - 1; j > 0; j--) {
                limit += books[j - 1][0];
                max_height = std::max(max_height, books[j - 1][1]);
                if (limit > shelfWidth) {
                    break;
                }
                dp[i] = std::min(dp[i], max_height + dp[j - 1]);
            }
        }
        return dp[books.size()];
    }
};
