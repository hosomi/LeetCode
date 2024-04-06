/**
 * @param {string} s
 * @return {string}
 */
var minRemoveToMakeValid = function(s) {
    let arr = s.split("");
    let stack = [];
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === '(') {
            stack.push(i);
        } else if (arr[i] === ')' && stack.length) {
            stack.pop();
        } else if (arr[i] === ')') {
            arr[i] = "";
        }
    }

    while (stack.length) {
        const curr = stack.pop();
        arr[curr] = '';
    }
    return arr.join("");
};
