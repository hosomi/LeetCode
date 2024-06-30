/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var maxNumEdgesToRemove = function(n, edges) {
    let res = 0;
    let alice = Array(n+1).fill(-1);
    let bob = [...alice];
    for (let [type, x, y] of edges) {
        if (type === 3) {
            let m1 = union(x,y, alice);
            let m2 = union(x,y, bob)
            if (m1 && m2) {
                res++;
            }
        }
    }

    for (let [type, x, y] of edges) {
        if (type !== 3) {
            if (type == 1) {
                if (union(x,y,alice)) {
                    res++;
                }
            } else {
                if (union(x,y,bob)) {
                    res++;
                }
            }
        }
    }

    let minus1 = 0;
    for (let idx = 1; idx < n + 1; idx++) {
        if (alice[idx] === -1) {
            minus1++;
        }
    }

    if (minus1 > 1) {
        return -1;
    }

    for (let idx = 1; idx < n+1; idx++) {
        if (bob[idx] === -1) {
            minus1++;
        }
    }

    if (minus1 > 2) {
        return -1;
    }
    return res;

        function findPar(x, par) {
        if(par[x] == -1) {
            return x;
        }

        par[x] = findPar(par[x], par);
        return par[x];
    }

    function union(x,y,par) {
        let p_x = findPar(x,par);
        let p_y = findPar(y,par);
        if (p_x !== p_y) {
            par[p_x] = p_y;
            return false;
        }
        return true;
    }
};
