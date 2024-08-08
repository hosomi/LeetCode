/**
 * @param {number} rows
 * @param {number} cols
 * @param {number} rStart
 * @param {number} cStart
 * @return {number[][]}
 */
var spiralMatrixIII = function(rows, cols, rStart, cStart) {
    let results = [];
    let r = rStart;
    let c = cStart;
    let right = true;
    let down = false;
    let left = false;
    let up = false;
    let steps = 1;
    let maxSteps = 2;
    while (results.length !== (rows * cols)) {
        if (r >= 0 && c >= 0 && r < rows && c < cols) {
            results.push([r, c]);
        }

        if (right) {
            if (steps + 1 > maxSteps) {
                steps = 2;
                r++;
                right = false;
                down = true;
            } else {
                c++;
                steps++;
            }
        } else if (down) {
            if (steps + 1 > maxSteps) {
                steps = 2;
                c--;
                down = false;
                left = true;
                maxSteps++;
            } else {
                r++;
                steps++;
            }
        } else if (left) {
            if (steps + 1 > maxSteps) {
                steps = 2;
                r--;
                left = false;
                up = true;
            } else {
                c--;
                steps++;
            }
        } else if (up) {
            if (steps + 1 > maxSteps) {
                steps = 2;
                c++;
                up = false;
                right = true;
                maxSteps++;
            } else {
                r--;
                steps++;
            }
        }
    }
    return results;
};
