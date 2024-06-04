/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let result = 0;
    const set = new Set();
    for (let i = 0; i<s.length; i++) {
        if (set.has(s[i])) {
            result += 2;
            set.delete(s[i]);
        } else { 
            set.add(s[i]);
        }
    };
    return result + (set.size > 0 ? 1 : 0);
};
