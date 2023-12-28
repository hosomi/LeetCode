/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var getLengthOfOptimalCompression = function(s, k) {
    const str = new Array(s.length)
        .fill(0)
        .map(el => new Array(k + 1).fill(null));

    return dfs(0, k);

    function dfs(left, k) {
        if (k < 0) {
            return Infinity;
        }
      
        if (left >= s.length || s.length - left <= k) {
            return 0;
        }
      
        if (str[left][k] !== null) {
            return str[left][k];
        }

        let result = Infinity;
        const count = new Array(26).fill(0);
        let comp = 0;
        for (let i = left; i < s.length; i++) {
          comp = Math.max(comp, ++count[s[i].charCodeAt() - 97])
          result = Math.min(
                result,
                dfs(i + 1, k - (i - left + 1 - comp))
                    + after(comp));
        }
        return str[left][k] = result;
    }  
    
    function after(num) {
        if (num === 1) {
            return 1;
        } 
        
        if (num < 10) {
            return 2;
        }
        
        return num < 100 ? 3 : 4;
    }
};
