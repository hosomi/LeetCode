/**
 * @param {string} s
 * @return {string}
 */
var shortestPalindrome = function(s) {
    const reserse = s.split('').reverse().join('');
    const len = s.length;
    let substr = '';
    for (let i = len - 1; i >= 0; i--) {
        const short = i + 1;
        if (s.slice(0, short) === reserse.slice(len - short, len)) {
            substr = reserse.slice(0, len - short);
            break;
        }
    }
    return substr + s;
};
