class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {

        int size = slices.size();
        return std::max(maxSizeSlices(slices, 0, size - 2),
            maxSizeSlices(slices, 1, size - 1));
    }

private:
    int maxSizeSlices(vector<int>& slices, int left, int right){

        int size = slices.size();
        int index = size / 3;
        vector<vector<int>> result(size, vector<int>(index, 0));
        for (int i = left; i <= right; i++) {
            for (int j = 0; j < index; j++) {
                result[i][j] = std::max(i - 1 >= 0 ? result[i - 1][j] : 0, 
                    (((i - 2 >= 0) && (j - 1 >= 0)) ? result[i - 2][j - 1] : 0) + slices[i]);
            }
        }
        return result[right][index - 1];
    }
};
