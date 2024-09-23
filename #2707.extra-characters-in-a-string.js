/**
 * @param {string} s
 * @param {string[]} dictionary
 * @return {number}
 */
var minExtraChar = function(s, dictionary) {
    let arr = new Array(s.length + 1).fill(-1);
    arr[s.length] = 0;
    for (let i = s.length - 1; i >= 0; i--) {
        arr[i] = arr[i + 1] + 1;
        for (let w of dictionary) {
            let subStr = s.substring(i, i + w.length);
            if (subStr === w){
                let prev = arr[i + w.length];
                if (prev < arr[i]) {
                    arr[i] = prev;
                }
            }
        }
    }
    return arr[0];
};
