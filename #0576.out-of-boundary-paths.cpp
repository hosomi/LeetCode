class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        long path[m][n][maxMove + 1]; 
        memset(path, -1, sizeof(path));
        function<long(int, int, int)> fnPath = [&](int i, int j, int mv) {
            if (i < 0 || i >= m || j < 0 || j >= n) {
                return 1l;
            }

            if (mv == 0) {
                return 0l;
            }

            if (path[i][j][mv] < 0) {
                path[i][j][mv] = (
                    fnPath(i - 1, j, mv - 1) +
                    fnPath(i, j - 1, mv - 1) +
                    fnPath(i, j + 1, mv - 1) +
                    fnPath(i + 1, j, mv - 1)) % 1'000'000'007; 
            }

            return path[i][j][mv]; 
        }; 
        
        return fnPath(startRow, startColumn, maxMove); 
    }
};
