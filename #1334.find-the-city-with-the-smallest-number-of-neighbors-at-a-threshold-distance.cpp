class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>matrix(n, vector<int>(n, 1e9));
        for (auto it : edges) {
            matrix[it[0]][it[1]] = it[2];
            matrix[it[1]][it[0]] = it[2];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    matrix[j][k] = std::min(matrix[j][k],
                        matrix[j][i] + matrix[i][k]);
                }
            }
         }

         int result = -1;
         int cnt = INT_MAX;
         for (int i = n - 1; i >= 0; i--) {
            int temp = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }

                if (matrix[i][j] <= distanceThreshold) {
                    temp++;
                }
            }

            if (temp < cnt) {
                cnt = temp;
                result=i;
            }
         }    
        return result;
    }
};
