#define min(x, y) (x < y ? x : y)
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        double total[100][100];
        memset(total, 0, sizeof(total));
        total[0][0] = poured;
        for (int i = 0; i < query_row; i++) {
            for (int j = 0; j <= i; j++) {
                double remain = (total[i][j] - 1) / 2;
                if (remain > 0) {
                    total[i + 1][j] += remain;
                    total[i + 1][j + 1] += remain;
                }
            }
        }
        return min(total[query_row][query_glass], 1);
    }
};
