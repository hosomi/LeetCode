/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
    let counter = 0;
    for(let c of t) {
        if (c === s[counter]) {
            counter++;
        }
    }
    return counter === s.length;
};
