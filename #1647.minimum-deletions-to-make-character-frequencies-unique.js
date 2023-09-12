/**
 * @param {string} s
 * @return {number}
 */
var minDeletions = function(s) {
    let m = new Map();
    s.split("").forEach((el) => m.set(el, m.get(el) + 1 || 1));

    let arr = Array.from(m.values());
    arr.sort((left, right) => right - left);

    let length = arr.length;
    let result = 0;
    for (let i = 0; i < length - 1; i++) {
        while (arr[i + 1] && arr[i + 1] >= arr[i]) {
            arr[i + 1]--;
            result++;
        }
    }
    return result;
};
