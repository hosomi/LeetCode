/**
 * @param {number[]} arr
 * @param {number[][]} queries
 * @return {number[]}
 */
var xorQueries = function(arr, queries) {
    const xors = arr.reduce((result, num, index) => {
        result.push(result[index] ^ num);
        return result;
    }, [0]);

    return queries.map(([left, right]) => {
        return xors[right + 1] ^ xors[left];
    });
};
