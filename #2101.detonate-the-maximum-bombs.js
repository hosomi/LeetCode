/**
 * @param {number[][]} bombs
 * @return {number}
 */
var maximumDetonation = function(bombs) {
    
    let length = bombs.length;
    let arr = {};
    let max = 0;
    for (let i = 0; i < length; i++) {
        if (!arr[i]) {
            arr[i] = [];
        }

        for (let j = 0; j < length; j++) {
            let [x,y,r] = bombs[i];
            let h = bombs[j][0], k = bombs[j][1];
            if (Math.sqrt(Math.pow(x-h, 2) + Math.pow(y-k, 2)) <= r) {
                arr[i].push(j);
            }
        }
    }
    const dfs = (index, visited = new Set()) => {
        let subMax = 0;
        arr[index].forEach((ar) => {
            if (!visited.has(ar)) {
                visited.add(ar)
                subMax++
                subMax += dfs(ar, visited)
            }
        }) 
        return subMax;      
    }

    for(let i = 0; i < length; i++) {
        max = Math.max(dfs(i), max);
        if (max == length) {
            return max;
        }
    }
    return max;
};
