class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {

        int size = coordinates.size();
        if (size == 2) {
            return true;
        }

        vector<int> v1 = { coordinates[1][0] - coordinates[0][0],
                          coordinates[1][1] - coordinates[0][1] };
        vector<int> v2;
        for (int i = 2; i < size; i++) {
            v2 = {coordinates[i][0] - coordinates[0][0], coordinates[i][1] - coordinates[0][1]};
            if (v1[0]*v2[1] - v1[1]*v2[0] != 0) {
                return false;
            }
        }
        return true;
    }
};
