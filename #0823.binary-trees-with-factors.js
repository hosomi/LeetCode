/**
 * @param {number[]} arr
 * @return {number}
 */
var numFactoredBinaryTrees = function(arr) {
    arr.sort((left, right) => left - right);
    let m = new Map();
    let sol = Array(arr.length).fill(1);
    let mod = 1e9 + 7;
    arr.forEach((val) => {
        m.set(val, []);
    });

    for (let i = 0; i < arr.length; i++) {
        for (let j = i; j < arr.length; j++) {
            let prod = arr[i] * arr[j];
            if (prod > arr[arr.length - 1]) {
                break;
            }

            if (m.has(prod)) {
                m.get(prod).push([i, j]);
            }
        }
    }

    for (let i = 0; i < arr.length; i++) {
        if (m.has(arr[i])) {
            let prodArr = m.get(arr[i]);
            for (j = 0; j < prodArr.length; j++) {
                let i1 = prodArr[j][0], i2 = prodArr[j][1];
                sol[i] += sol[i1] * sol[i2] * (i1 == i2 ? 1 : 2) % mod;
            }
        }
    }

    return sol.reduce((sum, val) => (sum + val) % mod, 0);
};
