/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = function(arr) {
    let arr2 = {};
    for (let i = 0; i < arr.length; i++) {
        let item = arr[i];
        arr2[item] = (arr2[item] || 0) + 1;
    }

    const results = Array.from(new Set(Object.values(arr2)));
    return results.length === Array.from(new Set(arr)).length;
};
