/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    let low = 0;
    let high = matrix.length - 1;
    let mid = 0;
    while (low <= high) {
        mid = Math.ceil((high + low) / 2);

        if (matrix[mid].includes(target)) {
            return true;
        }

        let lastMid = matrix[mid][matrix[mid].length - 1]
        if (lastMid < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return matrix[mid].includes(target);
};
