/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    if (n === 1) {
        return "1";
    }

    let prev = countAndSay(n - 1);
    let count = 1;
    let res = "";
    let i = 0;
    for (; i < prev.length -1; i++) {
        if (prev[i] === prev[i + 1]) {
            count++;
        } else {
            res += count + prev[i];
            count = 1;
        }
    }
    res += count + prev[i];
    return res;
};
