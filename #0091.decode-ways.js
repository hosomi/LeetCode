/**
 * @param {string} s
 * @return {number}
 */
var numDecodings = function(s) {
    
    const length = s.length;
    const arr = Array(length + 1).fill(0);
    arr[0] = 1;
    for (let i = 1; i <= length; i++) {
        const char1 = +s.slice(i - 1, i);
        const char2 = +s.slice(i - 2, i);
        
        if (char1 > 0) {
            arr[i] = arr[i - 1];
        }
        if (char2 >= 10 && char2 <= 26) {
            arr[i] += arr[i - 2];
        }
    }    
    return arr[length];
};
