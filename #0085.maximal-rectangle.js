/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalRectangle = function(matrix) {
    if (!matrix.length) {
        return 0;
    }

    const row = matrix.length;
    const col = matrix[0].length;
    const arr = Array(col).fill(0);
    let result = 0;
    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            arr[j] = +matrix[i][j] ? arr[j] + 1 : 0;
        }
        
        for(let j = 0; j < col; j++) {
            let left = j - 1;
            while (left >= 0 && arr[left] >= arr[j]) {
                left--;
            }

            let right = j + 1;
            while (right < col && arr[right] >= arr[j]) {
                right++;
            }
            result = Math.max(arr[j] * (right - left - 1), result);
        }
    }
    return result;
};
