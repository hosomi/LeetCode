/**
 * @param {string} dominoes
 * @return {string}
 */
var pushDominoes = function(dominoes) {
    const N = dominoes.length;
    const dp = new Array(N).fill().map(_ => {
        return { left: Infinity, right: Infinity } 
    });
    for (let last = '', force = 0, i = 0; i < N; i++) {
        if (dominoes[i] != '.') {
            force = 0;
            last = dominoes[i];
        }
        
        if (last == 'R') {
            dp[i].right = force++;
        }
    }
    
    for (let last = '', force = 0, i = N-1; i >= 0; i--) {
        if (dominoes[i] != '.') {
            force = 0;
            last = dominoes[i];
        }
        
        if (last == 'L') {
            dp[i].left = force++;
        }
    }
    
    return dp.map(({ left, right }) => left === right ? '.' : left < right ? 'L' : 'R').join('');
};
