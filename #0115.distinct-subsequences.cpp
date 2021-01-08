typedef long long int lli;
class Solution {
   public:
   int numDistinct(string s, string t) {

      int n = s.size();
      int m = t.size();
      s = " " + s;
      t = " " + t;
      vector < vector <lli>> dp(n + 1, vector <lli> (m + 1));
      dp[0][0] = 1;

      for (int i = 1; i<= n; i++) {
          dp[i][0] = 1;
      }

      for (int i = 1; i <= n; i++) {
         for (int j = 1; j <= m; j++) {
            if(s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            dp[i][j] += dp[i - 1][j];
         }
      }

      return dp[n][m];
   }
};
