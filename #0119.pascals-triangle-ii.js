/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var getRow = function(rowIndex) {
    let results = [1];
    for (let i = 1; i <= rowIndex; i++) {
        results.push(results[results.length - 1]
            * (rowIndex - i + 1) / i);
    }
    return results;
};
