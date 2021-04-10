class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int index = 0;
        int boardSize = rowSize * colSize - 1;
        int middle;
        while (index <= boardSize){
            middle = (index + boardSize) / 2;
            if (matrix[middle / colSize][middle % colSize] == target) {
                return true;
            } else if(matrix[middle / colSize][middle % colSize] < target) {
                index = middle + 1;
            } else{
                boardSize = middle - 1;
            }
        }
        return false;
    }
};
