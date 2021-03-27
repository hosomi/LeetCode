class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {

        int index = 1;
        int size = R * C;
        int row = 1;
        int count = 0;
        vector<vector<int>> result{{r0, c0}};
        while (index < size) {
            count = 0;
            while (count < row) {
                count++;
                c0++;
                if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) {
                    result.push_back(vector<int>{r0, c0});
                    index++;
                }
            }

            count = 0;
            while (count < row) {
                count++;
                r0++;
                if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) {
                    result.push_back(vector<int>{r0, c0});
                    index++;
                }
            }

            row++;
            count = 0;
            while (count < row) {
                count++;
                c0--;
                if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) {
                    result.push_back(vector<int>{r0, c0});
                    index++;
                }
            }

            count = 0;
            while (count < row) {
                count++;
                r0--;
                if (r0 >= 0 && r0 < R&& c0 >= 0 && c0 < C) {
                    result.push_back(vector<int>{r0, c0});
                    index++;
                }
            }

            row++;
        }
        return result;
    }
};
