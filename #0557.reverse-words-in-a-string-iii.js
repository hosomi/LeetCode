/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.split(' ')
        .map(value => value.split('')
        .reverse()
        .join(''))
        .join(' ')
    ;
};
