class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int size = matrix.size();
        int col = matrix[0].size();
        if (!size && !col) {
            return false;
        }

        int i = 0;
        int j = col - 1; 
        while (i < size && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }

            if (matrix[i][j] < target) {
                i++;
            } else if (matrix[i][j] > target) {
                j--;
            }
        }
        return false;
    }
};
