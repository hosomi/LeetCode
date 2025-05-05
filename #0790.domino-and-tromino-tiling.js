/**
 * @param {number} n
 * @return {number}
 */
var numTilings = function(n) {
    let r = [ 1, 2, 5 ];
    let x = 0;
    while (n--) {
        x = r.shift();
        r.push(( 2 * r[1] + x) % (1e9 + 7));
    }
    return x;
};
