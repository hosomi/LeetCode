/**
 * @param {string[]} logs
 * @return {number}
 */
var minOperations = function(logs) {
    let stack = [];
    for (let i = 0; i < logs.length; i++) {
        if (logs[i] == '../'){
            stack.pop();
        }

        if (logs[i] != './' && logs[i] != '../') {
            stack.push(logs[i]);
        }
    }
    return stack.length;
};
