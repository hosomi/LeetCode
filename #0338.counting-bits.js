/**
 * @param {number} n
 * @return {number[]}
 */
var countBits = function(n) {
    let pop = new Array(n + 1).fill(0);
    for (let i = 1; i<= n; i++) {
        pop[i] = pop[i & (i - 1)] + 1;
    }
    return pop;
};
