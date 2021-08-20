class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {

        int size = positions.size();
        vector<int> axis(size);
        for (int i = 0; i < size; i++) {
            int left = positions[i][0];
            int height = positions[i][1];
            int right = left + height -1;
            axis[i] += height;

            for (int j = i + 1; j < size; j++) {
                int left2 = positions[j][0];
                int height2 = positions[j][1];
                int right2 = left2 + height2 -1;
                if( left2 <= right && right2 >= left) {
                    axis[j] = std::max(axis[j], axis[i]);
                }
            }
        }

        vector<int> result;
        int i = -1;
        for (int a : axis) {
            i = std::max(i, a);
            result.push_back(i);
        }
        return result;
    }
};
