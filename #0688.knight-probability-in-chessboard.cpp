class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        
        if (k == 0) {
            return 1.00000;
        }

        vector<vector<vector<double>>>dp(n,
            vector<vector<double>>(n, vector<double>(k + 1, -1)));
        return recursion(n, k, row, column, dp);
    }

private:
    double recursion(int n,int k,int row,int col, vector<vector<vector<double>>>&dp) {

        if (row<0 || row>=n || col>=n || col<0) {
            return 0;
        }

        if (k == 0) {
            return 1;
        }

        if (dp[row][col][k] != -1) {
            return dp[row][col][k];
        }

        int coli[] = {-1, -2, -1, -2, +1, +2, +1, +2};
        int colj[] = {-2, -1, +2, +1, -2, -1, +2, +1};
        double result = 0;
        for (int i = 0; i < 8; i++) {
             result += recursion(n, k - 1, row + coli[i], col + colj[i], dp);
        }
        return dp[row][col][k] = result / (double)8;
    }    
};
