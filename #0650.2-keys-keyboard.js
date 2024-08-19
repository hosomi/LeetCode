/**
 * @param {number} n
 * @return {number}
 */
var minSteps = function(n) {
    if (n === 1) {
        return 0;
    }
    
    let steps = 0;
    for (let char = 2; char <= n; char++) {
        while (n % char === 0) {
            n /= char;
            steps += char;
        }
    }
    return steps;
};
