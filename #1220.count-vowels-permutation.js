/**
 * @param {number} n
 * @return {number}
 */
var countVowelPermutation = function(n) {
    const sum = (x,y) => (x + y) % (10 ** 9 + 7);
    const pre = [[1, 2, 4], [0, 2], [1, 3], [2], [2, 3]]; 
    const dp = [[0, 1], [0, 1], [0,1 ], [0,1 ], [0, 1]];                                
    for (let i = 2; i <= n; i++) {
        let k = i % 2;
        for (let j = 0; j < 5; j++) {
            dp[j][k] = pre[j].reduce((left, right) => 
                sum(left, dp[right][1-k]), 0);
        }
    }
    
    return dp.reduce((left, right) =>
        sum(left, right[n % 2]), 0);
};
