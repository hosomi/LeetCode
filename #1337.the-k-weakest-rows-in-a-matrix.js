/**
 * @param {number[][]} mat
 * @param {number} k
 * @return {number[]}
 */
var kWeakestRows = function(mat, k) {
    const reduce = mat.map((row, i) => [i,
        row.reduce((left, right)=> left + right)]);
    reduce.sort((left, right) => left[1] - right[1]);
    return reduce.slice(0, k).map(m => m[0]);
};
