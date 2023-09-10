/**
 * @param {number} n
 * @return {number}
 */
var countOrders = function(n) {
    const mod = 10 ** 9 + 7;
    let order = 1;
    for (let i = 0; i < n; i++) {
        order = (order * (i + 1)) % mod;
        order = (order * (i * 2 + 1)) % mod;
    }
    return order;
};
