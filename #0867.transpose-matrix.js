/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var transpose = function(matrix) {
    const result = Array.from(
        { length: matrix[0].length },
        () => new Array(matrix.length).fill(0)
    );

    for (let i = 0 ; i < matrix.length ; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
};
