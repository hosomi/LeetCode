/**
 * @param {string} expression
 * @return {number[]}
 */
var diffWaysToCompute = function(expression) {
    function backtrack(nums, ops) {
        if (nums.length == 1) {
            return nums;
        }

        let result = [];
        for (let i = 0; i < ops.length; i++) {
            const left = backtrack(nums.slice(0, i + 1), ops.slice(0, i));
            const right = backtrack(nums.slice(i + 1), ops.slice(i + 1));
            for (let j of left) {
                for (let k of right) {
                    if (ops[i] == '*') {
                        result.push(j * k);
                    } else if (ops[i] == '+') {
                        result.push(j + k);
                    } else {
                        result.push(j - k);
                    }
                }
            }
        }
        return result;
    }

    const nums = expression.match(/\d+/g).map(Number);
    const ops = expression.match(/[^\d]/g);
    return backtrack(nums, ops);
};
