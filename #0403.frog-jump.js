/**
 * @param {number[]} stones
 * @return {boolean}
 */
var canCross = function(stones) {
    let q = [[0,0]];
    let length = stones.length - 1;
    let isBool = {};
    while (q.length) {
        let [i,k] = q.shift();
        if(i == length) {
            return true;
        }

        if (k == 0 && i > 0 || isBool[`${i}:${k}`]) {
            continue;
        }

        isBool[`${i}:${k}`] = true;
        let j = i + 1;
        while (stones[j] <= stones[i] + k + 1) {
            if(stones[i] + k == stones[j]) {
                q.push([j,k]);
            }

            if (stones[i] + k + 1 == stones[j]) {
                q.push([j,k + 1]);
            }

            if (stones[i] + k - 1 == stones[j]) {
                q.push([j,k - 1]);
            }

            j++;
        }  
    }   
    return false;
};
