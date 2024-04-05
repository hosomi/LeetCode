/**
 * @param {string} s
 * @return {string}
 */
var makeGood = function(s) {
    const lowerCase = (left, right) => 
        left !== right
        && left.toLowerCase() === right.toLowerCase();

    let stack = [''];
    for (const x of s) {
        lowerCase(x, stack.at(-1)) ? stack.pop() : stack.push(x);
    }
    return stack.join('');
};
