/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var getLucky = function(s, k) {
    let alpha = "abcdefghijklmnopqrstuvwxyz";
    let arr = [];
    for (let i = 0; i < s.length; i++) {     
        if (alpha.includes(s[i])) {
            arr.push(alpha.indexOf(s[i]) + 1);
        }
    }

    arr = arr.join('');
    for (let j = 1; j <= k; j++) {
        arr = arr.toString()
            .split('')
            .map(Number)
            .reduce((left, right) => left + right); 
    }
    return arr;
};
