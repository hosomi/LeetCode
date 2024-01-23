/**
 * @param {string[]} arr
 * @return {number}
 */
var maxLength = function(arr) {
    const isValid = (str) => str.length === new Set(str).size;
    const valid = arr.filter(s => isValid(s));
    let combinations = valid;
    for (let i = 0; i < valid.length; i++) {
        combinations = combinations.flatMap(c => {
            if (!isValid(c + valid[i])
                || c + valid[i] > valid[i] + c) {
                return c;
            } else {
                return [c, c + valid[i]];
            }
        });
    }
    return Math.max(...combinations.map((c => c.length)), 0);
};
