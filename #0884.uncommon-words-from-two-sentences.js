/**
 * @param {string} s1
 * @param {string} s2
 * @return {string[]}
 */
var uncommonFromSentences = function(s1, s2) {
    let s = `${s1} ${s2}`.split(" ");
    let m = s.reduce((left, right) => {
        left.has(right) ?
            left.set(right, left.get(right) + 1)
            : left.set(right, 1);
        return left;
    }, new Map());

    let results = [];
    for (let key of m) {
        if (key[1] === 1) {
            results.push(key[0]);
        }
    }
    return results;
};
