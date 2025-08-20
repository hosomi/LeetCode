function countSquares(matrix: number[][]): number {
    let m = matrix.length;
    let n = matrix[0].length;
    let total = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] === 1 && i > 0 && j > 0) {
                matrix[i][j] = Math.min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + 1;
            }
            total += matrix[i][j];
        }
    }
    return total;
};
