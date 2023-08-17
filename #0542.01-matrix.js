/**
 * @param {number[][]} mat
 * @return {number[][]}
 */
var updateMatrix = function(mat) {
		const row = mat.length;
		const col = mat[0].length;
		for (let i = 0; i < row; i++) {
				for (let j = 0; j < col; j++) {
						if (mat[i][j] === 0) {
							continue;
						}

						mat[i][j] = Infinity;
						if (i - 1 >= 0) {
								mat[i][j] = Math.min(mat[i][j], 1 + mat[i - 1][j]);
						}
						if (j - 1 >= 0) {
								mat[i][j] = Math.min(mat[i][j], 1 + mat[i][j - 1]);
						}
				}
		}

		for (let i = row - 1; i >= 0; i--) {
				for (let j = col - 1; j >= 0; j--) {
						if (mat[i][j] === 0) {
								continue;
						}

						if (i + 1 < row) {
								mat[i][j] = Math.min(mat[i][j], 1 + mat[i + 1][j]);
						}
						if (j + 1 < col) {
								mat[i][j] = Math.min(mat[i][j], 1 + mat[i][j + 1]);
						}
				}
		}

		return mat;
};
