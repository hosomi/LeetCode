/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    let result = s[0] || "";
    const search = (left, right) => {
        while (left < s.length
            && left - right.length - 1 > -1
            && s[left] === s[left - right.length - 1]) {
            right = s[left] + right + s[left];
            left++;
        }

        result = result.length < right.length ? right : result;
    }

    for (let i = 1; i < s.length; i++) {
        if (s[i - 1] === s[i]) {
            search(i + 1, s[i - 1] + s[i]);
        }
        search(i + 1, s[i]);
    }
    return result;
};
