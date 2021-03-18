class Solution {
public:
    int totalNQueens(int n) {

        limit = (1 << n) - 1;
        solve(0, 0, 0);
        return result;
    }

private:
    int result = 0;
    int limit;

    void solve(int row, int ld, int rd) {

        if (row == limit) {
            result ++;
            return;
        }

        int index = limit & (~(row | ld | rd));
        int pos;
        while (index != 0) {
            pos = index & (-index);
            index -= pos;
            solve(row + pos, (ld + pos) << 1, (rd + pos) >> 1);
        }
    }
};
