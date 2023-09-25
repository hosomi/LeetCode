/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    for (let c of s) {
        t = t.replace(c, '');
    }
    return t;
};
